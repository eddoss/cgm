#pragma once


#include <CGM/Modules/Cartesian/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/**
 * Cartesian 3D axes enum.
 */
enum class EAxes
{
    X = 0,  ///< X axis.
    Y,      ///< Y axis.
    Z       ///< Z axis.
};

#define CGM_3D_AXIS_X   CGM_XYZ::EAxes::X
#define CGM_3D_AXIS_Y   CGM_XYZ::EAxes::Y
#define CGM_3D_AXIS_Z   CGM_XYZ::EAxes::Z

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END