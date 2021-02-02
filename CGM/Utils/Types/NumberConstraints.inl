

#include "NumberConstraints.hpp"


CGM_NAMESPACE_BEGIN

template <typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
PositiveNumberConstraint<T>::operator () (T value)
{
    return value > val<T>(0) ? value : val<T>(0);
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
NegativeNumberConstraint<T>::operator () (T value)
{
    return value < val<T>(0) ? value : val<T>(0);
}

/* ####################################################################################### */
/* Angle */
/* ####################################################################################### */

template <typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
RadiansAngleConstraint_0_PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > val<T>(CGM_PI) ? val<T>(CGM_PI) : value < val<T>(0) ? val<T>(0) : value;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
RadiansAngleConstraint_0_2PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > val<T>(CGM_PI2) ? val<T>(CGM_PI2) : value < val<T>(0) ? val<T>(0) : value;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
RadiansAngleConstraint_PI_PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > val<T>(CGM_PI) ? val<T>(CGM_PI) : value < val<T>(-CGM_PI) ? val<T>(-CGM_PI) : value;
}

/* --------------------------------------------------------------------------------------- */


template <typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
RadiansAngleConstraint_2PI_2PI<T>::operator () (T value)
{
    // TODO Normalize angle at first !!!
    return value > val<T>(CGM_PI2) ? val<T>(CGM_PI2) : value < val<T>(-CGM_PI2) ? val<T>(-CGM_PI2) : value;
}

CGM_NAMESPACE_END
