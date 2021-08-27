

#include "Operators.hpp"


template<typename T>
constexpr bool
operator == (const CGM_2D::Axes<T>& A, const CGM_2D::Axes<T>& B)
{
    return
    CGM::eq(A.x, B.x) &&
    CGM::eq(A.y, B.y);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_2D::Axes<T>& A, const CGM_2D::Axes<T>& B)
{
    return
    CGM::neq(A.x, B.x) ||
    CGM::neq(A.y, B.y);
}
