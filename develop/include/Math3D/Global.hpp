#ifndef MATH3D_GLOBAL_HPP
#define MATH3D_GLOBAL_HPP


#include <algorithm>


/* ####################################################################################### */
/* Common constants */
/* ####################################################################################### */

#if USE_DOUBLE_PRECISION
    using FLOAT = double;
    constexpr FLOAT BIG_NUMBER                  = 1.79768e+308;
    constexpr FLOAT SMALL_NEGATIVE_NUMBER       = 2.22506e-308;
    constexpr FLOAT SMALL_POSITIVE_NUMBER       = 0.0000000000001;
    constexpr FLOAT PI                          = 3.1415926535897;
    constexpr FLOAT PI2                         = 6.2831853071795;
    constexpr FLOAT PI_HALF                     = 1.5707963267948;
    constexpr FLOAT PI_INVERTED                 = 0.3183098861837;
    constexpr FLOAT EULER_NUMBER                = 2.7182818284590;
    constexpr FLOAT GOLDEN_RATIO                = 1.6180339887498;
    constexpr FLOAT TOLERANCE                   = 0.0000000000001;
    constexpr FLOAT TO_DEGREES                  = 57.295779513000;
    constexpr FLOAT TO_RADIANS                  = 0.0174532925199;
#else
    using FLOAT = float;
    constexpr FLOAT BIG_NUMBER                  = 3.40282e+38f;
    constexpr FLOAT SMALL_POSITIVE_NUMBER       = 0.00000001f;
    constexpr FLOAT SMALL_NEGATIVE_NUMBER       = 1.17548e-38f;
    constexpr FLOAT PI                          = 3.14159265f;
    constexpr FLOAT PI2                         = 6.28318530f;
    constexpr FLOAT PI_HALF                     = 1.57079632f;
    constexpr FLOAT PI_INVERTED                 = 0.31830988f;
    constexpr FLOAT EULER_NUMBER                = 2.71828182f;
    constexpr FLOAT GOLDEN_RATIO                = 1.61803398f;
    constexpr FLOAT TOLERANCE                   = 0.00000001f;
    constexpr FLOAT TO_DEGREES                  = 57.2957790f;
    constexpr FLOAT TO_RADIANS                  = 0.01745320f;
#endif

/* ####################################################################################### */
/* Numbers comparison */
/* ####################################################################################### */

/**
 * Compare number A and B.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
inline bool equal(T A, T B) {return A == B;}

template<>
inline bool equal(float A, float B) {return std::abs(A-B) <= TOLERANCE;}

template<>
inline bool equal(double A, double B) {return std::abs(A-B) <= TOLERANCE;}

/* --------------------------------------------------------------------------------------- */

/**
 * Compare number A and B.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
inline bool notEqual(T A, T B) {return A != B;}

template<>
inline bool notEqual(float A, float B) {return std::abs(A-B) > TOLERANCE;}

template<>
inline bool notEqual(double A, double B) {return std::abs(A-B) > TOLERANCE;}

#endif // MATH3D_GLOBAL_HPP
