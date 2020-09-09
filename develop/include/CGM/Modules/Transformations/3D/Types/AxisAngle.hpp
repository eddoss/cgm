#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct AxisAngle
{
    CGM_RULE_OF_FIVE(AxisAngle)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    /** Rotation axis direction. */
    Vector<3,T>
    direction;

    /** Rotation angle in radians. */
    T
    angle;

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize direction and angle.
     * @param dir Rotation axis direction.
     * @param ang Rotation angle.
     */
    AxisAngle(const Vector<3,T>& dir, T ang);
};

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Types/AxisAngle.hpp>