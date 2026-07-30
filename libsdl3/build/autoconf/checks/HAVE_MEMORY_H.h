// HAVE_MEMORY_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MEMORY_H

/* memory.h. Present on Linux/glibc, BSD, Mac OS, Windows (including MinGW).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)   || \
    defined(BUILD2_AUTOCONF_MACOS)        || \
    defined(_WIN32)                       || \
    defined(__CYGWIN__)                   || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_MEMORY_H 1
#endif
