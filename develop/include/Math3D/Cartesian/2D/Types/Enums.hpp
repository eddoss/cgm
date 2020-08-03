#pragma once


#include <Math3D/Global.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/**
 * Cartesian 2D axes enum.
 */
enum class EAxes
{
    X = 0,  ///< X axis.
    Y       ///< Y axis.
};

/* --------------------------------------------------------------------------------------- */

/**
 * Describe 2D basis base.
 */
enum class EBasisBase
{
    Matrix2 = 0,    /**< Based on 2x2 matrix and position. */
    Matrix3,        /**< Based on 2x2 matrix, position store in matrix. */
};

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END