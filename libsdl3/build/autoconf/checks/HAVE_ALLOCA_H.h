// HAVE_ALLOCA_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ALLOCA_H

/* Check for the alloca.h header.
 *
 * Available on Linux/glibc, BSD, and Mac OS. Not available on Windows
 * except MinGW: MSVC declares alloca() via malloc.h or intrin.h instead.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)   || \
    defined(BUILD2_AUTOCONF_MACOS)        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__)) || \
    defined(__MINGW32__)
#  define HAVE_ALLOCA_H 1
#endif
