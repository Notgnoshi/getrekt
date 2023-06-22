#include "getrekt/rectangle.hpp"

#include <emscripten/bind.h>

namespace getrekt {
EMSCRIPTEN_BINDINGS(std_wrappers) { emscripten::register_vector<int>("VectorInt"); };

EMSCRIPTEN_BINDINGS(rectangle)
{
    emscripten::class_<Rectangle>("Rectangle")
        .constructor<int, int, int, int>()
        .function("area", &Rectangle::area)
        .function("dimensions", &Rectangle::dimensions)
        .property("x", &Rectangle::get_x, &Rectangle::set_x)
        .property("y", &Rectangle::get_y, &Rectangle::set_y)
        .property("width", &Rectangle::get_width, &Rectangle::set_width)
        .property("height", &Rectangle::get_height, &Rectangle::set_height);
};
}  // namespace getrekt
