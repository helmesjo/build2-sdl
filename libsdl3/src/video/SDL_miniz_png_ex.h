#ifndef SDL_miniz_png_ex_h_
#define SDL_miniz_png_ex_h_

#include <miniz.h>

/* PLTE/tRNS-chunk-capable PNG encoder built on stock libminiz's public API.
 * See SDL_miniz_png_ex.c.
 */
void *SDL_miniz_write_image_to_png_file_in_memory_ex(const void *pImage, int w, int h, int num_chans, int bpl, size_t *pLen_out, mz_uint level, mz_bool flip, mz_uint8 *plte, int plte_size, mz_uint8 *trns, int trns_size);

#endif
