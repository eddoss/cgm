

#include "Contains.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE bool
contains(const Rectangle<T>& rect, const Vector<2,T>& point)
{
    const auto a = bottomLeft(rect);
    const auto b = topRight(rect);

    return  point.x >= a.x && point.x <= b.x &&
            point.y >= a.y && point.y <= b.y;
}

CGM_2D_NAMESPACE_END