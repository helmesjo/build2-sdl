#include <SDL3/SDL.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* Exercise a non-inline symbol from the shared library. */
  const char *rev = SDL_GetRevision ();
  assert (rev != NULL);

  if (!SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS))
  {
    /* Headless CI may lack a display. Still OK if library linked. */
    SDL_ClearError ();
    if (!SDL_Init (0))
    {
      const char *err = SDL_GetError ();
      assert (err != NULL);
    }
  }

  SDL_Quit ();
  return 0;
}
