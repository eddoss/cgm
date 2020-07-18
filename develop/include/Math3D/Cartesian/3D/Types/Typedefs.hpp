#ifndef MATH3D_XYZ_TYPEDEFS_HPP
#define MATH3D_XYZ_TYPEDEFS_HPP


#include <tuple>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>

MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

template<typename T> using AxesTuple    = std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>;
template<typename T> using SpaceTuple   = std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>, Vector<3,T>>;

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif //MATH3D_XYZ_TYPEDEFS_HPP
