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
 * Refracts the vector through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param vector Vector to reflect.
 * @param ior Index of refraction.
 */
template<EPlane Plane, typename T>
constexpr void
refract(Vector<3,T>& vector, T ior);

/**
 * Refracts the vector through a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Refracts the 3x3 matrix through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param matrix Matrix to reflect.
 * @param ior Index of refraction.
 */
template<EPlane Plane, ESpace Space = ESpace::World, typename T>
constexpr void
refract(Matrix<3,3,T>& matrix, T ior);

/**
 * Refracts the 3x3 matrix through a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
refract(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Refracts the 4x4 matrix through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param matrix Matrix to reflect.
 * @param ior Index of refraction.
 */
template<EPlane Plane, ESpace Space = ESpace::World, typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, T ior);

/**
 * Refracts the 4x4 matrix through a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Refracts the pivot through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param pivot Pivot to reflect.
 * @param ior Index of refraction.
 */
template<EPlane Plane, typename T>
constexpr void
refract(Pivot<T>& pivot, T ior);

/**
 * Refracts the pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Pivot<T>& pivot, Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Refracts the vector through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param vector Vector to reflect.
 * @param ior Index of refraction.
 * @return Copy of refracted vector.
 */
template<EPlane Plane, typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, T ior);

/**
 * Refracts the vector through a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted vector.
 */
template<typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Refracts the 3x3 matrix through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param matrix Matrix to reflect.
 * @param ior Index of refraction.
 * @return Copy of refracted matrix.
 */
template<EPlane Plane, ESpace Space = ESpace::World, typename T>
constexpr Matrix<3,3,T>
refracted(const Matrix<3,3,T>& matrix, T ior);

/**
 * Refracts the 3x3 matrix through a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
refracted(const Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Refracts the 4x4 matrix through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param matrix Matrix to reflect.
 * @param ior Index of refraction.
 * @return Copy of refracted matrix.
 */
template<EPlane Plane, ESpace Space = ESpace::World, typename T>
constexpr Matrix<4,4,T>
refracted(const Matrix<4,4,T>& matrix, T ior);

/**
 * Refracts the 4x4 matrix through a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
refracted(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Refracts the pivot through a default Cartesian plane.
 * @tparam Plane Default Cartesian plane.
 * @param pivot Pivot to reflect.
 * @param ior Index of refraction.
 * @return Copy of refracted pivot.
 */
template<EPlane Plane, typename T>
constexpr Pivot<T>
refracted(const Pivot<T>& pivot, T ior);

/**
 * Refracts the pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted pivot.
 */
template<typename T>
constexpr Pivot<T>
refracted(const Pivot<T>& pivot, Vector<3,T>& planeNormal, T ior);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Refract.hpp>
