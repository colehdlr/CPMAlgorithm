# Vendored raylib 6.0

Pre-built raylib static libraries shipped with the repo so `make` works without
any system install.

## Layout

```
vendor/raylib/
  include/            shared headers (raylib.h, raymath.h, rlgl.h)
  lib/macos/          libraylib.a  (universal: arm64 + x86_64)
  lib/linux-amd64/    libraylib.a
```

The Makefile auto-selects `lib/<platform>/libraylib.a` based on `uname`.

## Adding another platform

Download the matching prebuilt from
<https://github.com/raysan5/raylib/releases/tag/6.0>, e.g.

```sh
# Linux arm64
curl -L -o /tmp/r.tar.gz \
  https://github.com/raysan5/raylib/releases/download/6.0/raylib-6.0_linux_arm64.tar.gz
tar -xzf /tmp/r.tar.gz -C /tmp
mkdir -p vendor/raylib/lib/linux-arm64
cp /tmp/raylib-6.0_linux_arm64/lib/libraylib.a vendor/raylib/lib/linux-arm64/
```

Then add a matching branch in the Makefile's platform detection.

License: zlib (see `LICENSE`).
