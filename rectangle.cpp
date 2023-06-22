#include <emscripten/bind.h>

namespace getrekt {
int area(int width, int height) { return width * height; }

class Rectangle
{
  public:
    Rectangle(int x, int y, int width, int height) noexcept :
        m_x{x}, m_y{y}, m_width{width}, m_height{height}
    {
    }

    int area() const noexcept { return m_width * m_height; }

  private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};
}  // namespace getrekt

EMSCRIPTEN_BINDINGS(getrekt) { emscripten::function("rectangle_area", &getrekt::area); }
