// HAVE__STRREV

#undef HAVE__STRREV

/* Check for the _strrev() function. Windows CRT.
 */
#if defined(_WIN32)
#  define HAVE__STRREV 1
#endif
