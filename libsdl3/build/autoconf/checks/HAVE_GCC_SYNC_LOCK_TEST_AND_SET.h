// HAVE_GCC_SYNC_LOCK_TEST_AND_SET

#undef HAVE_GCC_SYNC_LOCK_TEST_AND_SET

/* Legacy GCC __sync_lock_test_and_set. SDL prefers __atomic (HAVE_GCC_ATOMICS). Left undefined so the atomic path is used.
 */
