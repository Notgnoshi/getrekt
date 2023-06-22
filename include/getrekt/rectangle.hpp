#include <iostream>
#include <vector>

class Rectangle
{
  public:
    Rectangle(int x, int y, int width, int height) noexcept :
        m_x{x}, m_y{y}, m_width{width}, m_height{height}
    {
        std::cout << "Rectangle(" << x << ", " << y << ", " << width << ", " << height << ")\n";
    }
    virtual ~Rectangle() noexcept { std::cout << "~Rectangle()\n"; }

    [[nodiscard]] int area() const noexcept { return m_width * m_height; }
    void set_x(int x) noexcept { m_x = x; }
    [[nodiscard]] int get_x() const noexcept { return m_x; }
    void set_y(int y) noexcept { m_y = y; }
    [[nodiscard]] int get_y() const noexcept { return m_y; }
    void set_width(int w) noexcept { m_width = w; }
    [[nodiscard]] int get_width() const noexcept { return m_width; }
    void set_height(int h) noexcept { m_height = h; }
    [[nodiscard]] int get_height() const noexcept { return m_height; }

    [[nodiscard]] std::vector<int> dimensions() const noexcept
    {
        return {m_x, m_y, m_width, m_height};
    };

  private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};
