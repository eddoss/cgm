#pragma once


#include <CGM/Modules/Core/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Enums */
/* ####################################################################################### */

/**
 * Describe Cartesian axes and vector components for 2D space.
 */
enum class E2D
{
    X = size_t(0),
    Y
};

/**
 * Describe Cartesian axes and vector components for 3D space.
 */
enum class E3D
{
    X = size_t(0),
    Y,
    Z
};

/**
 * Describe Cartesian axes and vector components for 4D space.
 */
enum class E4D
{
    X = size_t(0),
    Y,
    Z,
    W
};

/* ####################################################################################### */
/* Macro */
/* ####################################################################################### */

#define CGM_2D_X    CGM::E2D::X
#define CGM_2D_Y    CGM::E2D::Y

#define CGM_3D_X    CGM::E3D::X
#define CGM_3D_Y    CGM::E3D::Y
#define CGM_3D_Z    CGM::E3D::Z

#define CGM_4D_X    CGM::E4D::X
#define CGM_4D_Y    CGM::E4D::Y
#define CGM_4D_Z    CGM::E4D::Z
#define CGM_4D_W    CGM::E4D::W

CGM_NAMESPACE_END