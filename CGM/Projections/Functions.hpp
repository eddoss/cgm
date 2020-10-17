#pragma once


#include <CGM/Projections/ModuleGlobals.hpp>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Cartesian/3D/Types/Config.hpp>
#include <CGM/Coordinates/Functions/Converters.hpp>
#include <CGM/Projections/Types.hpp>
#include <CGM/Core/Functions/IO.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Creates matrix are transit points from camera frustum to normalized device space (unit cube).
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
 * @return Transition (to NDC) matrix.
 **/
template<CGM_XYZ::EAxes Right, CGM_XYZ::EAxes Up, CGM_XYZ::EAxes Forward, CGM::EHandedness Handedness, typename T>
constexpr Matrix<4,4,T>
ndc(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax);

/**
 * Creates matrix are transit points from camera frustum to normalized device space (unit cube) for specific graphics API.
 * @note This matrix should be applied to vectors are in camera space.
 * @param fov Vertical angle of field of view (in radiance).
 * @param aspect Viewport size ration (width / height).
 * @param near Near clipping plane distance.
 * @param far Far clipping plane distance.
 * @param api Graphics API.
 * @return Transition (to NDC) matrix.
 **/
template<typename T>
constexpr Matrix<4,4,T>
ndc(T fov, T aspect, T near, T far, EGraphicsApi api);

CGM_NAMESPACE_END


#include "Functions.inl"