#pragma once


#include <type_traits>


/* ####################################################################################### */
/* Library namespace */
/* ####################################################################################### */

#define CGM        cgm
#define CGM_XY     xy
#define CGM_XYZ    xyz
#define CGM_COORD  coord

/* ####################################################################################### */
/* Library namespaces macro */
/* ####################################################################################### */

#define CGM_NAMESPACE_BEGIN          namespace CGM {
#define CGM_NAMESPACE_END            }

#define CGM_XY_NAMESPACE_BEGIN       namespace CGM_XY {
#define CGM_XY_NAMESPACE_END         }

#define CGM_XYZ_NAMESPACE_BEGIN      namespace CGM_XYZ {
#define CGM_XYZ_NAMESPACE_END        }

#define CGM_COORD_NAMESPACE_BEGIN    namespace CGM_COORD {
#define CGM_COORD_NAMESPACE_END      }

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

#define CGM_RULE_OF_FIVE(className) \
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

/* --------------------------------------------------------------------------------------- */

template <typename T, typename TOut>
using enable_if_floating_or_integral = std::enable_if_t<(std::is_integral_v<T> || std::is_floating_point_v<T>), TOut>;
