#pragma once


#include <CGM/Projections/ModuleGlobals.hpp>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Cartesian/3D/Types/Config.hpp>
#include <CGM/Coordinates/Functions/Converters.hpp>
#include <CGM/Transformations/3D/Types/Ray.hpp>
#include <CGM/Projections/Types.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Calculates world space viewport size (for perspective projection).
 * @param fov Vertical angle of field of view (in radiance).
 * @param aspect Viewport size ratio (width / height).
 * @param offset Distance from projection point and viewport center.
 * @return World space viewport size.
 */
template<typename T>
constexpr Vector<2,T>
perspectiveViewport(T fov, T aspect, T offset = val<T>(1));

/**
 * Create ray from projector to specific viewport position.
 * @param point Relative coordinate of point in viewport space. X and Y values should laid out in [-1,+1] range.
 * @param fov Vertical angle of field of view (in radiance).
 * @param aspect Viewport size ratio (width / height).
 * @param projectorSpace Camera space matrix.
 * @return 3D ray from projector.
 */
template<typename T>
constexpr CGM::Ray<T>
perspectiveRay(const Vector<2,T>& point, T fov, T aspect, const Matrix<4,4,T>& projectorSpace);

/**
 * Creates (perspective projection) matrix are transit points from camera frustum to clip space for specific graphics API.
 * @note This matrix should be applied to vectors are in camera space.
 * @tparam API Graphics API.
 * @param fov Vertical angle of field of view (in radiance).
 * @param aspect Viewport size ratio (width / height).
 * @param near Near clipping plane distance.
 * @param far Far clipping plane distance.
 * @return Transition matrix.
 */
template<EGraphicsApi API, typename T>
constexpr Matrix<4,4,T>
perspective(T fov, T aspect, T near, T far);

/**
 * Creates (perspective projection) matrix are transit points from camera frustum to clip space.
 * @note This matrix should be applied to vectors are in camera space.
 * @tparam Right Target coordinate system right axis label.
 * @tparam Up Target coordinate system up axis label.
 * @tparam Forward Target coordinate system forward axis label.
 * @tparam Handedness Target coordinate system handedness.
 * @param nearPlaneWidth Width of near projection plane (sometimes referred as 'left' and 'right', in this case its distance between 'right' and 'left').
 * @param nearPlaneHeight Height of near projection plane (sometimes referred as 'top' and 'bottom', in this case its distance between 'top' and 'bottom').
 * @param nearPlaneDist Offset of the near plane from frustum apex.
 * @param farPlaneDist Distance between frustum apex and bottom (frustum depth).
 * @param cubeWidth Target unit cube width (2 for OpenGL/Vulkan/DirectX).
 * @param cubeHeight Target unit cube height (2 for OpenGL/Vulkan/DirectX).
 * @param cubeDepthMin Target unit cube depth min (-1 for OpenGL/Vulkan, 0 for DirectX).
 * @param cubeDepthMax Target unit cube depth max (1 for OpenGL/Vulkan/DirectX).
 * @return Transition matrix.
 */
template<CGM::E3D Right, CGM::E3D Up, CGM::E3D Forward, EHandedness Handedness, typename T>
constexpr Matrix<4,4,T>
perspective(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax);

CGM_NAMESPACE_END


#include "Perspective.inl"