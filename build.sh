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
    emcc -lembind hello-world.cpp -o hello-world.js
