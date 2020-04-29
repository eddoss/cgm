#ifndef MATH3D_XFORM_2D_TRANSFORMS_HPP
#define MATH3D_XFORM_2D_TRANSFORMS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/Common.hpp>
#include <Math3D/XForm/2D/Pivot.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<size_t D, typename T>
struct Transforms <D, T, std::enable_if_t<(D == 2)>>
{
    /**
     * Transformations pivot point.
     */
    Pivot<2,T>
    pivot;

    /**
     * Describe translations.
     */
    Vector<2,T>
    translations;

    /**
     * Describe scales.
     */
    Vector<2,T>
    scales;

    /**
     * Describe Rotations (in radians).
     */
    T
    angle;

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
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_2D_TRANSFORMS_HPP