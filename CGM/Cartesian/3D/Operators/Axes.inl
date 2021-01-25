

#include "Axes.hpp"


template<typename T>
constexpr bool
operator == (const CGM::Axes<T>& A, const CGM::Axes<T>& B)
{
    return
    CGM::eq(A.x, B.x) &&
    CGM::eq(A.y, B.y) &&
    CGM::eq(A.z, B.z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM::Axes<T>& A, const CGM::Axes<T>& B)
{
    return
    CGM::neq(A.x, B.x) ||
    CGM::neq(A.y, B.y) ||
    CGM::neq(A.z, B.z);
}
