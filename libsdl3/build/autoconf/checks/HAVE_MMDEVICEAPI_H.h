// HAVE_MMDEVICEAPI_H

#undef HAVE_MMDEVICEAPI_H

/* Check for the mmdeviceapi.h header. Windows Core Audio device
 * enumeration, used by WASAPI, part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_MMDEVICEAPI_H 1
#endif
