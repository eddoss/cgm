#ifndef MATH3D_XFORM_3D_EULER_ANGLES_HPP
#define MATH3D_XFORM_3D_EULER_ANGLES_HPP


#include <Math3D/Global.hpp>
#include <type_traits>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<typename T>
struct EulerAngles
{
    T roll;     ///< Rotation around "forward" axis.
    T pitch;    ///< Rotation around "right" axis.
    T yaw;      ///< Rotation around "up" axis.
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_EULER_ANGLES_HPP