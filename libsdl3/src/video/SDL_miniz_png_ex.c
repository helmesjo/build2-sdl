/* SDL_miniz_write_image_to_png_file_in_memory_ex: a packaging-local overlay
 * providing the same PLTE/tRNS-chunk-capable PNG encoder that upstream SDL
 * carries as a modification to its own vendored miniz.h (there named
 * tdefl_write_image_to_png_file_in_memory_ex, with an extra bpl/plte/trns
 * argument set not present in stock miniz's own version of that function).
 * This package depends on the real libminiz instead of vendoring miniz, so
 * that extension has to live here rather than in a patched miniz.h: this
 * file reimplements the same algorithm entirely in terms of miniz's own
 * public, exported API (tdefl_init/tdefl_compress_buffer/mz_crc32), not
 * miniz's internal tdefl_output_buffer/tdefl_output_buffer_putter (private,
 * static, not exported by the compiled library) -- this file defines its
 * own equivalent pair instead, which is exactly what tdefl_init's callback
 * parameter is designed to accept from any caller.
 *
 * Used from SDL_stb.c (see the accompanying .patch): SDL_SavePNG_IO calls
 * this instead of the name it originally called, since the real libminiz
 * already exports a same-named function with a different (7-argument, no
 * palette/transparency support) signature -- reusing that name here would
 * be a duplicate-symbol link error.
 *
 * Allocates its return buffer with SDL_malloc, so the caller must release
 * it with SDL_free, not mz_free (stock libminiz's own compiled mz_free
 * releases through plain libc free, not SDL's allocator).
 *
 * Ported from libsdl-org/SDL's tdefl_write_image_to_png_file_in_memory_ex,
 * added in commit 1fa6475 and since fixed twice, in ac0915b (compress
 * w*num_chans bytes per row, not bpl) and 38df1c3 (size out_buf from
 * w*num_chans*h, not bpl*h) -- both already reflected here. No patch ties
 * this file back to upstream/src/video/miniz.h, so a future SDL version
 * bump needs a manual diff of that function against this one.
 */
#include "SDL_internal.h"

#include "SDL_miniz_png_ex.h"
#include <miniz_tdef.h>

typedef struct SDL_miniz_output_buffer {
    mz_uint8 *m_pBuf;
    size_t m_capacity;
    size_t m_size;
    mz_bool m_expandable;
} SDL_miniz_output_buffer;

static mz_bool SDL_miniz_output_buffer_putter(const void *pBuf, int len, void *pUser)
{
    SDL_miniz_output_buffer *p = (SDL_miniz_output_buffer *)pUser;
    size_t new_size = p->m_size + len;
    if (new_size > p->m_capacity) {
        size_t new_capacity = p->m_capacity;
        if (!p->m_expandable) {
            return MZ_FALSE;
        }
        do {
            new_capacity = MZ_MAX(128U, new_capacity << 1U);
        } while (new_size > new_capacity);
        void *pNew_buf = SDL_realloc(p->m_pBuf, new_capacity);
        if (!pNew_buf) {
            return MZ_FALSE;
        }
        p->m_pBuf = (mz_uint8 *)pNew_buf;
        p->m_capacity = new_capacity;
    }
    SDL_memcpy((mz_uint8 *)p->m_pBuf + p->m_size, pBuf, len);
    p->m_size = new_size;
    return MZ_TRUE;
}

