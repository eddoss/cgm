

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
constexpr CGM_FORCEINLINE PositiveNumber<T>
posnum(T value)
{
    return PositiveNumber<T>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE NegativeNumber<T>
negnum(T value)
{
    return NegativeNumber<T>(value);
}

CGM_NAMESPACE_END