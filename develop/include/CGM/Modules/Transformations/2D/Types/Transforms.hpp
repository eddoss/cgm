#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Axes.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/2D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/2D/Types/Pivot.hpp>


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
    pivot;

    /**
     * Describe translations.
     */
    Vector<2,T>
    translation;

    /**
     * Describe scales.
     */
    Vector<2,T>
    scale;

    /**
     * Describe uniform scale.
     */
    T
    uniformScale;

    /**
     * Describe rotation (in radians).
     */
    T
    rotation;

    /**
     * Describe transformation order.
     */
    ETransformOrder
    transformOrder;

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


#include <CGM/detail/Modules/Transformations/2D/Types/Transforms.hpp>