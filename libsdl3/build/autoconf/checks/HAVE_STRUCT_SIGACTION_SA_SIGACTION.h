// HAVE_STRUCT_SIGACTION_SA_SIGACTION : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SIGACTION_SA_SIGACTION

/* Check for the sa_sigaction data member in the sigaction struct (POSIX
 * real-time signals).
 *
 * Available on Linux/glibc, BSD, and Mac OS. Not available on Windows
 * including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)   || \
    defined(BUILD2_AUTOCONF_MACOS)        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_STRUCT_SIGACTION_SA_SIGACTION 1
#endif
