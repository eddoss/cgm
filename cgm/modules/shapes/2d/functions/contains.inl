

#include "contains.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr bool
contains(const Rectangle<T>& rect, const Vector<2,T>& point)
{
    const auto rectMin = rect.bottomLeft();
    const auto rectMax = rect.topRight();

    return point.x >= rectMin.x && point.x <= rectMax.x &&
           point.y >= rectMin.y && point.y <= rectMax.y;
}

/*  --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
contains(const Rectangle<T>& A, const Rectangle<T>& B)
{
    const auto aMin = A.bottomLeft();
    const auto aMax = A.topRight();
    
    const auto bMin = B.bottomLeft();
    const auto bMax = B.topRight(); 
    
    return bMin.x >= aMin.x && bMin.x <= aMax.x &&
           bMin.y >= aMin.y && bMin.y <= aMax.y &&
           bMax.x >= aMin.x && bMax.x <= aMax.x &&
           bMax.y >= aMin.y && bMax.y <= aMax.y;
}

/*  --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
contains(const Range<T>& range, const Vector<2,T>& point)
{
    return  point.x >= range.min.x && point.x <= range.max.x &&
            point.y >= range.min.y && point.y <= range.max.y;
}

/*  --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
contains(const Range<T>& A, const Range<T>& B)
{    
    return B.min.x >= A.min.x && B.min.x <= A.max.x &&
           B.min.y >= A.min.y && B.min.y <= A.max.y &&
           B.max.x >= A.min.x && B.max.x <= A.max.x &&
           B.max.y >= A.min.y && B.max.y <= A.max.y;
}

CGM_2D_NAMESPACE_END