void *SDL_miniz_write_image_to_png_file_in_memory_ex(const void *pImage, int w, int h, int num_chans, int bpl, size_t *pLen_out, mz_uint level, mz_bool flip, mz_uint8 *plte, int plte_size, mz_uint8 *trns, int trns_size)
{
    static const mz_uint s_tdefl_png_num_probes[11] = { 0, 1, 6, 32, 16, 32, 128, 256, 512, 768, 1500 };
    tdefl_compressor *pComp = (tdefl_compressor *)SDL_malloc(sizeof(tdefl_compressor));
    SDL_miniz_output_buffer out_buf;
    int i, y, z = 0;
    mz_uint32 c;
    size_t data_start, data_size;

    *pLen_out = 0;
    if (!pComp) {
        return NULL;
    }
    SDL_zero(out_buf);
    out_buf.m_expandable = MZ_TRUE;
    out_buf.m_capacity = 57 + MZ_MAX(64, (1 + w * num_chans) * h);
    if (plte_size > 0) {
        out_buf.m_capacity += 12 + plte_size;
    }
    if (trns_size > 0) {
        out_buf.m_capacity += 12 + trns_size;
    }
    out_buf.m_pBuf = (mz_uint8 *)SDL_malloc(out_buf.m_capacity);
    if (!out_buf.m_pBuf) {
        SDL_free(pComp);
        return NULL;
    }

    /* write header */
    {
        static const mz_uint8 chans[] = { 0x00, 0x00, 0x04, 0x02, 0x06 };
        mz_uint8 pnghdr[33] = { 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a,
                                 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

        pnghdr[18] = (mz_uint8)(w >> 8);
        pnghdr[19] = (mz_uint8)(w >> 0);
        pnghdr[22] = (mz_uint8)(h >> 8);
        pnghdr[23] = (mz_uint8)(h >> 0);

        if (num_chans == 1 && plte_size > 0) {
            pnghdr[25] = 3;
        } else {
            pnghdr[25] = (chans[num_chans]);
        }

        c = (mz_uint32)mz_crc32(MZ_CRC32_INIT, pnghdr + 12, 17);
        for (i = 0; i < 4; ++i, c <<= 8) {
            ((mz_uint8 *)(pnghdr + 29))[i] = (mz_uint8)(c >> 24);
        }
        if (!SDL_miniz_output_buffer_putter(pnghdr, sizeof(pnghdr), &out_buf)) {
            *pLen_out = 0;
            SDL_free(pComp);
            SDL_free(out_buf.m_pBuf);
            return NULL;
        }
    }

    /* write PLTE chunk */
    if (plte_size > 0) {
        mz_uint8 hdr[8] = { 0x00, 0x00, 0x00, 0x00, 0x50, 0x4c, 0x54, 0x45 };
        hdr[0] = (mz_uint8)(plte_size >> 24);
        hdr[1] = (mz_uint8)(plte_size >> 16);
        hdr[2] = (mz_uint8)(plte_size >> 8);
        hdr[3] = (mz_uint8)(plte_size >> 0);
        if (!SDL_miniz_output_buffer_putter(hdr, sizeof(hdr), &out_buf)) {
            *pLen_out = 0;
            SDL_free(pComp);
            SDL_free(out_buf.m_pBuf);
            return NULL;
        }
        data_start = out_buf.m_size;
        if (!SDL_miniz_output_buffer_putter(plte, plte_size, &out_buf)) {
            *pLen_out = 0;
            SDL_free(pComp);
            SDL_free(out_buf.m_pBuf);
            return NULL;
        }
        if (!SDL_miniz_output_buffer_putter("\0\0\0\0", 4, &out_buf)) {
            *pLen_out = 0;
            SDL_free(pComp);
            SDL_free(out_buf.m_pBuf);
            return NULL;
        }
        c = (mz_uint32)mz_crc32(MZ_CRC32_INIT, out_buf.m_pBuf + data_start - 4, plte_size + 4);
        for (i = 0; i < 4; ++i, c <<= 8) {
            (out_buf.m_pBuf + out_buf.m_size - 4)[i] = (mz_uint8)(c >> 24);
        }
    }

    /* write tRNS chunk */
    if (trns_size > 0) {
        mz_uint8 hdr[8] = { 0x00, 0x00, 0x00, 0x00, 0x74, 0x52, 0x4E, 0x53 };
        hdr[0] = (mz_uint8)(trns_size >> 24);
        hdr[1] = (mz_uint8)(trns_size >> 16);
        hdr[2] = (mz_uint8)(trns_size >> 8);
        hdr[3] = (mz_uint8)(trns_size >> 0);
        if (!SDL_miniz_output_buffer_putter(hdr, sizeof(hdr), &out_buf)) {
            *pLen_out = 0;
            SDL_free(pComp);
            SDL_free(out_buf.m_pBuf);
            return NULL;
        }
        data_start = out_buf.m_size;
        if (!SDL_miniz_output_buffer_putter(trns, trns_size, &out_buf)) {
            *pLen_out = 0;
            SDL_free(pComp);
            SDL_free(out_buf.m_pBuf);
            return NULL;
        }
        if (!SDL_miniz_output_buffer_putter("\0\0\0\0", 4, &out_buf)) {
            *pLen_out = 0;
            SDL_free(pComp);
            SDL_free(out_buf.m_pBuf);
            return NULL;
        }
        c = (mz_uint32)mz_crc32(MZ_CRC32_INIT, out_buf.m_pBuf + data_start - 4, trns_size + 4);
        for (i = 0; i < 4; ++i, c <<= 8) {
            (out_buf.m_pBuf + out_buf.m_size - 4)[i] = (mz_uint8)(c >> 24);
        }
    }

    /* write IDAT chunk */
    if (!SDL_miniz_output_buffer_putter("\0\0\0\0\x49\x44\x41\x54", 8, &out_buf)) {
        *pLen_out = 0;
        SDL_free(pComp);
        SDL_free(out_buf.m_pBuf);
        return NULL;
    }
    data_start = out_buf.m_size;

    /* compress image data */
    tdefl_init(pComp, SDL_miniz_output_buffer_putter, &out_buf, s_tdefl_png_num_probes[MZ_MIN(10, level)] | TDEFL_WRITE_ZLIB_HEADER);
    for (y = 0; y < h; ++y) {
        tdefl_compress_buffer(pComp, &z, 1, TDEFL_NO_FLUSH);
        tdefl_compress_buffer(pComp, (mz_uint8 *)pImage + (flip ? (h - 1 - y) : y) * bpl, w * num_chans, TDEFL_NO_FLUSH);
    }
    if (tdefl_compress_buffer(pComp, NULL, 0, TDEFL_FINISH) != TDEFL_STATUS_DONE) {
        SDL_free(pComp);
        SDL_free(out_buf.m_pBuf);
        return NULL;
    }

    /* write IDAT size */
    data_size = out_buf.m_size - data_start;
    (out_buf.m_pBuf + data_start - 8)[0] = (mz_uint8)(data_size >> 24);
    (out_buf.m_pBuf + data_start - 8)[1] = (mz_uint8)(data_size >> 16);
    (out_buf.m_pBuf + data_start - 8)[2] = (mz_uint8)(data_size >> 8);
    (out_buf.m_pBuf + data_start - 8)[3] = (mz_uint8)(data_size >> 0);

    /* write footer (IDAT CRC-32, followed by IEND chunk) */
    if (!SDL_miniz_output_buffer_putter("\0\0\0\0\0\0\0\0\x49\x45\x4e\x44\xae\x42\x60\x82", 16, &out_buf)) {
        *pLen_out = 0;
        SDL_free(pComp);
        SDL_free(out_buf.m_pBuf);
        return NULL;
    }
    c = (mz_uint32)mz_crc32(MZ_CRC32_INIT, out_buf.m_pBuf + data_start - 4, data_size + 4);
    for (i = 0; i < 4; ++i, c <<= 8) {
        (out_buf.m_pBuf + out_buf.m_size - 16)[i] = (mz_uint8)(c >> 24);
    }

    *pLen_out = out_buf.m_size;
    SDL_free(pComp);
    return out_buf.m_pBuf;
}
