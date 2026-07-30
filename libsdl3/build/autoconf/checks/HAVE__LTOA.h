// HAVE__LTOA

#undef HAVE__LTOA

/* Check for the _ltoa() function. Windows CRT.
 */
#if defined(_WIN32)
#  define HAVE__LTOA 1
#endif
