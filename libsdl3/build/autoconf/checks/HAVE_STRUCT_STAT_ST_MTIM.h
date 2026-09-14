// HAVE_STRUCT_STAT_ST_MTIM : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_STAT_ST_MTIM

/* Check for the st_mtim data member in the stat struct (POSIX.1-2008).
 *
 * Available on Linux/glibc 2.3+ and modern BSD. Not available on Windows
 * including MinGW or Mac OS (Mac OS uses st_mtimespec instead).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199912) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)
#  define HAVE_STRUCT_STAT_ST_MTIM 1
#endif
