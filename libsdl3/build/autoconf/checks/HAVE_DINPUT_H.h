// HAVE_DINPUT_H

#undef HAVE_DINPUT_H

/* Check for the dinput.h header. DirectInput, part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_DINPUT_H 1
#endif
