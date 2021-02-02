#pragma once


#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Functions/Comparison.hpp>
#include <CGM/Interpolations/ModuleGlobals.hpp>
#include <CGM/Core/Types/Vector.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

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

/* ####################################################################################### */
/* Vectors */
/* ####################################################################################### */

/**
 * Takes the vector in one range and shifts it to the corresponding vector in a new range.
 * @param value Vector to remap.
 * @param omin Old range min vector.
 * @param omax Old range max vector.
 * @param nmin New range min vector.
 * @param nmax New range max vector.
 * @param remapped value.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit(const Vector<D,T>& value, const Vector<D,T>& omin, const Vector<D,T>& omax, const Vector<D,T>& nmin, const Vector<D,T>& nmax);

/**
 * Takes the vector in the range [0,1] and shifts it to the corresponding vector in a new range.
 * @param value Vector to remap.
 * @param newMin New range min vector.
 * @param newMax New range max vector.
 * @param remapped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit01(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax);

/**
 * Takes the vector in the range [1,0] and shifts it to the corresponding vector in a new range.
 * @param value Vector to remap.
 * @param newMin New range min vector.
 * @param newMax New range max vector.
 * @param remapped value.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit10(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax);

/**
 * Takes the vector in the range [-1,1] and shifts it to the corresponding vector in a new range.
 * @param value Vector to remap.
 * @param newMin New range min vector.
 * @param newMax New range max vector.
 * @param remapped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit11(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax);

CGM_NAMESPACE_END


#include "Fit.inl"
