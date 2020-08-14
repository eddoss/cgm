#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/ModuleGlobals.hpp>


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
constexpr CGM_FORCEINLINE Matrix<3,3,T>
packBasis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position);

/**
 * Creates 2D space from orientation matrix and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 2D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
packBasis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Cartesian/2D/Functions/BasisPackers.hpp>
