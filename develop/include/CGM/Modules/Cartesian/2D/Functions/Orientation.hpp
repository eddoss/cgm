#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/ModuleGlobals.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Typedefs.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

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
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Extract orientation axes from Space tuple.
 * @param space Space tuple.
 * @return Tuple of orientation axes.
 */
template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const SpaceTuple<T>& space);

/**
 * Make axes tuple from 2x2 orientation matrix.
 * @param orientation 2x2 orientation matrix to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<2,2,T>& orientation);

/**
 * Make axes tuple from space.
 * @param space Space to extract axes from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
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
orientationMatrix(const AxesTuple<T>& axes);

/**
 * Extract orientation matrix from Space tuple.
 * @param space Space tuple.
 * @return Tuple of orientation axes.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const SpaceTuple<T>& space);

/**
 * Extract 2x2 orientation matrix from 3x3 space matrix.
 * @param space Space to extract axes from.
 * @return 2x2 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Matrix<3,3,T>& space);

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Cartesian/2D/Functions/Orientation.hpp>