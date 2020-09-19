#pragma once


#include <type_traits>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Types/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Axes.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

/**
 * Make axes struct from X,Y,Z.
 * @param x X axis.
 * @param y Y axis.
 * @param z Z axis.
 * @return Axes struct.
 */
template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Make axes struct from 3x3 orientation matrix.
 * @param orientation 3x3 orientation matrix to extract axes from.
 * @return Axes struct.
 */
template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Matrix<3,3,T>& orientation);

/**
 * Make axes struct from orientation quaternion.
 * @param orientation Orientation quaternion to extract axes from.
 * @return Axes struct.
 */
template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Quaternion<T>& orientation);

/**
 * Make axes struct from space.
 * @param space Space to extract axes from.
 * @return Axes struct.
 */
template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
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
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Make orientation axes to 3x3 orientation matrix.
 * @param axes Axes to pack.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Axes<T>& axes);

/**
 * Convert orientation quaternion to 3x3 orientation matrix.
 * @param orientation Orientation quaternion to convert.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Quaternion<T>& orientation);

/**
 * Extract 3x3 orientation matrix from 4x4 space matrix.
 * @param space Space to extract axes from.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
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
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const Axes<T>& axes);

/**
 * Convert 3x3 orientation matrix to orientation quaternion.
 * @param orientation Orientation matrix to convert from.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<3,3,T>& orientation);

/**
 * Extract 3x3 orientation matrix and convert it to orientation quaternion.
 * @param space 4x4 space matrix to extract from.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<4,4,T>& space);

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Cartesian/3D/Functions/Orientation.hpp>