#ifndef MATH3D_XY_FUNCTIONS_SPACE_HPP
#define MATH3D_XY_FUNCTIONS_SPACE_HPP


#include <tuple>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/**
 * Creates 2D basis from axes and position.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param position Basis position.
 * @return 2D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
space(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position);

/**
 * Creates 2D basis from orientation matrix and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 2D basis represented by 3x3 matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
space(const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Space.hpp>


#endif // MATH3D_XY_FUNCTIONS_UTILS_HPP
