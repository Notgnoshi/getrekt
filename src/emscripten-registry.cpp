#include "getrekt/rectangle.hpp"
#include "getrekt/rectinator.hpp"

#include <emscripten/bind.h>

namespace getrekt {
EMSCRIPTEN_BINDINGS(std_wrappers) { emscripten::register_vector<int>("VectorInt"); };

EMSCRIPTEN_BINDINGS(rectangle)
{
    emscripten::class_<Rectangle>("Rectangle").function("dimensions", &Rectangle::dimensions);
};

EMSCRIPTEN_BINDINGS(rectinator)
{
    emscripten::class_<Rectinator>("Rectinator")
        .constructor<int, int>()
        .function("create", &Rectinator::create)
        .function("select", &Rectinator::select);
};
}  // namespace getrekt
