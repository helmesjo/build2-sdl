// HAVE__LTOA

#undef HAVE__LTOA

/* Check for the _ltoa() function. Windows CRT.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or
 * Mac OS.
 */
#if defined(_WIN32)
#  define HAVE__LTOA 1
#endif
