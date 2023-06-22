#!/bin/bash

docker run \
    -it \
    --rm \
    -p 8080:80 \
    --mount "type=bind,source=$PWD,target=/usr/share/nginx/html,readonly" \
    nginx:latest
