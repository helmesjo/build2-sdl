// HAVE__I64TOA

#undef HAVE__I64TOA

/* Check for the _i64toa() function. Windows CRT.
 */
#if defined(_WIN32)
#  define HAVE__I64TOA 1
#endif
