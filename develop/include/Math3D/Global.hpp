#ifndef MATH3D_GLOBAL_HPP
#define MATH3D_GLOBAL_HPP


#include <type_traits>


/* ####################################################################################### */
/* Library namespaces */
/* ####################################################################################### */

#define MATH3D_NAMESPACE        mth
#define MATH3D_COORD_NAMESPACE  coord

/* ####################################################################################### */
/* Library namespaces macro */
/* ####################################################################################### */

#define MATH3D_NAMESPACE_BEGIN          namespace MATH3D_NAMESPACE {
#define MATH3D_NAMESPACE_END            }

#define MATH3D_COORD_NAMESPACE_BEGIN    namespace MATH3D_COORD_NAMESPACE {
#define MATH3D_COORD_NAMESPACE_END      }

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
/* Platform */
/* ####################################################################################### */

#ifdef __GNUC__
    #define FORCEINLINE     inline __attribute__((always_inline))
    #define FORCENOINLINE   __attribute__((noinline))
#endif

/* --------------------------------------------------------------------------------------- */

#ifdef __clang__
    #define FORCEINLINE     inline __attribute__((always_inline))
    #define FORCENOINLINE   __attribute__((noinline))
#endif

/* --------------------------------------------------------------------------------------- */

#ifdef _MSC_VER
    #define FORCEINLINE     __forceinline
    #define FORCENOINLINE   __declspec(noinline)
#endif

/* ####################################################################################### */
/* Utils */
/* ####################################################################################### */

#define MATH3D_RULE_OF_FIVE(className) \
    ~className()                                            = default; \
    constexpr className()                                   = default; \
    constexpr className(className&&) noexcept               = default; \
    constexpr className(const className&)                   = default; \
    constexpr className& operator = (const className&)      = default; \
    constexpr className& operator = (className&&) noexcept  = default;

/* --------------------------------------------------------------------------------------- */

template <typename T, typename TOut>
using enable_if_floating = std::enable_if_t<std::is_floating_point_v<T>, TOut>;

/* --------------------------------------------------------------------------------------- */

template <typename T, typename TOut>
using enable_if_integral = std::enable_if_t<std::is_integral_v<T>, TOut>;

#endif // MATH3D_GLOBAL_HPP
