#include "getrekt/rectangle.hpp"

#include "inner-rectangle.hpp"

namespace getrekt {
std::vector<int> Rectangle::dimensions() const noexcept
{
    const auto width = m_inner->m_max_x - m_inner->m_min_x;
    const auto height = m_inner->m_max_y - m_inner->m_min_y;

    return {m_inner->m_min_x, m_inner->m_min_y, width, height};
}
}  // namespace getrekt
