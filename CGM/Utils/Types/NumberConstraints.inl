

#include "NumberConstraints.hpp"


CGM_NAMESPACE_BEGIN

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
PositiveNumberConstraint<T>::operator () (T value)
{
    return value > T(0) ? value : T(0);
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
NegativeNumberConstraint<T>::operator () (T value)
{
    return value < T(0) ? value : T(0);
}

/* ####################################################################################### */
/* Angle */
/* ####################################################################################### */

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
AngleConstraint_0_2PI<T>::operator () (T value)
{
    return normalizedAngle_0_2PI(value);
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
AngleConstraint_PI_PI<T>::operator () (T value)
{
    return normalizedAngle_PI_PI(value);
}

/* --------------------------------------------------------------------------------------- */


template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
AngleConstraint_2PI_2PI<T>::operator () (T value)
{
    return normalizedAngle(value);
}

CGM_NAMESPACE_END
