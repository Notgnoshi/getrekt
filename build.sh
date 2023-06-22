#!/bin/bash
set -o errexit
set -o pipefail
set -o nounset
set -o noclobber

docker run \
    --rm \
    -it \
    --mount "type=bind,src=$PWD,dst=$PWD" \
    --user "$(id -u):$(id -g)" \
    --workdir "$PWD" \
    emscripten/emsdk:latest \
    bash -c "emcmake cmake -B ./build/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON . && cmake --build ./build/"
