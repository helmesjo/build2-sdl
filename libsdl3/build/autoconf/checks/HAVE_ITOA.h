// HAVE_ITOA

#undef HAVE_ITOA

/* Check for the itoa() function. Non-standard Windows CRT function, not
 * part of any UNIX libc.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or
 * Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_ITOA 1
#endif
