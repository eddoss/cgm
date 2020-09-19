#pragma once


#include <CGM/detail/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

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

#define CGM_RO_XYZ      CGM_XFORM3D::ERotationOrder::XYZ
#define CGM_RO_XZY      CGM_XFORM3D::ERotationOrder::XZY
#define CGM_RO_YXZ      CGM_XFORM3D::ERotationOrder::YXZ
#define CGM_RO_YZX      CGM_XFORM3D::ERotationOrder::YZX
#define CGM_RO_ZXY      CGM_XFORM3D::ERotationOrder::ZXY
#define CGM_RO_ZYX      CGM_XFORM3D::ERotationOrder::ZYX

#define CGM_PLANE_XY    CGM_XFORM3D::EPlane::XY
#define CGM_PLANE_YZ    CGM_XFORM3D::EPlane::YZ
#define CGM_PLANE_ZX    CGM_XFORM3D::EPlane::ZX

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END