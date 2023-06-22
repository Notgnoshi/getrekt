#pragma once
#include <iostream>
#include <memory>
#include <vector>

namespace getrekt {
class InnerRectangle;

class Rectangle
{
  public:
    std::vector<int> dimensions() const noexcept;

  private:
    friend class Rectinator;

    Rectangle(std::shared_ptr<InnerRectangle> rect) noexcept : m_inner(std::move(rect))
    {
        std::cout << "Rectangle(this=" << this << ", inner=" << m_inner.get() << ")\n";
    }
    std::shared_ptr<InnerRectangle> m_inner = nullptr;
};
}  // namespace getrekt
