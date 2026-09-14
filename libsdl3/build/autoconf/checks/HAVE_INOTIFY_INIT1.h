// HAVE_INOTIFY_INIT1 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_INOTIFY_INIT1

/* Check for the inotify_init1() function.
 *
 * Available on Linux/glibc 2.10+. Not available on Windows including
 * MinGW or Mac OS.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 10)
#  define HAVE_INOTIFY_INIT1 1
#endif
