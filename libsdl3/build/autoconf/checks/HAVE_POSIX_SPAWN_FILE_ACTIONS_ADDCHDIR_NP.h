// HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP

// NOTE: keep consistent with HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR.

/* Check for the posix_spawn_file_actions_addchdir_np() function.
 *
 * The non-portable predecessor to the POSIX.1-2024
 * posix_spawn_file_actions_addchdir().
 *
 * Available on Linux/glibc 2.29+, FreeBSD 13.1+, and Mac OS 10.15+. Not
 * available on Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 29)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(13, 1)  || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 15)
#  define HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP 1
#endif
