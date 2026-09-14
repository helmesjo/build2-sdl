// HAVE_DXGI_H

#undef HAVE_DXGI_H

/* Check for the dxgi.h header. DXGI (DirectX Graphics Infrastructure),
 * part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_DXGI_H 1
#endif
