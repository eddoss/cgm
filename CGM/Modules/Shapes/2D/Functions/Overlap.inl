

#include "Overlap.hpp"


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
constexpr std::tuple<Rectangle<T>, bool>
overlapping(const Rectangle<T>& A, const Rectangle<T>& B)
{
    return std::make_tuple(Rectangle<T>{Vector<2,T>(num<T>(0)), Size<T>(num<T>(0))}, false);

    // TODO Need to implement
}

CGM_2D_NAMESPACE_END