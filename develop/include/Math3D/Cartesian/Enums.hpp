#ifndef MATH3D_XYZ_ENUMS_HPP
#define MATH3D_XYZ_ENUMS_HPP


#include <Math3D/Global.hpp>

MATH3D_NAMESPACE_BEGIN

/**
 * Describe space.
 */
enum class ESpace
{
    Local = 0,    /**< Local space. */
    World         /**< World space. */
};

MATH3D_NAMESPACE_END

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/**
 * Cartesian 2D axes enum.
 */
enum class EAxes
{
    X = 0,  ///< X axis.
    Y,      ///< Y axis.
};

/**
 * Describe 2D basis base.
 */
enum class EBasisBase
{
    Matrix2 = 0,    /**< Based on 2x2 matrix and position. */
    Matrix3         /**< Based on 3x3 matrix, position store in matrix. */
};

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

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

/**
 * Cartesian planes enum.
 */
enum class EPlane
{
    XY = 0,  ///< XY plane.
    XZ,      ///< XZ plane.
    YZ       ///< YZ plane.
};

/**
 * Describe 2D basis base.
 */
enum class EBasisBase
{
    Matrix3 = 0,    /**< Based on 3x3 matrix and position. */
    Matrix4,        /**< Based on 3x3 matrix, position store in matrix. */
    Quaternion      /**< Based on quaternion and position. */
};

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XYZ_ENUMS_HPP
