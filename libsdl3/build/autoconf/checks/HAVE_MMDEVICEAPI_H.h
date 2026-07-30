// HAVE_MMDEVICEAPI_H

#undef HAVE_MMDEVICEAPI_H

/* mmdeviceapi.h (WASAPI). Windows SDK. Assumed when targeting Windows.
 */
#if defined(_WIN32)
#  define HAVE_MMDEVICEAPI_H 1
#endif
