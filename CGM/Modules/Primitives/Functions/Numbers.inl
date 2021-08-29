

#include "Numbers.hpp"


CGM_NAMESPACE_BEGIN

template<typename AT, typename BT>
constexpr CGM_FORCEINLINE std::enable_if_t<(std::is_floating_point_v<AT> || std::is_integral_v<AT>), AT>
val(BT value)
{
    return static_cast<AT>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T, Constraint>
num(T value)
{
    return Number<T, Constraint>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE NumberPositive<T>
posnum(T value)
{
    return PositiveNumber<T>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE NumberNegative<T>
negnum(T value)
{
    return NegativeNumber<T>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Number10<T>
num10(T value)
{
    return Number10<T>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Number01<T>
num01(T value)
{
    return Number01<T>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Number11<T>
num11(T value)
{
    return Number11<T>(value);
}

CGM_NAMESPACE_END