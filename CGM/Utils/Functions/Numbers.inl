

#include "Numbers.hpp"


CGM_NAMESPACE_BEGIN

template<typename AT, typename BT>
constexpr CGM_FORCEINLINE std::enable_if_t<(std::is_floating_point_v<AT> || std::is_integral_v<AT>), AT>
val(BT value)
{
    return static_cast<AT>(value);
}

/* --------------------------------------------------------------------------------------- */

CGM_NAMESPACE_END