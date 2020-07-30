#pragma once


#include <tuple>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>

MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

template<typename T=FLOAT> using AxesTuple    = std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>;
template<typename T=FLOAT> using SpaceTuple   = std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>, Vector<3,T>>;

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END