#pragma once


#include <CGM/Projections/Functions.hpp>


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr Matrix<4,4,T>
ndc(T fov, T aspect, T near, T far, T width, T height, T depthMin, T depthMax)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
ndc(const Vector<2,T>& screenSize, T near, T far, T width, T height, T depthMin, T depthMax)
{

}

CGM_NAMESPACE_END