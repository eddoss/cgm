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
/* Inplace */
/* ####################################################################################### */

/**
 * Refracts vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts 3x3 matrix from a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts 4x4 matrix from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Pivot<T>& pivot, Vector<3,T>& planeNormal, T ior);

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

/**
 * Refracts vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted vector.
 */
template<typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts 3x3 matrix from a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
refracted(const Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts 4x4 matrix from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
refracted(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts pivot through plane.
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
