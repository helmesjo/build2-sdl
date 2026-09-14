// HAVE_MEMFD_CREATE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MEMFD_CREATE

/* Check for the memfd_create() function.
 *
 * Available on Linux/glibc 2.27+. Not available on Windows including
 * MinGW or Mac OS.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 27)
#  define HAVE_MEMFD_CREATE 1
#endif
