#pragma once


#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Functions/Comparison.hpp>
#include <CGM/Interpolations/ModuleGlobals.hpp>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Utils/TypeTraits.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

/**
 * Returns value clamped between 'a' and 'b'. It does not matter 'a' > 'b' or vice versa.
 * @param value Value to clamp.
 * @param a Range begin.
 * @param b Range end.
 * @return Clamped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,T>
clamp(T value, T a, T b);

/**
 * Returns value clamped between 0 and 1.
 * @param value Value to clamp.
 * @return Clamped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,T>
clamp01(T value);

/**
 * Returns value clamped between -1 and 1.
 * @param value Value to clamp.
 * @return Clamped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
clamp11(T value);

/* ####################################################################################### */
/* Vectors */
/* ####################################################################################### */

/**
 * Returns vector clamped between 'a' and 'b'. It does not matter 'a' > 'b' or vice versa.
 * @param value Vector to vector.
 * @param a Range begin.
 * @param b Range end.
 * @return clamped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,Vector<D,T>>
clamp(const Vector<D,T>& value, const Vector<D,T>& a, const Vector<D,T>& b);

/**
 * Returns vector clamped between 0 and 1.
 * @param value Vector to vector.
 * @return clamped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,Vector<D,T>>
clamp01(const Vector<D,T>& value);

/**
 * Returns vector clamped between -1 and 1.
 * @param value Vector to vector.
 * @return clamped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
clamp11(const Vector<D,T>& value);

CGM_NAMESPACE_END


#include "Clamp.inl"
