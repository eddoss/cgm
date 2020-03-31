

#include <Math3D/Global.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
FORCEINLINE bool equal(T A, T B)
{
    if constexpr (std::is_floating_point_v<T>)
    {
        return std::abs(A-B) <= TOLERANCE;
    }
    else
    {
        return A == B;
    }
}
/* --------------------------------------------------------------------------------------- */

template<typename T>
FORCEINLINE bool notEqual(T A, T B)
{
    if constexpr (std::is_floating_point_v<T>)
    {
        return std::abs(A-B) > TOLERANCE;
    }
    else
    {
        return A != B;
    }
}

/* ####################################################################################### */
/* Floating point numbers comparison with given tolerance */
/* ####################################################################################### */

template<typename T>
FORCEINLINE typename std::enable_if_t<std::is_floating_point<T>::value, bool>
equalTolerance(T A, T B, T tolerance)
{
    return std::abs(A-B) <= tolerance;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
FORCEINLINE typename std::enable_if_t<std::is_floating_point<T>::value, bool>
notEqualTolerance(T A, T B, T tolerance)
{
    return std::abs(A-B) > tolerance;
}

/* ####################################################################################### */
/* Number converter */
/* ####################################################################################### */

template<typename AT, typename BT>
constexpr FORCEINLINE typename std::enable_if_t<(std::is_floating_point_v<AT> || std::is_integral_v<AT>), AT>
number(BT value)
{
    return static_cast<AT>(value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE typename std::enable_if_t<(std::is_floating_point_v<T> || std::is_integral_v<T>), T>
zero()
{
    return static_cast<T>(0);
}

MATH3D_NAMESPACE_END