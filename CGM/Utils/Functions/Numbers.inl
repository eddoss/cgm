

#include "Numbers.hpp"


CGM_NAMESPACE_BEGIN

template<typename AT, typename BT>
constexpr CGM_FORCEINLINE enable_if_number<AT,AT>
val(BT value)
{
    return static_cast<AT>(value);
}

/* --------------------------------------------------------------------------------------- */

CGM_NAMESPACE_END