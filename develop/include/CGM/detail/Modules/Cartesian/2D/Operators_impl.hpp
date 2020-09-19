

#include <CGM/detail/Modules/Cartesian/2D/Operators.hpp>


template<typename T>
constexpr bool
operator == (const CGM_XY::Axes<T>& A, const CGM_XY::Axes<T>& B)
{
    return
    CGM::eq(A.x, B.x) &&
    CGM::eq(A.y, B.y);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_XY::Axes<T>& A, const CGM_XY::Axes<T>& B)
{
    return
    CGM::neq(A.x, B.x) ||
    CGM::neq(A.y, B.y);
}
