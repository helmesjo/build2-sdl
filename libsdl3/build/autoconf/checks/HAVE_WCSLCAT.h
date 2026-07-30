// HAVE_WCSLCAT

#undef HAVE_WCSLCAT

/* Check for the wcslcat() function. BSD and Mac OS. Not on Linux/glibc or Windows.
 */
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_WCSLCAT 1
#endif
