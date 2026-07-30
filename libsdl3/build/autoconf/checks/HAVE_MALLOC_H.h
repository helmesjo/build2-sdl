// HAVE_MALLOC_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MALLOC_H

/* malloc.h. Present on Linux/glibc and MinGW. Not on Mac OS (use stdlib.h) or MSVC
 * as a preferred portable header (MSVC has it as an extension in some versions).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    defined(__MINGW32__)
#  define HAVE_MALLOC_H 1
#endif
