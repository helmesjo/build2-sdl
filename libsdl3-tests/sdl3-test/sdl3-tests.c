#include <sdl3-test/sdl3-tests.h>

#include <errno.h>

int say_hello (FILE *f, const char* n)
{
  if (f == NULL || n == NULL || *n == '\0')
  {
    errno = EINVAL;
    return -1;
  }

  return fprintf (f, "Hello, %s!\n", n);
}
