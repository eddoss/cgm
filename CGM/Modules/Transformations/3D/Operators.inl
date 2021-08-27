

#include "Operators.hpp"


/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM::Pivot<T>& A, const CGM::Pivot<T>& B)
{
    return A.position == B.position && A.axes == B.axes;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM::Pivot<T>& A, const CGM::Pivot<T>& B)
{
    return A.position != B.position || A.axes != B.axes;
}

/* ####################################################################################### */
/* Transforms */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM::Transforms<T>& A, const CGM::Transforms<T>& B)
{
    return
    A.translation       == B.translation
    && A.scale          == B.scale
    && A.rotation       == B.rotation
    && A.pivot          == B.pivot
    && A.uniformScale   == B.uniformScale
    && A.rotationOrder  == B.rotationOrder
    && A.transformOrder == B.transformOrder;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM::Transforms<T>& A, const CGM::Transforms<T>& B)
{
    return
    A.translation       != B.translation
    || A.scale          != B.scale
    || A.rotation       != B.rotation
    || A.pivot          != B.pivot
    || A.uniformScale   != B.uniformScale
    || A.rotationOrder  != B.rotationOrder
    || A.transformOrder != B.transformOrder;
}

/* ####################################################################################### */
/* Axis */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM::Ray<T>& A, const CGM::Ray<T>& B)
{
    return A.position == B.position && A.direction == B.direction;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM::Ray<T>& A, const CGM::Ray<T>& B)
{
    return A.position != B.position || A.direction != B.direction;
}