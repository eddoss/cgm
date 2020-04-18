#ifndef MATH3D_PIVOT_HPP
#define MATH3D_PIVOT_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template <typename T>
struct Pivot
{
    Vector<3,T> x;           ///< X axes.
    Vector<3,T> y;           ///< Y axes.
    Vector<3,T> z;           ///< Z axes.
    Vector<3,T> position;    ///< Pivot position.
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_PIVOT_HPP