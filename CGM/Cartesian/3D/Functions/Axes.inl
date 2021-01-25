

#include "Axes.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
axis()
{
    if constexpr (Axis == E3D::X)
    {
        return Vector<3,T>{number<T>(1), zero<T>, zero<T>};
    }
    else if constexpr (Axis == E3D::Y)
    {
        return Vector<3,T>{zero<T>, number<T>(1), zero<T>};
    }
    else
    {
        return Vector<3,T>{zero<T>, zero<T>, number<T>(1)};
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
x()
{
    return {number<T>(1), zero<T>, zero<T>};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
y()
{
    return {zero<T>, number<T>(1), zero<T>};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
z()
{
    return {zero<T>, zero<T>, number<T>(1)};
}

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
up()
{
#ifdef CGM_CFG_UP_IS_X
        return x<T>();
#endif
#ifdef CGM_CFG_UP_IS_Y
        return y<T>();
#endif
#ifdef CGM_CFG_UP_IS_Z
        return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right()
{
#ifdef CGM_CFG_RIGHT_IS_X
        return x<T>();
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
        return y<T>();
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
        return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward()
{
#ifdef CGM_CFG_FORWARD_IS_X
    return x<T>();
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    return y<T>();
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
down()
{
    return -up<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
left()
{
    return -right<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
backward()
{
    return -forward<T>();
}

CGM_NAMESPACE_END
