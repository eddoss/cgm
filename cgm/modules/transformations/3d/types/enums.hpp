#pragma once


#include <cgm/modules/transformations/3d/module_globals.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Describe rotation order in 3D space.
 */
enum class ERotationOrder
{
    XYZ = 0,    /**< Rotate around X, around Y, around Z */
    XZY,        /**< Rotate around X, around Z, around Y */
    YXZ,        /**< Rotate around Y, around X, around Z */
    YZX,        /**< Rotate around Y, around Z, around X */
    ZXY,        /**< Rotate around Z, around X, around Y */
    ZYX         /**< Rotate around Z, around Y, around X */
};

/**
 * Describe default Cartesian planes.
 */
enum class EPlane
{
    XY = 0,    /**< XY plane */
    YZ,        /**< YZ plane */
    ZX,        /**< ZX plane */
};

/* ####################################################################################### */
/* Macro */
/* ####################################################################################### */

#define CGM_RO_XYZ      CGM::ERotationOrder::XYZ
#define CGM_RO_XZY      CGM::ERotationOrder::XZY
#define CGM_RO_YXZ      CGM::ERotationOrder::YXZ
#define CGM_RO_YZX      CGM::ERotationOrder::YZX
#define CGM_RO_ZXY      CGM::ERotationOrder::ZXY
#define CGM_RO_ZYX      CGM::ERotationOrder::ZYX

#define CGM_PLANE_XY    CGM::EPlane::XY
#define CGM_PLANE_YZ    CGM::EPlane::YZ
#define CGM_PLANE_ZX    CGM::EPlane::ZX

CGM_NAMESPACE_END