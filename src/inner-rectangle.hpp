#pragma once
#include <iostream>

namespace getrekt {
class InnerRectangle
{
  public:
    InnerRectangle(int min_x, int min_y, int max_x, int max_y) noexcept :
        m_min_x(min_x), m_min_y(min_y), m_max_x(max_x), m_max_y(max_y)
    {
        std::cout << "InnerRectangle(this=" << this << ")\n";
    }
    virtual ~InnerRectangle() noexcept { std::cout << "~InnerRectangle(this=" << this << ")\n"; }

  private:
    friend class Rectangle;

    int m_min_x;
    int m_min_y;
    int m_max_x;
    int m_max_y;
};
}  // namespace getrekt
