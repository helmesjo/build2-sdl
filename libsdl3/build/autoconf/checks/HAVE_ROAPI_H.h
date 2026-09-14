// HAVE_ROAPI_H

#undef HAVE_ROAPI_H

/* Check for the roapi.h header. WinRT (Windows Runtime) activation API,
 * part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_ROAPI_H 1
#endif
