#pragma once


#include <CGM/Cartesian/3D/ModuleGlobals.hpp>


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

/* --------------------------------------------------------------------------------------- */

/**
 * Describe 3D basis base.
 */
enum class EBasisBase
{
    Matrix3 = 0,    /**< Based on 3x3 matrix and position. */
    Matrix4,        /**< Based on 4x4 matrix, position store in matrix. */
    Quaternion      /**< Based on quaternion and position. */
};

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END