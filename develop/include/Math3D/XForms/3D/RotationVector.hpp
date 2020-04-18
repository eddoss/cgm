#ifndef MATH3D_ROTATION_AXIS_HPP
#define MATH3D_ROTATION_AXIS_HPP


#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<typename T>
struct RotationAxis
{
    /** Axis direction. */
    Vector<3,T>
    direction;

    /** Axis position. */
    Vector<3,T>
    position;
};

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

template<typename T>
struct RotationVector
{
    /** Rotation axis. */
    RotationAxis<T>
    axis;

    /** Rotation angle (in radians). */
    T
    angle;
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_ROTATION_AXIS_HPP