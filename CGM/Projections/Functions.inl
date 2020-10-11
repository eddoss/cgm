

#include "Functions.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr Matrix<4,4,T>
ndc(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
ndc(T fov, const Vector<2,uint32>& viewport, EGraphicsApi api)
{

}

CGM_NAMESPACE_END