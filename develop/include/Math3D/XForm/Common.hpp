#ifndef MATH3D_XFORM_COMMON_HPP
#define MATH3D_XFORM_COMMON_HPP


#include <Math3D/Global.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<size_t D, typename T=FLOAT, typename = void> struct Pivot;
template<size_t D, typename T=FLOAT, typename = void> struct Transforms;

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/**
 * Describe transformation order.
 */
enum class ETransformOrder
{
    SRT = 0,    /**< Scale, rotate, translate */
    STR,        /**< Scale, translate, rotate */
    TRS,        /**< Translate, rotate, scale */
    TSR,        /**< Translate, scale, rotate */
    RST,        /**< Rotate, scale, translate */
    RTS         /**< Rotate, translate, scale */
};

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/**
 * Describe transformation space.
 */
enum class ESpace
{
    Local = 0,    /**< Transform in local space. */
    World         /**< Transform in world space. */
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_COMMON_HPP