// HAVE_MODFF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MODFF

/* Check for the modff() function. Available with C99 libm on Linux/glibc, BSD, Mac OS, Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0)     || \
    defined(_WIN32)                        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_MODFF 1
#endif
