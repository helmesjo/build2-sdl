// HAVE_SIGTIMEDWAIT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SIGTIMEDWAIT

/* Check for the sigtimedwait() function. POSIX real-time signals. Linux/glibc and some BSD. Not Mac OS or Windows.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)  || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)
#  define HAVE_SIGTIMEDWAIT 1
#endif
