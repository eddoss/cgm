#ifndef MATH3D_XYZ_FUNCTIONS_BASIS_CREATORS_HPP
#define MATH3D_XYZ_FUNCTIONS_BASIS_CREATORS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Quaternion/Functions.hpp>
#include <Math3D/Core/Quaternion/Operators.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* 2D */
/* ####################################################################################### */

/**
 * Creates 2D basis manually.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @return 2D basis represented by 2x2 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
basis2D(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Creates 2D basis manually.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param position Basis position.
 * @return 2D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
basis2D(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position);

/**
 * Creates 2D basis from orientation and position.
 * @param orientation Basis orientation.
 * @param position Basis position.
 * @return 2D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
basis2D(const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

/* ####################################################################################### */
/* 3D */
/* ####################################################################################### */

/**
 * Creates 3D basis manually.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param z Basis Z axis.
 * @return 3D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
basis3D(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Creates 3D basis manually.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param z Basis Z axis.
 * @param position Basis position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
basis3D(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

/**
 * Creates 3D basis from orientation and position.
 * @param orientation Basis orientation.
 * @param position Basis position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
basis3D(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Creates 3D basis from Quaternion.
 * @param orientation Basis orientation.
 * @return 3D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
basis3D(const Quaternion<T>& orientation);

/**
 * Creates 3D basis from Quaternion.
 * @param orientation Basis orientation.
 * @param position Basis position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
basis3D(const Quaternion<T>& orientation, const Vector<3,T>& position);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/Functions/BasisCreators.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_BASIS_CREATORS_HPP
