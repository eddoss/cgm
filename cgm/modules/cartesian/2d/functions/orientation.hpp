#pragma once


#include <tuple>
#include <type_traits>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/cartesian/2d/types/axes.hpp>
#include <cgm/modules/cartesian/2d/functions/utils.hpp>
#include <cgm/modules/cartesian/2d/module_globals.hpp>


CGM_2D_NAMESPACE_BEGIN

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
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Make axes tuple from 2x2 orientation matrix.
 * @param orientation 2x2 orientation matrix to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Matrix<2,2,T>& orientation);

/**
 * Make axes tuple from space.
 * @param space Space to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
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
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Make orientation axes to 2x2 orientation matrix.
 * @param axes Axes to pack.
 * @return 2x2 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Axes<T>& axes);

/**
 * Extract orientation matrix from Space tuple.
 * @param space Space tuple.
 * @return Tuple of orientation axes.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Axes<T>& space);

/**
 * Extract 2x2 orientation matrix from 3x3 space matrix.
 * @param space Space to extract axes from.
 * @return 2x2 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Matrix<3,3,T>& space);

CGM_2D_NAMESPACE_END


#include "orientation.inl"
