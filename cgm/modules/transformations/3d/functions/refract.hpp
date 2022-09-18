#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>


CGM_NAMESPACE_BEGIN

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
constexpr enable_if_floating<T, void>
refract(Vector<3,T>& vector, T ior);

/**
 * Refracts the vector through a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr enable_if_floating<T, void>
refract(Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior);

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
constexpr enable_if_floating<T, Vector<3,T>>
refracted(const Vector<3,T>& vector, T ior);

/**
 * Refracts the vector through a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 * @return Copy of refracted vector.
 */
template<typename T>
constexpr enable_if_floating<T, Vector<3,T>>
refracted(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior);

CGM_NAMESPACE_END


#include "refract.inl"
