#pragma once


#include <Math3D/Global.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

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
 * Describe 2D basis base.
 */
enum class EBasisBase
{
    Matrix3 = 0,    /**< Based on 3x3 matrix and position. */
    Matrix4,        /**< Based on 4x4 matrix, position store in matrix. */
    Quaternion      /**< Based on quaternion and position. */
};

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END