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

#if CGM_CFG_MATRIX_MULTIPLICATION_ORDER != Pre || CGM_CFG_MATRIX_MULTIPLICATION_ORDER != Post
    static_assert(false, "[ComputerGraphixMath]: invalid configuration property value 'CGM_CFG_AXES'");
#endif


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

template <typename T, typename TOut>
using enable_if_floating = std::enable_if_t<std::is_floating_point_v<T>, TOut>;

/* --------------------------------------------------------------------------------------- */

template <typename T, typename TOut>
using enable_if_integral = std::enable_if_t<std::is_integral_v<T>, TOut>;

/* --------------------------------------------------------------------------------------- */

template <typename T, typename TOut>
using enable_if_floating_or_integral = std::enable_if_t<(std::is_integral_v<T> || std::is_floating_point_v<T>), TOut>;
