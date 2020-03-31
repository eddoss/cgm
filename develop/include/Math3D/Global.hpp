#ifndef MATH3D_GLOBAL_HPP
#define MATH3D_GLOBAL_HPP


#include <algorithm>
#include <type_traits>
#include <Math3D/Platform.hpp>


/* ####################################################################################### */
/* Library namespaces */
/* ####################################################################################### */

#define MATH3D_NAMESPACE mth
#define MATH3D_AXES_NAMESPACE axes
#define MATH3D_COORD_NAMESPACE coord

/* ####################################################################################### */
/* Library namespaces macro */
/* ####################################################################################### */

#define MATH3D_NAMESPACE_BEGIN          namespace MATH3D_NAMESPACE {
#define MATH3D_NAMESPACE_END            }

#define MATH3D_AXES_NAMESPACE_BEGIN     namespace MATH3D_AXES_NAMESPACE {
#define MATH3D_AXES_NAMESPACE_END       }

#define MATH3D_COORD_NAMESPACE_BEGIN    namespace MATH3D_COORD_NAMESPACE {
#define MATH3D_COORD_NAMESPACE_END      }

MATH3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Common constants */
/* ####################################################################################### */

#ifdef MATH3D_USE_DOUBLE_PRECISION
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
FORCEINLINE bool equal(T A, T B);

/**
 * Compare number A and B.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
FORCEINLINE bool notEqual(T A, T B);

/* ####################################################################################### */
/* Floating point numbers comparison with given tolerance */
/* ####################################################################################### */

/**
 * Compare floating point number A and B with given tolerance.
 * @return true if abs(A-B) <= tolerance, false otherwise.
 */
template<typename T>
FORCEINLINE typename std::enable_if_t<std::is_floating_point<T>::value, bool>
equalTolerance(T A, T B, T tolerance);

/**
 * Compare floating point number A and B with given tolerance.
 * @return true if abs(A-B) > tolerance, false otherwise.
 */
template<typename T>
FORCEINLINE typename std::enable_if_t<std::is_floating_point<T>::value, bool>
notEqualTolerance(T A, T B, T tolerance);

/* ####################################################################################### */
/* Number converter */
/* ####################################################################################### */

/**
 * Convert number from type A in type B.
 */
template<typename AT, typename BT>
constexpr FORCEINLINE typename std::enable_if_t<(std::is_floating_point_v<AT> || std::is_integral_v<AT>), AT>
number(BT value);

/**
 * Create zero value number with given type.
 * @return Zero with given type.
 */
template<typename T>
constexpr FORCEINLINE typename std::enable_if_t<(std::is_floating_point_v<T> || std::is_integral_v<T>), T>
zero();

MATH3D_NAMESPACE_END


#include <private/Math3D/Global.hpp>


#endif // MATH3D_GLOBAL_HPP
