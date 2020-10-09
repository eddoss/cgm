#pragma once


#include <CGM/Cartesian/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Describe space.
 */
enum class EVectorRepresentation
{
    Point = 0,    /**< Point position. Finite length of vector, homogeneous component equal to 1.*/
    Direction     /**< Direction vector. Infinite length of vector, homogeneous component equal to 0. */
};

/**
 * Describe transformation space.
 */
enum class ESpace
{
    Local = 0,    /**< Transform in local space. */
    World         /**< Transform in world space. */
};

/* ####################################################################################### */
/* Macro */
/* ####################################################################################### */

#define CGM_LOCAL       CGM::ESpace::Local
#define CGM_WORLD       CGM::ESpace::World

#define CGM_POINT       CGM::EVectorRepresentation::Point
#define CGM_DIRECTION   CGM::EVectorRepresentation::Direction

CGM_NAMESPACE_END

/* ####################################################################################### */
/* IO */
/* ####################################################################################### */

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space);


#include <CGM/Cartesian/Common.inl>