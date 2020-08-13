#pragma once


#include <CGM/Modules/Cartesian/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Describe space.
 */
enum class EVectorRepresentation
{
    Point = 0,    /**< Point position. Finite length of vector, homogeneous component equal to 1.*/
    Direction     /**< Direction vector. Infinite length of vector, homogeneous component equal to 0. */
};

#define CGM_POINT       CGM::EVectorRepresentation::Point
#define CGM_DIRECTION   CGM::EVectorRepresentation::Direction

CGM_NAMESPACE_END