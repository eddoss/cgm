#ifndef MATH3D_TRANSFORMS_HPP
#define MATH3D_TRANSFORMS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForms/3D/Pivot.hpp>


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

template<typename T>
struct Transforms
{
    /**
     * Transformations pivot point.
     */
    Pivot<T>
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

#endif // MATH3D_TRANSFORMS_HPP