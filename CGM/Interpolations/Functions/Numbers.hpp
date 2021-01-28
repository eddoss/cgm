#pragma once


#include <CGM/Common.hpp>
#include <CGM/Interpolations/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Remapping */
/* ####################################################################################### */

/**
 * Returns value clamped between 'a' and 'b'. It does not matter 'a' > 'b' or vice versa.
 * @param value Value to clamp.
 * @param a Range begin.
 * @param b Range end.
 * @return clamped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,T>
clamp(T value, T a, T b);

/**
 * Takes the value in one range and shifts it to the corresponding value in a new range.
 * @param value Value to remap.
 * @param omin Old range min value.
 * @param omax Old range max value.
 * @param nmin New range min value.
 * @param nmax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit(T value, T omin, T omax, T nmin, T nmax);

/**
 * Takes the value in the range [0,1] and shifts it to the corresponding value in a new range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit01(T value, T newMin, T newMax);

/**
 * Takes the value in the range [1,0] and shifts it to the corresponding value in a new range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit10(T value, T newMin, T newMax);

/**
 * Takes the value in the range [-1,1] and shifts it to the corresponding value in a new range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit11(T value, T newMin, T newMax);

/**
 * Takes the value in one range and shifts it to the corresponding value in a new range.
 * Does not clamp values to the given range.
 * @param value Value to remap.
 * @param omin Old range min value.
 * @param omax Old range max value.
 * @param nmin New range min value.
 * @param nmax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit(T value, T omin, T omax, T nmin, T nmax);

/**
 * Takes the value in the range [0,1] and shifts it to the corresponding value in a new range.
 * Does not clamp values to the given range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit01(T value, T newMin, T newMax);

/**
 * Takes the value in the range [1,0] and shifts it to the corresponding value in a new range.
 * Does not clamp values to the given range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit10(T value, T newMin, T newMax);

/**
 * Takes the value in the range [-1,1] and shifts it to the corresponding value in a new range.
 * Does not clamp values to the given range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit11(T value, T newMin, T newMax);

/* ####################################################################################### */
/* Interpolations */
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

CGM_NAMESPACE_END


#include "Numbers.inl"
