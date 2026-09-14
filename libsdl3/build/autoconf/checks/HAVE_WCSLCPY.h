// HAVE_WCSLCPY

#undef HAVE_WCSLCPY

/* Check for the wcslcpy() function. BSD and Mac OS. Not on Linux/glibc or Windows.
 */
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_WCSLCPY 1
#endif
