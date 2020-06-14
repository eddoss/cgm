#ifndef MATH3D_XY_FUNCTIONS_ORIENTATION_HPP
#define MATH3D_XY_FUNCTIONS_ORIENTATION_HPP


#include <tuple>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

template<typename T> using AxesTuple = std::tuple<Vector<2,T>, Vector<2,T>>;

/**
 * Extract X,Y axes from orientation matrix.
 * @param orientation 2x2 orientation matrix to extract from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<2,2,T>& orientation);

/**
 * Extract X,Y axes from basis.
 * @param space Space to extract from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<3,3,T>& space);

/**
 * Convert orientation axes to 2x2 orientation matrix.
 * @param x X orientation axes.
 * @param y Y orientation axes.
 * @return Orientation matrix.
 */
template<typename T>
constexpr Matrix<2,2,T>
orientationMatrix(const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Convert orientation axes to 2x2 orientation matrix.
 * @param x X orientation axes.
 * @param y Y orientation axes.
 * @return Orientation matrix.
 */
template<typename T>
constexpr Matrix<2,2,T>
orientationMatrix(const AxesTuple<T>& axes);

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Orientation.hpp>


#endif // MATH3D_XY_FUNCTIONS_UTILS_HPP
