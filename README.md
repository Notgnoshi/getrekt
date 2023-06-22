# getrekt

Experimentation on web assembly bindings for C++ for computational geometry operations.

## How to run

Loading WASM requires running a webserver. You can't just open the `index.html` in a web browser.
Run a simple Nginx web server in the current directory with
```sh
./nginx.sh
```

and navigate to <http://localhost:8080> to view the project in your browser.

## How to build

Using the `emscripten/emsdk:latest` Docker image:
```sh
./build.sh
```

Natively:
```sh
emcmake cmake -B ./build/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
cmake --build ./build/
```
