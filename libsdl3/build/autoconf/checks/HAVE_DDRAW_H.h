// HAVE_DDRAW_H

#undef HAVE_DDRAW_H

/* Check for the ddraw.h header. DirectDraw, part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_DDRAW_H 1
#endif
