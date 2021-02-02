#pragma once


#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Functions/Comparison.hpp>
#include <CGM/Interpolations/ModuleGlobals.hpp>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/Cartesian/3D/Functions/Quaternion.hpp>
#include <CGM/Cartesian/3D/Operators/Quaternion.hpp>
#include <CGM/Utils/TypeTraits.hpp>


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


#include "Interps.inl"
