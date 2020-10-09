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

#ifdef CGM_USE_DOUBLE_PRECISION
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


#include <CGM/Common.inl>


CGM_NAMESPACE_END
