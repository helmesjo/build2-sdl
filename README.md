# SDL - cross-platform multimedia C library

This is a `build2` package repository for
[`SDL`](https://github.com/libsdl-org/SDL), a cross-platform multimedia C
library.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libsdl3` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libsdl3/PACKAGE-README.md) file.

The development setup for `SDL` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../SDL.git
cd SDL

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
