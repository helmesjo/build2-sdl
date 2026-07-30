// HAVE_GETRESGID : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETRESGID

/* Check for the getresgid() function. Linux/glibc, FreeBSD. Not on Mac OS or Windows.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)   || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199912) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)
#  define HAVE_GETRESGID 1
#endif
