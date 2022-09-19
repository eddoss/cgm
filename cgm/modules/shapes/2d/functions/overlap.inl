

#include "overlap.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr bool
overlapped(const Rectangle<T>& A, const Rectangle<T>& B)
{
    const auto au = A.bottomLeft();
    const auto av = A.topRight();
    const auto bu = B.bottomLeft();
    const auto bv = B.topRight();

    return !(bu.x >= au.x || bu.x <= au.x || bv.y <= av.y || bv.y <= av.y);

    // TODO Need to test
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr std::tuple<bool, Rectangle<T>>
overlapping(const Rectangle<T>& A, const Rectangle<T>& B)
{
    // TODO Need to implement and test
    return {};
}

CGM_2D_NAMESPACE_END