

#include "angles.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
radians(T angle)
{
    return angle * static_cast<T>(0.01745329251994329576923690768489);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
degrees(T angle)
{
    return angle * static_cast<T>(57.295779513082320876798154814105);
}

CGM_NAMESPACE_END