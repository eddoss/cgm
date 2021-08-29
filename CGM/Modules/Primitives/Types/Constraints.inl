

#include "Constraints.hpp"


CGM_NAMESPACE_BEGIN

#define CGM_DEFINE_NUMBER_CONSTRAINT(StructName)                                \
    template <typename T>                                                       \
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>   \
    StructName<T>::operator () (T value)

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintPositive)
{
    return value > T(0) ? value : T(0);
}

/* --------------------------------------------------------------------------------------- */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintNegative)
{
    return value < T(0) ? value : T(0);
}

/* --------------------------------------------------------------------------------------- */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintRange01)
{
    return value >= T(1) ? T(1) : value <= T(0) ? T(0) : value;
}

/* --------------------------------------------------------------------------------------- */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintRange10)
{
    return value >= T(0) ? T(0) : value <= T(-1) ? T(-1) : value;
}

/* --------------------------------------------------------------------------------------- */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintRange11)
{
    return value >= T(1) ? T(1) : value <= T(-1) ? T(-1) : value;
}

/* ####################################################################################### */
/* Angle */
/* ####################################################################################### */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintAngle02Pi)
{
    T intPart {};
    T result = CGM_PI2 * std::modf(value / CGM_PI2 , &intPart);
    if (result < static_cast<T>(0))
    {
        result = CGM_PI2 - result;
    }

    return result;
}

/* --------------------------------------------------------------------------------------- */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintAnglePiPi)
{
    T intPart {};
    T trunk = CGM_PI * std::modf(value / CGM_PI, &intPart);

    return trunk - CGM_PI * (i64(intPart) % 2);
}

/* --------------------------------------------------------------------------------------- */

CGM_DEFINE_NUMBER_CONSTRAINT(NumberConstraintAngle2Pi2Pi)
{
    T intPart {};
    return CGM_PI2 * std::modf(value / CGM_PI2 , &intPart);
}

#undef CGM_DEFINE_NUMBER_CONSTRAINT

CGM_NAMESPACE_END
