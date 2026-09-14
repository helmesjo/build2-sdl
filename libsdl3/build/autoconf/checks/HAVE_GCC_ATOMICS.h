// HAVE_GCC_ATOMICS

#undef HAVE_GCC_ATOMICS

/* Check for GCC/Clang __atomic_* builtins. Present with GCC and Clang. Not MSVC.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_GCC_ATOMICS 1
#endif
