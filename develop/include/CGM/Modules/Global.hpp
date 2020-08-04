#pragma once


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
