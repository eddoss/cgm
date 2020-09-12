#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Axes.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

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

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Types/Transforms.hpp>