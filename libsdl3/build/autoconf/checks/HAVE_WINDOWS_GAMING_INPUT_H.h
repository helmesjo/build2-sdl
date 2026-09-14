// HAVE_WINDOWS_GAMING_INPUT_H

#undef HAVE_WINDOWS_GAMING_INPUT_H

/* Check for the windows.gaming.input.h header. The WinRT
 * Windows.Gaming.Input namespace, part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_WINDOWS_GAMING_INPUT_H 1
#endif
