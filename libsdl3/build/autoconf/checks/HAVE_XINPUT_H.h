// HAVE_XINPUT_H

#undef HAVE_XINPUT_H

/* Check for the xinput.h header. XInput, the Xbox-controller API, part
 * of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_XINPUT_H 1
#endif
