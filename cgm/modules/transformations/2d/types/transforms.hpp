#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/cartesian/2d/functions/axes.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/2d/module_globals.hpp>
#include <cgm/modules/transformations/2d/types/pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Transforms
{
    CGM_RULE_OF_FIVE(Transforms)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    /**
     * Describe translations.
     */
    Pivot<T>
    pivot {};

    /**
     * Describe translations.
     */
    Vector<2,T>
    translation {T(0), T(0)};

    /**
     * Describe scales.
     */
    Vector<2,T>
    scale {T(1), T(1)};

    /**
     * Describe uniform scale.
     */
    T
    uniformScale {T(1)};

    /**
     * Describe rotation (in radians).
     */
    T
    rotation {T(0)};

    /**
     * Describe transformation order.
     */
    ETransformOrder
    transformOrder {ETransformOrder::SRT};

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize translation, scale and rotation.
     * @param t Translation value.
     * @param s Scale value.
     * @param r Rotation angle.
     */
    constexpr
    Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r);

    /**
     * Initialize translation, scale, rotation and uniform scale.
     * @param t Translation value.
     * @param s Scale value.
     * @param us Uniform scale value
     * @param r Rotation value.
     */
    constexpr
    Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, T us);

    /**
     * Initialize translation, scale and rotation.
     * @param t Translation value.
     * @param s Scale value.
     * @param r Rotation angle.
     * @param p Pivot point.
     */
    constexpr
    Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, const Pivot<T>& p);

    /**
     * Initialize translation, scale, rotation and uniform scale.
     * @param t Translation value.
     * @param s Scale value.
     * @param us Uniform scale value
     * @param r Rotation value.
     * @param p Pivot point.
     */
    constexpr
    Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, T us, const Pivot<T>& p);

    /**
     * Initialize translation, scale, rotation, uniform scale and pivot.
     * @param t Translation value.
     * @param s Scale value.
     * @param us Uniform scale value
     * @param r Rotation value.
     * @param p Pivot point.
     */
    constexpr
    Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, T us, const Pivot<T>& p, ETransformOrder to);
};

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "transforms.inl"
