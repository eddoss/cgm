#ifndef MATH3D_AXIS_HPP
#define MATH3D_AXIS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<typename T>
struct Axis
{
    Vector<3,T> direction;  ///< Axis direction.
    Vector<3,T> position;   ///< Axis position.
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_AXIS_HPP