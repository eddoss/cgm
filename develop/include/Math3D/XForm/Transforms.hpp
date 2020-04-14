#ifndef MATH3D_TRANSFORMS_HPP
#define MATH3D_TRANSFORMS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/Pivot.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

/**
 * Describe rotation order.
 */
enum class ERotationOrder
{
    XYZ,    /**< Rotate around X, around Y, around Z */
    XZY,    /**< Rotate around X, around Z, around Y */
    YXZ,    /**< Rotate around Y, around X, around Z */
    YZX,    /**< Rotate around Y, around Z, around X */
    ZXY,    /**< Rotate around Z, around X, around Y */
    ZYX     /**< Rotate around Z, around Y, around X */
};

/* --------------------------------------------------------------------------------------- */

/**
 * Describe transformation order.
 */
enum class ETransformOrder
{
    SRT,    /**< Scale, rotate, translate */
    STR,    /**< Scale, translate, rotate */
    TRS,    /**< Translate, rotate, scale */
    TSR,    /**< Translate, scale, rotate */
    RST,    /**< Rotate, scale, translate */
    RTS     /**< Rotate, translate, scale */
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Transforms
{
    /**
     * Describe translations.
     */
    Vector<D,T>
    translations;

    /**
     * Describe Rotations (in radians).
     */
    Vector<D,T>
    rotations;

    /**
     * Describe scales.
     */
    Vector<D,T>
    scales;

    /**
     * Describe uniform scale.
     */
    T
    uniformScale;

    /**
     * Transformations pivot point.
     */
    Pivot<D,T>
    pivot;

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

#endif // MATH3D_TRANSFORMS_HPP