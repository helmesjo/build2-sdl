// HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR

// NOTE: keep consistent with HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP.

/* Check for the posix_spawn_file_actions_addchdir() function
 * (POSIX.1-2024).
 *
 * glibc declares it as an asm-level alias of
 * posix_spawn_file_actions_addchdir_np(), with no separately exported
 * symbol, starting with glibc 2.44.
 *
 * Available on Linux/glibc 2.44+. Not available on FreeBSD, Mac OS, or
 * Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 44)
#  define HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR 1
#endif
