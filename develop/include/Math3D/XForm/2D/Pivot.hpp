#ifndef MATH3D_XFORM_2D_PIVOT_HPP
#define MATH3D_XFORM_2D_PIVOT_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/Common.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<size_t D, typename T>
struct Pivot <D, T, std::enable_if_t<(D == 2)>>
{
    Vector<2,T> x;          ///< X axes.
    Vector<2,T> y;          ///< Y axes.
    Vector<2,T> position;   ///< Pivot position.
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_2D_PIVOT_HPP