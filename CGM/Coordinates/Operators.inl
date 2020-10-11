

#include "Operators.hpp"


#include <CGM/Coordinates/Operators.hpp>


/* ####################################################################################### */
/* Polar */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM_COORD::Polar<T>& A, const CGM_COORD::Polar<T>& B)
{
    return  CGM::eq(A.angle(), B.angle()) &&
            CGM::eq(A.radius(), B.radius());
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_COORD::Polar<T>& A, const CGM_COORD::Polar<T>& B)
{
    return  CGM::neq(A.angle(), B.angle()) ||
            CGM::neq(A.radius(), B.radius());
}

/* ####################################################################################### */
/* Spherical */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM_COORD::Spherical<T>& A, const CGM_COORD::Spherical<T>& B)
{
    return  CGM::eq(A.radius(), B.radius())       &&
            CGM::eq(A.latitude(), B.latitude())   &&
            CGM::eq(A.longitude(), B.longitude());
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_COORD::Spherical<T>& A, const CGM_COORD::Spherical<T>& B)
{
    return  CGM::neq(A.radius(), B.radius())       ||
            CGM::neq(A.latitude(), B.latitude())   ||
            CGM::neq(A.longitude(), B.longitude());
}

/* ####################################################################################### */
/* Cylindrical */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM_COORD::Cylindrical<T>& A, const CGM_COORD::Cylindrical<T>& B)
{
    return  CGM::eq(A.angle(), B.angle())     &&
            CGM::eq(A.radius(), B.radius())   &&
            CGM::eq(A.height(), B.height());
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_COORD::Cylindrical<T>& A, const CGM_COORD::Cylindrical<T>& B)
{
    return  CGM::neq(A.angle(), B.angle())      ||
            CGM::neq(A.radius(), B.radius())    ||
            CGM::neq(A.height(), B.height());
}
