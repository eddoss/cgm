#pragma once


#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


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

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END