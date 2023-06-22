#pragma once
#include <iostream>
#include <memory>
#include <vector>

namespace getrekt {
class InnerRectangle;

class Rectangle
{
  public:
    virtual ~Rectangle() noexcept { std::cout << "~Rectangle(this=" << this << ")\n"; }
    std::vector<int> dimensions() const noexcept;

  private:
    friend class Rectinator;
    Rectangle(std::shared_ptr<InnerRectangle> rect) noexcept : m_inner(std::move(rect))
    {
        std::cout << "Rectangle(this=" << this << ")\n";
    }
    std::shared_ptr<InnerRectangle> m_inner = nullptr;
};
}  // namespace getrekt
