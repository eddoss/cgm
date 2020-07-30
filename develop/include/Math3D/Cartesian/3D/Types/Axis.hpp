#pragma once


#include <type_traits>
#include <Math3D/Core/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

template <size_t D, typename T, typename = void> struct Axis;

template <size_t D, typename T>
struct Axis <D, T, std::enable_if_t<(D == 2 || D == 3)>>
{
    Vector<D,T> direction;  ///< Direction of the axis.
    Vector<D,T> center;     ///< Point through which the axis center passes.
};

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END
