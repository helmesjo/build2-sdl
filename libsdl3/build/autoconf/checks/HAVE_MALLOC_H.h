// HAVE_MALLOC_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MALLOC_H

/* Check for the malloc.h header.
 *
 * Available on Linux/glibc and Windows except MSVC (present on MinGW; MSVC
 * ships it only as a non-portable extension in some versions). Not
 * available on Mac OS or BSD (use stdlib.h instead).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    defined(__MINGW32__)
#  define HAVE_MALLOC_H 1
#endif
