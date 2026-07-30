// HAVE__UI64TOA

#undef HAVE__UI64TOA

/* Check for the _ui64toa() function. Windows CRT.
 */
#if defined(_WIN32)
#  define HAVE__UI64TOA 1
#endif
