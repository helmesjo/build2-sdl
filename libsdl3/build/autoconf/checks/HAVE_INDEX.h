// HAVE_INDEX : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_INDEX

/* Check for the index() function (BSD strchr alias). Present on glibc, BSD, Mac OS.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)   || \
    defined(BUILD2_AUTOCONF_MACOS)        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_INDEX 1
#endif
