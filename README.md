# SDL - build2 packaging

This is a `build2` package repository for
[SDL3](https://github.com/libsdl-org/SDL), a cross-platform multimedia C
library.

For consumers, see [`libsdl3/PACKAGE-README.md`](libsdl3/PACKAGE-README.md).


## Packages

| Package | Status | Description |
|---------|--------|-------------|
| `libsdl3` | active | Core SDL3 library |
| `libsdl3-tests` | active | `lib{sdl3-test}` helper and `testautomation` |
| `sdl3-examples` | planned | Optional examples |

Upstream is a git submodule at `upstream/` (currently `release-3.4.12`).


## Development

Standard `bdep` workflow:

```
git clone --recurse-submodules .../SDL.git
cd SDL

bdep init -C @host cc config.c=clang
bdep update
bdep test
```

Local notes that are not part of the package live in untracked `todo.md`
(outside-package follow-ups).


## Layout

```
upstream/          # libsdl-org/SDL submodule
libsdl3/           # core package (build2 overlay via symlinks)
packages.manifest
buildfile
```
