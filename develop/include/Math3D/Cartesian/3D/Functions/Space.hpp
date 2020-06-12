#ifndef MATH3D_XYZ_FUNCTIONS_SPACE_HPP
#define MATH3D_XYZ_FUNCTIONS_SPACE_HPP


#include <tuple>
#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>
#include <Math3D/Cartesian/3D/Functions/Orientation.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/**
 * Creates 3D space from axes and position.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param z Basis Z axis.
 * @param position Basis position.
 * @return 3D space represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
space(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

/**
 * Creates 3D space from orientation matrix and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
space(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Creates 3D space from Quaternion and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 3D Space represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
space(const Quaternion<T>& orientation, const Vector<3,T>& position);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Space.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_UTILS_HPP
