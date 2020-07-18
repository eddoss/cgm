#ifndef MATH3D_XYZ_FUNCTIONS_ORIENTATION_HPP
#define MATH3D_XYZ_FUNCTIONS_ORIENTATION_HPP


#include <tuple>
#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Types/Enums.hpp>
#include <Math3D/Cartesian/3D/Types/Typedefs.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

/**
 * Make axes tuple from X,Y,Z.
 * @param x X axis.
 * @param y Y axis.
 * @param z Z axis.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Make axes tuple from 3x3 orientation matrix.
 * @param orientation 3x3 orientation matrix to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<3,3,T>& orientation);

/**
 * Make axes tuple from orientation quaternion.
 * @param orientation Orientation quaternion to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Quaternion<T>& orientation);

/**
 * Make axes tuple from space.
 * @param space Space to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<4,4,T>& space);

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

/**
 * Pack orientation axes to 3x3 orientation matrix.
 * @param axes Axes to pack.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Make orientation axes to 3x3 orientation matrix.
 * @param axes Axes to pack.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
orientationMatrix(const AxesTuple<T>& axes);

/**
 * Convert orientation quaternion to 3x3 orientation matrix.
 * @param orientation Orientation quaternion to convert.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Quaternion<T>& orientation);

/**
 * Extract 3x3 orientation matrix from 4x4 space matrix.
 * @param space Space to extract axes from.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Matrix<4,4,T>& space);

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

/**
 * Convert orientation axes to orientation quaternion.
 * @param x X orientation axes.
 * @param y Y orientation axes.
 * @param z Z orientation axes.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr Quaternion<T>
orientationQuaternion(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Convert orientation axes to orientation quaternion.
 * @param axes Axes to make from.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const AxesTuple<T>& axes);

/**
 * Convert 3x3 orientation matrix to orientation quaternion.
 * @param orientation Orientation matrix to convert from.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<3,3,T>& orientation);

/**
 * Extract 3x3 orientation matrix and convert it to orientation quaternion.
 * @param space 4x4 space matrix to extract from.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<4,4,T>& space);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Orientation.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_UTILS_HPP
