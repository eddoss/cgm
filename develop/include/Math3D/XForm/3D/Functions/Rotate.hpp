#ifndef MATH3D_XFORM_3D_FUNCTIONS_ROTATE_HPP
#define MATH3D_XFORM_3D_FUNCTIONS_ROTATE_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Axis.hpp>
#include <Math3D/Core/Cartesian.hpp>
#include <Math3D/XForm/3D/Pivot.hpp>
#include <Math3D/XForm/3D/Transforms.hpp>
#include <Math3D/XForm/3D/EulerAngles.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

using MATH3D_XYZ_NAMESPACE::EAxes3D;

/**
 * Rotates 3D vector around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angle Rotation angle.
 */
template<EAxes3D Axis, typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, T angle);

/**
 * Rotates 3D vector by Euler angles.
 * @param vector Vector to rotate.
 * @param eulerAngles Euler angles.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const EulerAngles<T>& eulerAngles);

/**
 * Rotates 3D vector around arbitrary axis.
 * @param vector Vector to rotate.
 * @param axis Rotation axis (contain axis position, direction).
 * @param angle Rotation angle.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const Axis<3,T>& axis);

/**
 * Rotates 3D vector around each axis of pivot on angle contained in "values".
 * @param vector Vector to rotate.
 * @param values Rotation angles (angle per pivot axis).
 * @param pivot Rotation pivot.
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<3,T>& pivot, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotates 3D vector by Quaternion.
 * @param vector Vector to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Rotates 3D vector around each axis of pivot on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Rotates 3D orientation matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 */
template<EAxes3D Axis, ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle);

/**
 * Rotates 3D orientation matrix by Euler angles.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param eulerAngles Euler angles.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const EulerAngles<T>& eulerAngles);

/**
 * Rotates 3D orientation matrix around axis.
 * @tparam Space In which space to transform.
 * @param axis Rotation axis (contain axis position, direction).
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle, const Axis<3,T>& axis);

/**
 * Rotates 3D orientation matrix around each axis of pivot on angle contained in "values".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param values Rotation angles (angle per pivot axis).
 * @param pivot Rotation pivot.
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<3,T>& pivot, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotates 3D orientation matrix by Quaternion.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 3D orientation matrix around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<3,T>& transforms);

/**
 * Rotates 3D transformation matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 */
template<EAxes3D Axis, ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle);

/**
 * Rotates 3D transformation matrix by Euler angles.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param eulerAngles Euler angles.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const EulerAngles<T>& eulerAngles);

/**
 * Rotates 3D transformation matrix around axis.
 * @tparam Space In which space to transform.
 * @param axis Rotation axis (contain axis position, direction).
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle, const Axis<3,T>& axis);

/**
 * Rotates 3D transformation matrix around each axis of pivot on angle contained in "values".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param values Rotation angles (angle per pivot axis).
 * @param pivot Rotation pivot.
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<3,T>& pivot, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotates 3D transformation matrix by Quaternion.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 3D transformation matrix around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

/**
 * Rotates 3D pivot around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param pivot Pivot to rotate.
 * @param angle Rotation angle.
 */
template<EAxes3D Axis, typename T>
constexpr FORCEINLINE void
rotate(Pivot<3,T>& pivot, T angle);

/**
 * Rotates 3D pivot by Euler angles.
 * @param pivot Pivot to rotate.
 * @param eulerAngles Euler angles.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Pivot<3,T>& pivot, const EulerAngles<T>& eulerAngles);

/**
 * Rotates 3D pivot around arbitrary axis.
 * @param pivot Pivot to rotate.
 * @param axis Rotation axis (contain axis position, direction).
 * @param angle Rotation angle.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Pivot<3,T>& pivot, T angle, const Axis<3,T>& axis);

/**
 * Rotates 3D pivot around each axis of pivot on angle contained in "values".
 * @param pivot Pivot to rotate.
 * @param values Rotation angles (angle per pivot axis).
 * @param rotationOrder Rotation order. By default is "XYZ".
 * @param rotationPivot Rotation pivot.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Pivot<3,T>& pivot, const Vector<3,T>& values, const Pivot<3,T>& rotationPivot, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotates 3D pivot by Quaternion.
 * @param pivot Pivot to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Pivot<3,T>& pivot, const Quaternion<T>& quaternion);

/**
 * Rotates 3D pivot around each axis of pivot on angle contained in "transform.rotations".
 * @param pivot Pivot to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Pivot<3,T>& pivot, const Transforms<3,T>& transforms);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_FUNCTIONS_ROTATE_HPP