// HAVE_DXGI1_6_H

#undef HAVE_DXGI1_6_H

/* Check for the dxgi1_6.h header. DXGI 1.6 (adds HDR10 metadata and
 * variable refresh rate queries), part of a modern Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_DXGI1_6_H 1
#endif
