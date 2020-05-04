#ifndef MATH3D_XFORM_3D_FUNCTIONS_SCALE_HPP
#define MATH3D_XFORM_3D_FUNCTIONS_SCALE_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Cartesian.hpp>
#include <Math3D/XForm/3D/Pivot.hpp>
#include <Math3D/XForm/3D/Transforms.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

using MATH3D_XYZ_NAMESPACE::EAxes3D;

/**
 * Scales 3D vector.
 * @tparam Space In which space to transform.
 * @param vector Vector to scale.
 * @param value How much to scale.
 */
 template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Scales 3D vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value, const Vector<3,T>& pivotPoint);

/**
 * Scales 3D vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivot Pivot point.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value, const Pivot<3,T>& pivot);

/**
 * Scales 3D vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Scales 3D transform matrix.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Scales 3D transform matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value, const Vector<3,T>& pivotPoint);

/**
 * Scales 3D transform matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value, const Pivot<3,T>& pivot);

/**
 * Scales 3D transform matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_FUNCTIONS_SCALE_HPP