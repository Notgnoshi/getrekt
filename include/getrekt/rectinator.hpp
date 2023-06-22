#pragma once
#include "getrekt/rectangle.hpp"

#include <memory>
#include <vector>

namespace getrekt {
class InnerRectangle;

//! Create, modify, and destroy rectangles on a canvas.
class Rectinator
{
  public:
    Rectinator(int width, int height) noexcept;
    virtual ~Rectinator() noexcept;

    Rectangle create(int min_x, int min_y, int max_x, int max_y) noexcept;

  private:
    int m_width;
    int m_height;

    std::vector<std::shared_ptr<InnerRectangle>> m_rectangles;
};

}  // namespace getrekt
