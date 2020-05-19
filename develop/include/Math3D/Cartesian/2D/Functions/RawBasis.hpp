#ifndef MATH3D_XY_FUNCTIONS_BASIS_CREATORS_HPP
#define MATH3D_XY_FUNCTIONS_BASIS_CREATORS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/**
 * Creates 2D basis manually.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @return 2D basis represented by 2x2 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
rawBasis(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Creates 2D basis manually.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param position Basis position.
 * @return 2D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
rawBasis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position);

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Basis.hpp>


#endif // MATH3D_XY_FUNCTIONS_BASIS_CREATORS_HPP
