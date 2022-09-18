

#include "contains.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr bool
contains(const Rectangle<T>& rect, const Vector<2,T>& point)
{
    const auto a = rect.bottomLeft();
    const auto b = rect.topRight();

    return  point.x >= a.x && point.x <= b.x &&
            point.y >= a.y && point.y <= b.y;
}

/*  --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
contains(const Rectangle<T>& A, const Rectangle<T>& B)
{
    const auto a = A.bottomLeft();
    const auto b = A.topRight();
    
    const auto u = B.bottomLeft();
    const auto v = B.topRight(); 
    
    return  u.x >= a.x && u.x <= b.x &&
            u.y >= a.y && u.y <= b.y &&
            v.x >= a.x && v.x <= b.x &&
            v.y >= a.y && v.y <= b.y;
}

CGM_2D_NAMESPACE_END