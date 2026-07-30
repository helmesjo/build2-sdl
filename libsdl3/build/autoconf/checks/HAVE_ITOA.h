// HAVE_ITOA

#undef HAVE_ITOA

/* Check for the itoa() function. Non-standard. Present on Windows CRT, not portable UNIX.
 */
#if defined(_WIN32)
#  define HAVE_ITOA 1
#endif
