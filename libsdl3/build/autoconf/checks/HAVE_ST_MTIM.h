// HAVE_ST_MTIM : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ST_MTIM

/* Check for st_mtim in struct stat (POSIX.1-2008). Linux/glibc, modern BSD. Mac OS uses st_mtimespec instead. Not on Windows.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199912) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)
#  define HAVE_ST_MTIM 1
#endif
