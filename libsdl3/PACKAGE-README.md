# libsdl3 - Cross-platform multimedia C library

This is a `build2` package for the
[`SDL`](https://github.com/libsdl-org/SDL) C library. It provides
cross-platform access to audio, keyboard, mouse, joystick/gamepad, and
graphics hardware, used by games, emulators, and other multimedia
applications.


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
