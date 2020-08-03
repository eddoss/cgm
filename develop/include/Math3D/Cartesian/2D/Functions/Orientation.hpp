#pragma once


#include <tuple>
#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Cartesian/2D/Types/Enums.hpp>
#include <Math3D/Cartesian/2D/Types/Typedefs.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

/**
 * Make axes tuple from X,Y.
 * @param x X axis.
 * @param y Y axis.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Extract orientation axes from Space tuple.
 * @param space Space tuple.
 * @return Tuple of orientation axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const SpaceTuple<T>& space);

/**
 * Make axes tuple from 2x2 orientation matrix.
 * @param orientation 2x2 orientation matrix to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<2,2,T>& orientation);

/**
 * Make axes tuple from space.
 * @param space Space to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

/**
 * Pack orientation axes to 2x2 orientation matrix.
 * @param axes Axes to pack.
 * @return 2x2 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Make orientation axes to 2x2 orientation matrix.
 * @param axes Axes to pack.
 * @return 2x2 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
orientationMatrix(const AxesTuple<T>& axes);

/**
 * Extract orientation matrix from Space tuple.
 * @param space Space tuple.
 * @return Tuple of orientation axes.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
orientationMatrix(const SpaceTuple<T>& space);

/**
 * Extract 2x2 orientation matrix from 3x3 space matrix.
 * @param space Space to extract axes from.
 * @return 2x2 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Matrix<3,3,T>& space);

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Orientation.hpp>