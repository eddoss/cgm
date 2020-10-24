#pragma once


#include <cstdint>
#include <CGM/Global.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Primitive types */
/* ####################################################################################### */

using int8  = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8  = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using float32 = float;
using float64 = double;

/* ####################################################################################### */
/* Common constants */
/* ####################################################################################### */

#ifdef CGMATH_USE_DOUBLE_PRECISION
    using FLOAT = double;
    #define CGM_BIG_NUMBER                  1.79768e+308
    #define CGM_SMALL_NEGATIVE_NUMBER       2.22506e-308
    #define CGM_SMALL_POSITIVE_NUMBER       0.0000000000001
    #define CGM_PI                          3.1415926535897
    #define CGM_PI2                         6.2831853071795
    #define CGM_PI_HALF                     1.5707963267948
    #define CGM_PI_INVERTED                 0.3183098861837
    #define CGM_EULER_NUMBER                2.7182818284590
    #define CGM_GOLDEN_RATIO                1.6180339887498
    #define CGM_TOLERANCE                   0.0000000000001
    #define CGM_TO_DEGREES                  57.295779513000
    #define CGM_TO_RADIANS                  0.0174532925199
#else
    using FLOAT = float;
    #define CGM_BIG_NUMBER                  3.40282e+38f
    #define CGM_SMALL_POSITIVE_NUMBER       0.00000001f
    #define CGM_SMALL_NEGATIVE_NUMBER       1.17548e-38f
    #define CGM_PI                          3.14159265f
    #define CGM_PI2                         6.28318530f
    #define CGM_PI_HALF                     1.57079632f
    #define CGM_PI_INVERTED                 0.31830988f
    #define CGM_EULER_NUMBER                2.71828182f
    #define CGM_GOLDEN_RATIO                1.61803398f
    #define CGM_TOLERANCE                   0.00000001f
    #define CGM_TO_DEGREES                  57.2957790f
    #define CGM_TO_RADIANS                  0.01745320f
#endif

/* ####################################################################################### */
/* Numbers comparison */
/* ####################################################################################### */

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(T A, T B, T tolerance=CGM_TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,bool>
eq(T A, T B);

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(T A, T B, T tolerance=CGM_TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,bool>
neq(T A, T B);

/* ####################################################################################### */
/* Number converters */
/* ####################################################################################### */

/**
 * Convert number from type A to type B.
 */
template<typename AT, typename BT>
constexpr CGM_FORCEINLINE enable_if_floating_or_integral<AT,AT>
number(BT value);

/**
 * Create zero value number with given type.
 * @return Zero with given type.
 */
template<typename T>
constexpr enable_if_floating_or_integral<T,T>
zero = static_cast<T>(0);

/* ####################################################################################### */
/* Angle converters */
/* ####################################################################################### */

/**
 * Convert degrees to radians.
 * @param angle Angle to convert.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
radians(T angle);

/**
 * Convert radians to degrees.
 * @param angle Angle to convert.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
degrees(T angle);

/* ####################################################################################### */
/* Value remapping */
/* ####################################################################################### */

/**
 * Returns value clamped between min and max.
 * @tparam T Type must have next traits: less and greater comparable.
 * @param value Value to clamp.
 * @param min Minimum of range.
 * @param max Maximum of range.
 * @return clamped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
clamp(const T& value, T min, T max);

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
constexpr CGM_FORCEINLINE T
fit(T value, T omin, T omax, T nmin, T nmax);

/**
 * Takes the value in the range [0,1] and shifts it to the corresponding value in a new range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
fit01(T value, T newMin, T newMax);

/**
 * Takes the value in the range [1,0] and shifts it to the corresponding value in a new range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
fit10(T value, T newMin, T newMax);

/**
 * Takes the value in the range [-1,1] and shifts it to the corresponding value in a new range.
 * @param value Value to remap.
 * @param newMin New range min value.
 * @param newMax New range max value.
 * @param remapped value.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
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
constexpr CGM_FORCEINLINE T
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
constexpr CGM_FORCEINLINE T
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
constexpr CGM_FORCEINLINE T
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
constexpr CGM_FORCEINLINE T
ufit11(T value, T newMin, T newMax);

/* ####################################################################################### */
/* Interpolations */
/* ####################################################################################### */

/**
 * Performs linear interpolation between the values.
 * @param A First value.
 * @param B Second value.
 * @param bias Interpolation coefficient.
 * @return Interpolated value.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
lerp(T A, T B, T bias);

/**
 * Performs a 2D linear interpolation between 4 values.
 * BiasX and biasY must laid out in [0,1] range.
 * @tparam T Type must have next traits: comparable, binary plus and minus, binary multiply
 * @param Ax First point X value.
 * @param Ay First point Y value.
 * @param Bx Second point X value.
 * @param By Second point Y value.
 * @param biasX X-direction interpolation coefficient.
 * @param biasY Y-direction interpolation coefficient.
 * @return Interpolated value.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
blerp(T Ax, T Ay, T Bx, T By, T biasX, T biasY);


#include "Common.inl"


CGM_NAMESPACE_END
