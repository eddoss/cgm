

#include "Angles.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
normalizedAngle(T angle)
{
    T intpart {};
    return CGM_PI2 * std::modf(angle / CGM_PI2 , &intpart);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
normalizedAngle_0_2PI(T angle)
{
    T result = normalizedAngle(angle);
    if (result < static_cast<T>(0))
    {
        result = CGM_PI2 - result;
    }

    return result;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
normalizedAngle_PI_PI(T angle)
{
    T intpart {};
    T trunk = CGM_PI * std::modf(angle / CGM_PI, &intpart);

    return trunk - CGM_PI * (int64_t(intpart) % 2);
}

/* --------------------------------------------------------------------------------------- */

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