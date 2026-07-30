// HAVE__ULTOA

#undef HAVE__ULTOA

/* Check for the _ultoa() function. Windows CRT.
 */
#if defined(_WIN32)
#  define HAVE__ULTOA 1
#endif
