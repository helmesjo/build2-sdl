// HAVE__I64TOA

#undef HAVE__I64TOA

/* Check for the _i64toa() function. Windows CRT.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or
 * Mac OS.
 */
#if defined(_WIN32)
#  define HAVE__I64TOA 1
#endif
