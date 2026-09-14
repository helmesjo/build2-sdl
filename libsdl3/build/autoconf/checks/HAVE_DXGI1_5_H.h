// HAVE_DXGI1_5_H

#undef HAVE_DXGI1_5_H

/* Check for the dxgi1_5.h header. DXGI 1.5 (adds HDR and tearing
 * support), part of a modern Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_DXGI1_5_H 1
#endif
