#pragma once


#include <type_traits>


/* ####################################################################################### */
/* Library namespace */
/* ####################################################################################### */

#define MATH3D_NAMESPACE        mth
#define MATH3D_XY_NAMESPACE     xy
#define MATH3D_XYZ_NAMESPACE    xyz
#define MATH3D_COORD_NAMESPACE  coord

/* ####################################################################################### */
/* Library namespaces macro */
/* ####################################################################################### */

#define MATH3D_NAMESPACE_BEGIN          namespace MATH3D_NAMESPACE {
#define MATH3D_NAMESPACE_END            }

#define MATH3D_XY_NAMESPACE_BEGIN       namespace MATH3D_XY_NAMESPACE {
#define MATH3D_XY_NAMESPACE_END         }

#define MATH3D_XYZ_NAMESPACE_BEGIN      namespace MATH3D_XYZ_NAMESPACE {
#define MATH3D_XYZ_NAMESPACE_END        }

#define MATH3D_COORD_NAMESPACE_BEGIN    namespace MATH3D_COORD_NAMESPACE {
#define MATH3D_COORD_NAMESPACE_END      }

/* ####################################################################################### */
/* Platform */
/* ####################################################################################### */

#ifdef __GNUC__
    #define FORCEINLINE     inline __attribute__((always_inline))
    #define FORCENOINLINE   __attribute__((noinline))
#elif __clang__
    #define FORCEINLINE     inline __attribute__((always_inline))
    #define FORCENOINLINE   __attribute__((noinline))
#elif _MSC_VER
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
