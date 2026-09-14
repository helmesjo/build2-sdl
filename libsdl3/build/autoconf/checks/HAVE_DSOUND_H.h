// HAVE_DSOUND_H

#undef HAVE_DSOUND_H

/* Check for the dsound.h header. DirectSound, part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_DSOUND_H 1
#endif
