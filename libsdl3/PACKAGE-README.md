# libsdl3

This is a `build2` package for [SDL3](https://www.libsdl.org/), a
cross-platform multimedia C library (video, audio, input, events, and related
subsystems).

Upstream source: https://github.com/libsdl-org/SDL


## Usage

Add a dependency to your `manifest` (adjust the version constraint as needed):

```
depends: libsdl3 ^3.4.12
```

Import the library in your `buildfile`:

```
import libs = libsdl3%lib{sdl3}
```

Include headers as:

```c
#include <SDL3/SDL.h>
```


## Importable targets

```
lib{sdl3}
```

The shared and static variants follow the normal `build2` `bin.lib` selection.


## Configuration notes

- Private `SDL_build_config.h` is generated at build time with the build2
  `autoconf` module from upstream `SDL_build_config.h.cmake` (cmake flavor)
  and per-platform `autoconf.substitutions` maps in `src/config/subs-*.build`.
  The build defines `USING_GENERATED_CONFIG_H` and does not use static
  `SDL_build_config_<platform>.h` copies.
- Optional OS stacks (X11, Wayland, ALSA, Pulse, etc.) are primarily used via
  upstream's dlopen path where configured. Prefer existing cppget `*-meta`
  packages (for example `libvulkan-meta`, `libopengl-meta`) when hard-linking
  system libraries is required.
- Apple builds compile Objective-C backends with `-fobjc-arc` and link the
  frameworks expected by upstream CMake.


## Platforms

Source selection is gated by `$c.target.class` for macOS, Linux, and Windows.
Other platforms still need backend wiring (see the package repository
`todo.md` for postponed toolchains).


## License

zlib (see `LICENSE.txt`).
