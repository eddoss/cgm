#ifndef MATH3D_XYZ_FUNCTIONS_RAW_BASIS_HPP
#define MATH3D_XYZ_FUNCTIONS_RAW_BASIS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/**
 * Creates 3D basis manually.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param z Basis Z axis.
 * @return 3D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
rawBasis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

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
rawBasis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

/**
 * Creates 3D basis from orientation and position.
 * @param orientation Basis orientation.
 * @param position Basis position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
rawBasis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Creates 3D basis from Quaternion.
 * @param orientation Basis orientation.
 * @return 3D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
rawBasis(const Quaternion<T>& orientation);

/**
 * Creates 3D basis from Quaternion.
 * @param orientation Basis orientation.
 * @param position Basis position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
rawBasis(const Quaternion<T>& orientation, const Vector<3,T>& position);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Basis.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_RAW_BASIS_HPP
