// HAVE_STRNSTR

#undef HAVE_STRNSTR

/* Check for the strnstr() function. BSD and Mac OS. Not on Linux/glibc or Windows.
 */
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_STRNSTR 1
#endif
