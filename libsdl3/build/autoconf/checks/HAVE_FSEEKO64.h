// HAVE_FSEEKO64 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FSEEKO64

/* Check for the fseeko64() function. Large-file API on glibc Linux. Not on Mac OS or Windows.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)
#  define HAVE_FSEEKO64 1
#endif
