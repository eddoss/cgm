#pragma once


#include <CGM/detail/Cartesian/2D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/**
 * Cartesian 2D axes enum.
 */
enum class EAxes
{
    X = 0,  ///< X axis.
    Y       ///< Y axis.
};

/* ####################################################################################### */
/* Macro */
/* ####################################################################################### */

#define CGM_2D_AXIS_X   CGM_XY::EAxes::X
#define CGM_2D_AXIS_Y   CGM_XY::EAxes::Y

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END