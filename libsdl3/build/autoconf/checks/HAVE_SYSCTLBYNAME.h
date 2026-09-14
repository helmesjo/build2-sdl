// HAVE_SYSCTLBYNAME

#undef HAVE_SYSCTLBYNAME

/* Check for the sysctlbyname() function. BSD and Mac OS. Not on Linux or Windows.
 */
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_SYSCTLBYNAME 1
#endif
