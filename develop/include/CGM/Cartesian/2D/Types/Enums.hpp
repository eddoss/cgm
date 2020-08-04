#pragma once


#include <CGM/Cartesian/2D/ModuleGlobals.hpp>


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

/* --------------------------------------------------------------------------------------- */

/**
 * Describe 2D basis base.
 */
enum class EBasisBase
{
    Matrix2 = 0,    /**< Based on 2x2 matrix and position. */
    Matrix3,        /**< Based on 2x2 matrix, position store in matrix. */
};

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END