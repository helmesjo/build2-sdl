// HAVE_FDATASYNC : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FDATASYNC

/* Check for the fdatasync() function. Linux/glibc, FreeBSD 8+, not classic Mac OS or Windows.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(8, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200805) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)
#  define HAVE_FDATASYNC 1
#endif
