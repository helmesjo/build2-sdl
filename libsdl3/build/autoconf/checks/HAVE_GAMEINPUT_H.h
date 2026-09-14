// HAVE_GAMEINPUT_H

#undef HAVE_GAMEINPUT_H

/* Check for the gameinput.h header. Microsoft's GameInput API, an
 * optional header in a modern Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_GAMEINPUT_H 1
#endif
