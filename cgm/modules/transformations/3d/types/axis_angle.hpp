#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>


CGM_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct AxisAngle
{
    CGM_RULE_OF_FIVE(AxisAngle)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    /** Rotation axis direction. */
    Vector<3,T>
    direction {T(1), T(0), T(0)};

    /** Rotation angle in radians. */
    T
    angle {T(0)};

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize direction and angle.
     * @param dir Rotation axis direction.
     * @param ang Rotation angle.
     */
    constexpr
    AxisAngle(const Vector<3,T>& dir, T ang);
};

CGM_NAMESPACE_END


#include "axis_angle.inl"
