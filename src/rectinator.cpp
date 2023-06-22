#include "getrekt/rectinator.hpp"

#include "getrekt/rectangle.hpp"
#include "inner-rectangle.hpp"

#include <iostream>

namespace getrekt {
Rectinator::Rectinator(int width, int height) noexcept : m_width(width), m_height(height)
{
    std::cout << "Rectinator(this=" << this << ", width=" << width << ", height=" << height
              << ")\n";
}

Rectinator::~Rectinator() noexcept { std::cout << "~Rectinator(this=" << this << ")\n"; }

Rectangle Rectinator::create(int min_x, int min_y, int max_x, int max_y) noexcept
{
    const auto rect = std::make_shared<InnerRectangle>(min_x, min_y, max_x, max_y);
    const auto handle = Rectangle(rect);
    this->m_rectangles.push_back(rect);

    return handle;
}

std::unique_ptr<Rectangle> Rectinator::select(int x, int y) const noexcept
{
    for (const auto& rect : m_rectangles)
    {
        if (rect->m_min_x <= x && x <= rect->m_max_x && rect->m_min_y <= y && y <= rect->m_max_y)
        {
            // std::make_unique can't access the private Rectangle constructor?!
            return std::unique_ptr<Rectangle>(new Rectangle(rect));
        }
    }
    return nullptr;
}
}  // namespace getrekt
