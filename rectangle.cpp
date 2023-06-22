#include <emscripten/bind.h>

int area(int width, int height) { return width * height; }

EMSCRIPTEN_BINDINGS(getrekt) { emscripten::function("rectangle_area", &area); }
