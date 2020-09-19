

#include <CGM/detail/Transformations/Operators.hpp>


/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM_XFORM2D::Pivot<T>& A, const CGM_XFORM2D::Pivot<T>& B)
{
    return A.position == B.position && A.axes == B.axes;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_XFORM2D::Pivot<T>& A, const CGM_XFORM2D::Pivot<T>& B)
{
    return A.position != B.position || A.axes != B.axes;
}

/* ####################################################################################### */
/* Transforms */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM_XFORM2D::Transforms<T>& A, const CGM_XFORM2D::Transforms<T>& B)
{
    return
    A.translation       == B.translation
    && A.scale          == B.scale
    && A.rotations      == B.rotations
    && A.pivot          == B.pivot
    && A.uniformScale   == B.uniformScale
    && A.transformOrder == B.transformOrder;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_XFORM2D::Transforms<T>& A, const CGM_XFORM2D::Transforms<T>& B)
{
    return
    A.translation       != B.translation
    || A.scale          != B.scale
    || A.rotations      != B.rotations
    || A.pivot          != B.pivot
    || A.uniformScale   != B.uniformScale
    || A.transformOrder != B.transformOrder;
}

/* ####################################################################################### */
/* Axis */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const CGM_XFORM2D::ArbitraryAxis<T>& A, const CGM_XFORM2D::ArbitraryAxis<T>& B)
{
    return A.position == B.position && A.direction == B.direction;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const CGM_XFORM2D::ArbitraryAxis<T>& A, const CGM_XFORM2D::ArbitraryAxis<T>& B)
{
    return A.position != B.position || A.direction != B.direction;
}