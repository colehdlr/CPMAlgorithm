# Vendored cJSON 1.7.18

Single-file JSON parser shipped with the repo so `make` works without any
system install.

## Layout

```
vendor/cjson/
  cJSON.c    implementation
  cJSON.h    public header
```

The Makefile adds `vendor/cjson` to the include path and compiles
`cJSON.c` into `build/cJSON.o`, which is linked into the final binary
alongside the objects built from `src/`.

## Usage

```c
#include "cJSON.h"
```

## Updating

Grab a tagged release from <https://github.com/DaveGamble/cJSON/releases>
and replace both files:

```sh
VER=1.7.18
curl -fsSL -o vendor/cjson/cJSON.c \
  https://raw.githubusercontent.com/DaveGamble/cJSON/v$VER/cJSON.c
curl -fsSL -o vendor/cjson/cJSON.h \
  https://raw.githubusercontent.com/DaveGamble/cJSON/v$VER/cJSON.h
```

License: MIT (see `LICENSE`).
