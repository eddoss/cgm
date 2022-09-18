#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/cartesian/3d/functions/axes.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>


CGM_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Transforms
{
    CGM_RULE_OF_FIVE(Transforms)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    /**
     * Transformations pivot point.
     */
    Pivot<T>
    pivot {};

    /**
     * Describe translations.
     */
    Vector<3,T>
    translation {T(0), T(0), T(0)};

    /**
     * Describe Rotations (in radians).
     */
    Vector<3,T>
    rotation {T(0), T(0), T(0)};

    /**
     * Describe scales.
     */
    Vector<3,T>
    scale {T(1), T(1), T(1)};

    /**
     * Describe uniform scale.
     */
    T
    uniformScale {T(1)};

    /**
     * Describe transformation order.
     */
    ETransformOrder
    transformOrder {ETransformOrder::SRT};

    /**
     * Describe rotation order.
     */
    ERotationOrder
    rotationOrder {ERotationOrder::XYZ};

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize translation, scale and rotation.
     * @param t Translation value.
     * @param s Scale value.
     * @param r Rotation value.
     */
    constexpr
    Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r);

    /**
     * Initialize translation, scale, rotation and pivot.
     * @param t Translation value.
     * @param s Scale value.
     * @param r Rotation value.
     * @param p Pivot point.
     */
    constexpr
    Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, const Pivot<T>& p);

    /**
     * Initialize translation, scale, rotation and uniform scale.
     * @param t Translation value.
     * @param s Scale value.
     * @param us Uniform scale value
     * @param r Rotation value.
     */
    constexpr
    Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, T us);

    /**
     * Initialize translation, scale, rotation, uniform scale and pivot.
     * @param t Translation value.
     * @param s Scale value.
     * @param us Uniform scale value
     * @param r Rotation value.
     * @param p Pivot point.
     */
    constexpr
    Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, T us, const Pivot<T>& p);

    /**
     * Initialize all attributes.
     * @param t Translation value.
     * @param s Scale value.
     * @param us Uniform scale value
     * @param r Rotation value.
     * @param p Pivot point.
     * @param ro Rotation order.
     * @param to Transform order.
     */
    constexpr
    Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, T us, const Pivot<T>& p, ERotationOrder ro, ETransformOrder to);
};

CGM_NAMESPACE_END


#include "transforms.inl"
