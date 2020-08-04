#pragma once


#include <tuple>
#include <CGM/Core/Vector.hpp>
#include <CGM/Cartesian/3D/ModuleGlobals.hpp>

CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

template<typename T=FLOAT> using AxesTuple    = std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>;
template<typename T=FLOAT> using SpaceTuple   = std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>, Vector<3,T>>;

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END