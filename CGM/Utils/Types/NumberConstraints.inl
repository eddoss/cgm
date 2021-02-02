

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
RadiansAngleConstraint_0_PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > T(CGM_PI) ? T(CGM_PI) : value < T(0) ? T(0) : value;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
RadiansAngleConstraint_0_2PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > T(CGM_PI2) ? T(CGM_PI2) : value < T(0) ? T(0) : value;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
RadiansAngleConstraint_PI_PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > T(CGM_PI) ? T(CGM_PI) : value < T(-CGM_PI) ? T(-CGM_PI) : value;
}

/* --------------------------------------------------------------------------------------- */


template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
RadiansAngleConstraint_2PI_2PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > T(CGM_PI2) ? T(CGM_PI2) : value < T(-CGM_PI2) ? T(-CGM_PI2) : value;
}

CGM_NAMESPACE_END
