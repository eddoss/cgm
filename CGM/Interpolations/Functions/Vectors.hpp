#pragma once


#include <CGM/Common.hpp>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Interpolations/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Remapping */
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

/**
 * Takes the vector in one range and shifts it to the corresponding vector in a new range.
 * Does not clamp vector to the given range.
 * @param value Value to remap.
 * @param omin Old range min vector.
 * @param omax Old range max vector.
 * @param nmin New range min vector.
 * @param nmax New range max vector.
 * @param remapped value.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit(const Vector<D,T>& value, const Vector<D,T>& omin, const Vector<D,T>& omax, const Vector<D,T>& nmin, const Vector<D,T>& nmax);

/**
 * Takes the value in the range [0,1] and shifts it to the corresponding vector in a new range.
 * Does not clamp vector to the given range.
 * @param value Vector to remap.
 * @param newMin New range min vector.
 * @param newMax New range max vector.
 * @param remapped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit01(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax);

/**
 * Takes the vector in the range [1,0] and shifts it to the corresponding vector in a new range.
 * Does not clamp vector to the given range.
 * @param value Vector to remap.
 * @param newMin New range min vector.
 * @param newMax New range max vector.
 * @param remapped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit10(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax);

/**
 * Takes the value in the range [-1,1] and shifts it to the corresponding value in a new range.
 * Does not clamp vector to the given range.
 * @param value Vector to remap.
 * @param newMin New range min vector.
 * @param newMax New range max vector.
 * @param remapped vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit11(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax);

/* ####################################################################################### */
/* Interpolations */
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
lerp(const Vector<D,T>& a, const Vector<D,T>& b, const Vector<D,T>& bias);

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

CGM_NAMESPACE_END


#include "Vector.inl"
