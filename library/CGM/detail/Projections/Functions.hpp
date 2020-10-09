#pragma once


#include <CGM/detail/Projections/ModuleGlobals.hpp>
#include <CGM/detail/Core/Types/Vector.hpp>
#include <CGM/detail/Core/Types/Matrix.hpp>
#include <CGM/detail/Cartesian/3D/Types/Enums.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Creates matrix are transit points from camera frustum to normalized device space (unit cube).
 * @note This matrix should be applied to vectors are in camera space.
 * @param fov Vertical angle of view (in radians).
 * @param aspect Ration between target frame width and height (width/height).
 * @param near Distance to near plane.
 * @param far Distance to far plane.
 * @param width Target unit cube width (2 for OpenGL/Vulkan/DirectX).
 * @param height Target unit cube height (2 for OpenGL/Vulkan/DirectX).
 * @param depthMin Target unit cube depth min (-1 for OpenGL/Vulkan, 0 for DirectX).
 * @param depthMax Target unit cube depth max (1 for OpenGL/Vulkan/DirectX).
 * @return Transition (to unit cube) matrix.
 **/
template<typename T>
constexpr Matrix<4,4,T>
ndc(T fov, T aspect, T near, T far, T width, T height, T depthMin, T depthMax);

/**
 * Creates matrix are transit points from camera frustum to normalized device space (unit cube).
 * @note This matrix should be applied to vectors are in camera space.
 * @param screenSize Size of near projection plane (sometimes referred as "top and right").
 * @param near Distance to near plane.
 * @param far Distance to far plane.
 * @param width Target unit cube width (2 for OpenGL/Vulkan/DirectX).
 * @param height Target unit cube height (2 for OpenGL/Vulkan/DirectX).
 * @param depthMin Target unit cube depth min (-1 for OpenGL/Vulkan, 0 for DirectX).
 * @param depthMax Target unit cube depth max (1 for OpenGL/Vulkan/DirectX).
 * @return Transition (to unit cube) matrix.
 **/
template<typename T>
constexpr Matrix<4,4,T>
ndc(const Vector<2,T>& screenSize, T near, T far, T width, T height, T depthMin, T depthMax);

CGM_NAMESPACE_END


#include <CGM/detail/Projections/Functions_impl.hpp>
