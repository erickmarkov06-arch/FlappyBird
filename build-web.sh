#!/bin/bash
# Builds the browser version into docs/index.html
# Needs: emsdk in ~/emsdk, and raylib built for web in ~/raylib-web
set -e
cd "$(dirname "$0")"

source ~/emsdk/emsdk_env.sh > /dev/null
RAYLIB=~/raylib-web/src

mkdir -p docs

# --preload-file bundles the assets/ folder into the build so LoadTexture("assets/...") works in the browser
emcc *.cpp -o docs/index.html \
    -Os -Wall \
    -I"$RAYLIB" \
    "$RAYLIB/libraylib.web.a" \
    -DPLATFORM_WEB \
    -s USE_GLFW=3 \
    -s ASYNCIFY \
    -s TOTAL_MEMORY=67108864 \
    --preload-file assets

echo "Built docs/index.html"
echo "Test it with:  cd docs && python3 -m http.server 8080   then open http://localhost:8080"
