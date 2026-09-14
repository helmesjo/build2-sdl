// HAVE__ULTOA

#undef HAVE__ULTOA

/* Check for the _ultoa() function. Windows CRT.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or
 * Mac OS.
 */
#if defined(_WIN32)
#  define HAVE__ULTOA 1
#endif
