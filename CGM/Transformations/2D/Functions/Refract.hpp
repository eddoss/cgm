#pragma once


#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Transformations/Common.hpp>
#include <CGM/Transformations/2D/ModuleGlobals.hpp>
#include <CGM/Utils/TypeTraits.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/**
 * Refracts the vector through a plane.
 * @param vector Vector to reflect.
 * @param axisNormal Axis normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr enable_if_floating<T, void>
refract(Vector<2,T>& vector, const Vector<2,T>& axisNormal, T ior);

/**
 * Refracts the vector through a plane.
 * @param vector Vector to reflect.
 * @param axisNormal Axis normal.
 * @param ior Index of refraction.
 * @return Copy of refracted vector.
 */
template<typename T>
constexpr enable_if_floating<T, Vector<2,T>>
refracted(const Vector<2,T>& vector, const Vector<2,T>& axisNormal, T ior);

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "Refract.inl"
