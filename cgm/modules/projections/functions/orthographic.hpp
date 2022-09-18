#pragma once


#include <cgm/modules/projections/module_globals.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/cartesian/3d/functions/utils.hpp>
#include <cgm/modules/cartesian/3d/types/config.hpp>
#include <cgm/modules/coordinates/functions/converters.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/projections/types.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Calculates global space viewport size (for orthographic projection).
 * @param scale Affect like a zoom.
 * @param aspect Viewport size ratio (width / height).
 * @return Global space viewport size.
 */
template<typename T>
constexpr enable_if_floating<T, Vector<2,T>>
orthographicViewport(T aspect, T scale = T(1));

/**
 * Create ray from projector to specific viewport position.
 * @param point Relative coordinate of point in viewport space. X and Y values should laid out in [-1,+1] range.
 * @param aspect Viewport size ratio (width / height).
 * @param projectorSpace Camera space matrix.
 * @return 3D ray from projector.
 */
template<typename T>
constexpr enable_if_floating<T, Ray<T>>
orthographicRay(const Vector<2,T>& point, T aspect, T scale, const Matrix<4,4,T>& projectorSpace);

/**
 * Creates (orthographic projection) matrix are transit points from camera frustum to clip space for specific graphics API.
 * @note This matrix should be applied to vectors are in camera space.
 * @tparam API Graphics API.
 * @param aspect Viewport size ratio (width / height).
 * @param scale Affect like a zoom.
 * @param near Near clipping plane distance.
 * @param far Far clipping plane distance.
 * @return Transition matrix.
 */
template<EGraphicsApi API, typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
orthographic(T aspect, T scale, T near, T far);

/**
 * Creates (orthographic projection) matrix are transit points from camera frustum to clip space.
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
constexpr enable_if_floating<T, Matrix<4,4,T>>
orthographic(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax);

CGM_NAMESPACE_END


#include "orthographic.inl"
