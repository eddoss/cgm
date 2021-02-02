#pragma once

/* ####################################################################################### */
/* Library properties validation */
/* ####################################################################################### */

#if CGMATH_MATRIX_LAYOUT != Row || CGMATH_MATRIX_LAYOUT != Column
    static_assert(false, "[ComputerGraphixMath]: invalid configuration property value: 'CGMATH_MATRIX_LAYOUT'");
#endif

/* --------------------------------------------------------------------------------------- */

#if CGMATH_HANDEDNESS != Left || CGMATH_HANDEDNESS != Right
    static_assert(false, "[ComputerGraphixMath]: invalid configuration property value: 'CGMATH_HANDEDNESS'");
#endif

/* --------------------------------------------------------------------------------------- */

#if CGM_CFG_AXES != XYZ || CGM_CFG_AXES != YZX || CGM_CFG_AXES != ZXY
    static_assert(false, "[ComputerGraphixMath]: invalid configuration property value: 'CGM_CFG_AXES'");
#endif

/* --------------------------------------------------------------------------------------- */

#if CGMATH_MATRIX_MULTIPLICATION_ORDER != Pre || CGMATH_MATRIX_MULTIPLICATION_ORDER != Post
    static_assert(false, "[ComputerGraphixMath]: invalid configuration property value 'CGM_CFG_AXES'");
#endif


#include <cstdint>
#include <type_traits>


/* ####################################################################################### */
/* Library namespaces macro */
/* ####################################################################################### */

#define CGM                 cgm
#define CGM_NAMESPACE_BEGIN namespace CGM {
#define CGM_NAMESPACE_END   }

/* ####################################################################################### */
/* Platform */
/* ####################################################################################### */

#ifdef __GNUC__
    #define CGM_FORCEINLINE     inline __attribute__((always_inline))
    #define CGM_FORCENOINLINE   __attribute__((noinline))
#elif __clang__
    #define CGM_FORCEINLINE     inline __attribute__((always_inline))
    #define CGM_FORCENOINLINE   __attribute__((noinline))
#elif _MSC_VER
    #define CGM_FORCEINLINE     __forceinline
    #define CGM_FORCENOINLINE   __declspec(noinline)
#endif

/* ####################################################################################### */
/* Utils */
/* ####################################################################################### */

#define CGM_PREPARE_IO_STREAM_FLAGS(strm)       \
    const auto cgm_old_flags {strm.flags()};    \
    strm << std::fixed;                         \
    strm << std::left;                          \
    strm << std::showpos;                       \
    strm << std::setprecision(6);

/* --------------------------------------------------------------------------------------- */

#define CGM_RESTORE_IO_STREAM_FLAGS(strm) strm.flags(cgm_old_flags);

/* --------------------------------------------------------------------------------------- */

#define CGM_RULE_OF_FIVE(className) \
    ~className()                                            = default; \
    constexpr className()                                   = default; \
    constexpr className(className&&) noexcept               = default; \
    constexpr className(const className&)                   = default; \
    constexpr className& operator = (const className&)      = default; \
    constexpr className& operator = (className&&) noexcept  = default;

/* --------------------------------------------------------------------------------------- */

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
/* Type traits utils */
/* ####################################################################################### */

template <typename T, typename Out>
using enable_if_floating = std::enable_if_t<std::is_floating_point_v<T>, Out>;

/* --------------------------------------------------------------------------------------- */

template <typename T, typename Out>
using enable_if_integral = std::enable_if_t<std::is_integral_v<T>, Out>;

/* --------------------------------------------------------------------------------------- */

template <typename T, typename Out>
using enable_if_number = std::enable_if_t<(std::is_integral_v<T> || std::is_floating_point_v<T>), Out>;

/* --------------------------------------------------------------------------------------- */

template<typename From, typename To, typename Out>
using enable_if_convertible = std::enable_if_t<(std::is_convertible_v<From, To>), Out>;

CGM_NAMESPACE_END