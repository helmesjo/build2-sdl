# libsdl3 - Cross-platform multimedia C library

This is a `build2` package for the
[`SDL`](https://github.com/libsdl-org/SDL) C library. It provides
cross-platform access to audio, keyboard, mouse, joystick/gamepad, and
graphics hardware, used by games, emulators, and other multimedia
applications.

`SDL` vendors a modified copy of `stb_image` (indexed-PNG palette loading via
`stbi_load_from_callbacks_with_palette`, direct MJPG-to-NV12 JPEG decode)
rather than depending on it. The palette-loading addition is based on
[nothings/stb#788](https://github.com/nothings/stb/pull/788), which the
`stb_image` maintainer declined to merge upstream. `SDL` periodically
re-syncs the vendored copy against current `stb_image` and reapplies these
changes on top, so this package keeps it bundled rather than unbundling it
as a `depends`.


## Usage

To start using `libsdl3` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libsdl3 ^3.4.0
```

Then import the library in your `buildfile`:

```
import libs = libsdl3%lib{sdl3}
```


## Importable targets

This package provides the following importable targets:

```
lib{sdl3}
```


## Configuration variables

This package provides no configuration variables.
