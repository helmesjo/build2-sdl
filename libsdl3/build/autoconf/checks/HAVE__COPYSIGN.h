// HAVE__COPYSIGN

#undef HAVE__COPYSIGN

/* Check for the _copysign() function. Windows CRT spelling of copysign().
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or
 * Mac OS.
 */
#if defined(_WIN32)
#  define HAVE__COPYSIGN 1
#endif
