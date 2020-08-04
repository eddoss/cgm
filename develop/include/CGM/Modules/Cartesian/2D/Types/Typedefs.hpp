#pragma once


#include <tuple>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/ModuleGlobals.hpp>

CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

template<typename T=FLOAT> using AxesTuple    = std::tuple<Vector<2,T>, Vector<2,T>>;
template<typename T=FLOAT> using SpaceTuple   = std::tuple<Vector<2,T>, Vector<2,T>, Vector<2,T>>;

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END