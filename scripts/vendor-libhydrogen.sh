#!/usr/bin/env sh
# Re-vendor libhydrogen from upstream, keeping only the files the Carp
# bindings need to build: hydrogen.h, hydrogen.c, impl/, and LICENSE.
#
# Usage: scripts/vendor-libhydrogen.sh [git-ref]   (default: HEAD)
set -eu

UPSTREAM="https://github.com/jedisct1/libhydrogen"
REF="${1:-HEAD}"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="$ROOT/libhydrogen"

TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

git clone --quiet "$UPSTREAM" "$TMP/src"
git -C "$TMP/src" checkout --quiet "$REF"
SHA="$(git -C "$TMP/src" rev-parse HEAD)"
CDATE="$(git -C "$TMP/src" log -1 --format=%cI)"

rm -rf "$DEST"
mkdir -p "$DEST"
cp "$TMP/src/hydrogen.h" "$TMP/src/hydrogen.c" "$TMP/src/LICENSE" "$DEST/"
cp -R "$TMP/src/impl" "$DEST/impl"

cat > "$DEST/VENDORED" <<EOF
upstream: $UPSTREAM
commit:   $SHA
date:     $CDATE

Only the files required to build the Carp bindings are vendored here
(hydrogen.h, hydrogen.c, impl/, LICENSE). To update, run:

    scripts/vendor-libhydrogen.sh [git-ref]
EOF

echo "Vendored libhydrogen @ $SHA ($CDATE)"
