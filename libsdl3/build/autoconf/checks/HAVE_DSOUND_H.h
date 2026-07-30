// HAVE_DSOUND_H

#undef HAVE_DSOUND_H

/* dsound.h (DirectSound). Windows SDK. Assumed when targeting Windows.
 */
#if defined(_WIN32)
#  define HAVE_DSOUND_H 1
#endif
