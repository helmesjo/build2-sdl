# libsdl3-tests

`build2` test package for [libsdl3](https://www.libsdl.org/). It provides:

- `lib{sdl3-test}` -- static SDL_test helper (upstream `SDL3_test`)
- `exe{testautomation}` -- upstream noninteractive automation suite

Public test headers remain in `libsdl3` as `<SDL3/SDL_test*.h>`.


## Usage

Pulled in automatically when testing `libsdl3` via the `tests:` manifest
field. You can also depend on it explicitly:

```
depends: libsdl3-tests == $
```

Import the helper library:

```
import test_libs = libsdl3-tests%lib{sdl3-test}
```


## Running tests

```
bdep test -d libsdl3
```

`testautomation` is run with `SDL_VIDEODRIVER=dummy` and
`SDL_AUDIODRIVER=dummy`, with a 120s timeout treated as success (matches
upstream noninteractive timeout).


## License

zlib for the packaging overlay. Upstream `test/LICENSE.txt` is more
permissive for some test sources (see `TEST-LICENSE.txt`).
