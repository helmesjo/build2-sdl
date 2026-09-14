// HAVE__STRREV

#undef HAVE__STRREV

/* Check for the _strrev() function. Windows CRT.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or
 * Mac OS.
 */
#if defined(_WIN32)
#  define HAVE__STRREV 1
#endif
