// HAVE_SHELLSCALINGAPI_H

#undef HAVE_SHELLSCALINGAPI_H

/* Check for the shellscalingapi.h header. Per-monitor DPI-awareness API,
 * part of the Windows 8.1+ SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_SHELLSCALINGAPI_H 1
#endif
