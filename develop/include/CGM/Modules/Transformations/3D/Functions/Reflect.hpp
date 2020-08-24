#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Reflects vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal);

/**
 * Reflects vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Reflects 3x3 matrix from a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Reflects 4x4 matrix from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal);

/**
 * Reflects 4x4 matrix from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Reflects pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal);

/**
 * Reflects pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Reflects vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @return Reflected copy of vector.
 */
template<typename T>
constexpr Vector<3,T>
reflected(const Vector<3,T>& vector, const Vector<3,T>& planeNormal);

/**
 * Reflects vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @return Reflected copy of vector.
 */
template<typename T>
constexpr Vector<3,T>
reflected(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Reflects 3x3 matrix from a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @return Reflected copy of matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal);

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Reflects 4x4 matrix from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @return Reflected copy of matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal);

/**
 * Reflects 4x4 matrix from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @return Reflected copy of matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Reflects pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @return Reflected copy of pivot.
 */
template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, Vector<3,T>& planeNormal);

/**
 * Reflects pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @return Reflected copy of pivot.
 */
template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Reflect.hpp>
