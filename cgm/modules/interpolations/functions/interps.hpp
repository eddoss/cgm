#pragma once


#include <cgm/modules/primitives/functions/numbers.hpp>
#include <cgm/modules/primitives/functions/comparison.hpp>
#include <cgm/modules/interpolations/module_globals.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/cartesian/3d/types/quaternion.hpp>
#include <cgm/modules/cartesian/3d/functions/quaternion.hpp>
#include <cgm/modules/cartesian/3d/operators/quaternion.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

/**
 * Performs linear interpolation between the values.
 * @param a First value.
 * @param b Second value.
 * @param bias Interpolation coefficient.
 * @return Interpolated value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
lerp(T a, T b, T bias);

/**
 * Performs a bilinear interpolation between 4 values.
 * BiasA and biasA must laid out in [0,1] range.
 * @param A0 First value of first pair.
 * @param A1 Second value of first pair.
 * @param B0 First value of second pair.
 * @param B1 Second value of second pair.
 * @param biasU First interpolation coefficient.
 * @param biasV Second interpolation coefficient.
 * @return Interpolated value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
bilerp(T A0, T A1, T B0, T B1, T biasU, T biasV);

/* ####################################################################################### */
/* Vectors */
/* ####################################################################################### */

/**
 * Performs linear interpolation between the vectors.
 * @param a First vector.
 * @param b Second vector.
 * @param bias Interpolation coefficient.
 * @return Interpolated vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
lerp(const Vector<D,T>& a, const Vector<D,T>& b, T bias);

/**
 * Performs a bilinear interpolation between 4 vectors.
 * BiasA and biasA must laid out in [0,1] range.
 * @param A0 First vector of first pair.
 * @param A1 Second vector of first pair.
 * @param B0 First vector of second pair.
 * @param B1 Second vector of second pair.
 * @param biasU First interpolation coefficient.
 * @param biasV Second interpolation coefficient.
 * @return Interpolated vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
bilerp(const Vector<D,T>& A0, const Vector<D,T>& A1, const Vector<D,T>& B0, const Vector<D,T>& B1, T biasU, T biasV);

/* ####################################################################################### */
/* Quaternions */
/* ####################################################################################### */

/**
 * Performs spherical linear interpolation between two quaternions.
 * @param a First quaternion.
 * @param b Second quaternion.
 * @param bias Interpolation coefficient.
 * @return Interpolated quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
slerp(const Quaternion<T>& a, const Quaternion<T>& b, T bias);

CGM_NAMESPACE_END


#include "interps.inl"
