#include <emscripten/bind.h>

#include <iostream>

namespace getrekt {
int area(int width, int height) { return width * height; }

class Rectangle
{
  public:
    Rectangle(int x, int y, int width, int height) noexcept :
        m_x{x}, m_y{y}, m_width{width}, m_height{height}
    {
        std::cout << "Rectangle(" << x << ", " << y << ", " << width << ", " << height << ")\n";
    }
    ~Rectangle() { std::cout << "~Rectangle()\n"; }

    int area() const noexcept { return m_width * m_height; }
    void set_x(int x) noexcept { m_x = x; }
    int get_x() const noexcept { return m_x; }
    void set_y(int y) noexcept { m_y = y; }
    int get_y() const noexcept { return m_y; }
    void set_width(int w) noexcept { m_width = w; }
    int get_width() const noexcept { return m_width; }
    void set_height(int h) noexcept { m_height = h; }
    int get_height() const noexcept { return m_height; }

    std::vector<int> dimensions() const noexcept { return {m_x, m_y, m_width, m_height}; };

  private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};

namespace bindings {
    EMSCRIPTEN_BINDINGS(getrekt)
    {
        emscripten::register_vector<int>("VectorInt");
        emscripten::function("rectangle_area", &getrekt::area);
        emscripten::class_<Rectangle>("Rectangle")
            .constructor<int, int, int, int>()
            .function("area", &Rectangle::area)
            .function("dimensions", &Rectangle::dimensions)
            .property("x", &Rectangle::get_x, &Rectangle::set_x)
            .property("y", &Rectangle::get_y, &Rectangle::set_y)
            .property("width", &Rectangle::get_width, &Rectangle::set_width)
            .property("height", &Rectangle::get_height, &Rectangle::set_height);
    }
}  // namespace bindings
}  // namespace getrekt
