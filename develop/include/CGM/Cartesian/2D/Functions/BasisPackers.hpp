#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/Core/Vector.hpp>
#include <CGM/Core/Matrix.hpp>
#include <CGM/Cartesian/2D/Types/Typedefs.hpp>
#include <CGM/Cartesian/2D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/**
 * Creates 2D space from axes and position.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param position Basis position.
 * @return 2D space represented by 3x3 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
packBasis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position);

/**
 * Creates 2D space from orientation matrix and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 2D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
packBasis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

/**
 * Unpack 3x3 matrix to X,Y axes and position.
 * @param matrix Matrix to unpack.
 * @return Tuple of space orientation axes and space position.
 */
template<typename T>
constexpr FORCEINLINE SpaceTuple<T>
unpackBasis(const Matrix<3,3,T>& matrix);

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <private/CGM/Cartesian/2D/Functions/BasisPackers.hpp>
