#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/cartesian/3d/functions/orientation.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Reflects vector from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param vector Vector to reflect.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Vector<3,T>& vector);

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
 * Reflects 3x3 matrix from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param matrix Matrix to reflect.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix);

/**
 * Reflects 3x3 matrix from a plane.
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
 * Reflects 4x4 matrix from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param matrix Matrix to reflect.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix);

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
 * Reflects pivot from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param pivot Pivot to reflect.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Pivot<T>& pivot);

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
/* Axis (inplace) */
/* ####################################################################################### */

/**
 * Reflects arbitrary axis from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param arbitraryAxis Arbitrary axis to reflect.
 */
template<EPlane Plane, typename T>
constexpr CGM_FORCEINLINE void
reflect(Ray<T>& arbitraryAxis);

/**
 * Reflects arbitrary axis from a plane.
 * @param arbitraryAxis Arbitrary axis to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
reflect(Ray<T>& arbitraryAxis, const Vector<3,T>& planeNormal);

/**
 * Reflects arbitrary axis from a plane.
 * @param arbitraryAxis Arbitrary axis to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
reflect(Ray<T>& arbitraryAxis, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Reflects vector from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param vector Vector to reflect.
 * @return Reflected copy of vector.
 */
template<EPlane Plane, typename T>
constexpr Vector<3,T>
reflected(const Vector<3,T>& vector);

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
 * Reflects 3x3 matrix from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param matrix Matrix to reflect.
 * @return Reflected copy of matrix.
 */
template<EPlane Plane, typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix);

/**
 * Reflects 3x3 matrix from a plane.
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
 * Reflects 3x3 matrix from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param matrix Matrix to reflect.
 * @return Reflected copy of matrix.
 */
template<EPlane Plane, typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix);

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

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

/**
 * Reflects arbitrary axis from a default Cartesian plane.
 * @tparam Plane Cartesian plane to reflect from.
 * @param arbitraryAxis Arbitrary axis to reflect.
 * @return Reflected copy of axis.
 */
template<EPlane Plane, typename T>
constexpr CGM_FORCEINLINE Ray<T>
reflected(const Ray<T>& arbitraryAxis);

/**
 * Reflects arbitrary axis from a plane.
 * @param arbitraryAxis Arbitrary axis to reflect.
 * @param planeNormal Plane normal.
 * @return Reflected copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
reflected(const Ray<T>& arbitraryAxis, const Vector<3,T>& planeNormal);

/**
 * Reflects arbitrary axis from a plane.
 * @param arbitraryAxis Arbitrary axis to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @return Reflected copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
reflected(const Ray<T>& arbitraryAxis, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create reflection matrix (from a default Cartesian plane).
 * @tparam Plane Cartesian plane to reflect from.
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @return Reflection matrix.
 */
template<EPlane Plane, size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
reflectionMatrix();

/**
 * Create reflection matrix (from a plane).
 * @param planeNormal Plane normal.
 * @return Reflection matrix.
 */
template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
reflectionMatrix(const Vector<3,T>& planeNormal);

/**
 * Create reflection matrix (from a plane).
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @return Reflection matrix.
 */
template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
reflectionMatrix(const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

CGM_NAMESPACE_END


#include "reflect.inl"
