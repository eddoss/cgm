#pragma once


#include <CGM/Projections/ModuleGlobals.hpp>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Projections/Types.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Creates matrix are transit points from camera frustum to normalized device space (unit cube).
 * @note This matrix should be applied to vectors are in camera space.
 * @param nearPlaneWidth Width of near projection plane (sometimes referred as 'left' and 'right', in this case its distance between 'right' and 'left').
 * @param nearPlaneHeight Height of near projection plane (sometimes referred as 'top' and 'bottom', in this case its distance between 'top' and 'bottom').
 * @param nearPlaneDist Offset of the near plane from frustum apex.
 * @param farPlaneDist Distance between frustum apex and bottom (frustum depth).
 * @param cubeWidth Target unit cube width (2 for OpenGL/Vulkan/DirectX).
 * @param cubeHeight Target unit cube height (2 for OpenGL/Vulkan/DirectX).
 * @param cubeDepthMin Target unit cube depth min (-1 for OpenGL/Vulkan, 0 for DirectX).
 * @param cubeDepthMax Target unit cube depth max (1 for OpenGL/Vulkan/DirectX).
 * @return Transition (to NDC) matrix.
 **/
template<typename T>
constexpr Matrix<4,4,T>
ndc(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax);

/**
 * Creates matrix are transit points from camera frustum to normalized device space (unit cube) for specific graphics API.
 * @note This matrix should be applied to vectors are in camera space.
 * @param fov Vertical angle of field of view.
 * @param viewport Current viewport size (target frame buffer size).
 * @param api Graphics API.
 * @return Transition (to NDC) matrix.
 **/
template<typename T>
constexpr Matrix<4,4,T>
ndc(T fov, const Vector<2,uint32>& viewport, EGraphicsApi api);

CGM_NAMESPACE_END


#include "Functions.inl"