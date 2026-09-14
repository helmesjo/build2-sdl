// HAVE_SEM_TIMEDWAIT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SEM_TIMEDWAIT

/* Check for the sem_timedwait() function. POSIX. Linux/glibc, not Mac OS (until recently) or Windows. Mac OS lacks unnamed semaphore timed wait historically.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199912) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)
#  define HAVE_SEM_TIMEDWAIT 1
#endif
