// HAVE_ELF_AUX_INFO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ELF_AUX_INFO

/* Check for the elf_aux_info() function. FreeBSD. Not on Linux, Mac OS, or Windows.
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(12, 0)
#  define HAVE_ELF_AUX_INFO 1
#endif
