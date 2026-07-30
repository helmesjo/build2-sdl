// HAVE_DDRAW_H

#undef HAVE_DDRAW_H

/* ddraw.h (DirectDraw). Windows SDK. Assumed when targeting Windows.
 */
#if defined(_WIN32)
#  define HAVE_DDRAW_H 1
#endif
