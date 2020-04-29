#ifndef MATH3D_XFORM_3D_TRANSFORMS_HPP
#define MATH3D_XFORM_3D_TRANSFORMS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/Common.hpp>
#include <Math3D/XForm/3D/Pivot.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

/**
 * Describe rotation order in 3D space.
 */
enum class ERotationOrder
{
    XYZ = 0,    /**< Rotate around X, around Y, around Z */
    XZY,        /**< Rotate around X, around Z, around Y */
    YXZ,        /**< Rotate around Y, around X, around Z */
    YZX,        /**< Rotate around Y, around Z, around X */
    ZXY,        /**< Rotate around Z, around X, around Y */
    ZYX         /**< Rotate around Z, around Y, around X */
};

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

template<size_t D, typename T>
struct Transforms <D, T, std::enable_if_t<(D == 3)>>
{
    /**
     * Transformations pivot point.
     */
    Pivot<3,T>
    pivot;

    /**
     * Describe translations.
     */
    Vector<3,T>
    translations;

    /**
     * Describe Rotations (in radians).
     */
    Vector<3,T>
    rotations;

    /**
     * Describe scales.
     */
    Vector<3,T>
    scales;

    /**
     * Describe uniform scale.
     */
    T
    uniformScale;

    /**
     * Describe transformation order.
     */
    ETransformOrder
    transformOrder;

    /**
     * Describe rotation order.
     */
    ERotationOrder
    rotationOrder;
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_TRANSFORMS_HPP