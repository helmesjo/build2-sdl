// HAVE_TPCSHRD_H

#undef HAVE_TPCSHRD_H

/* Check for the tpcshrd.h header. Windows Tablet PC / pen-input API,
 * part of the Windows SDK.
 *
 * Available on Windows including MinGW (assumed present when targeting
 * Windows). Not available on Linux/glibc or Mac OS.
 */
#if defined(_WIN32)
#  define HAVE_TPCSHRD_H 1
#endif
