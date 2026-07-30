// HAVE_INOTIFY_INIT1 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_INOTIFY_INIT1

/* Check for the inotify_init1() function. Linux only (glibc 2.10+).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 10)
#  define HAVE_INOTIFY_INIT1 1
#endif
