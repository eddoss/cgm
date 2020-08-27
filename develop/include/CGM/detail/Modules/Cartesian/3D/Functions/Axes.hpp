

#include <CGM/Modules/Cartesian/3D/Functions/Axes.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
axis()
{
    if constexpr (Axis == EAxes::X)
    {
        return Vector<3,T>{number<T>(1), zero<T>, zero<T>};
    }
    else if constexpr (Axis == EAxes::Y)
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
#ifdef CGM_CARTESIAN_UP_X
        return x<T>();
#endif
#ifdef CGM_CARTESIAN_UP_Y
        return y<T>();
#endif
#ifdef CGM_CARTESIAN_UP_Z
        return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right()
{
#ifdef CGM_CARTESIAN_RIGHT_X
        return x<T>();
#endif
#ifdef CGM_CARTESIAN_RIGHT_Y
        return y<T>();
#endif
#ifdef CGM_CARTESIAN_RIGHT_Z
        return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward()
{
#ifdef CGM_CARTESIAN_FORWARD_X
    return x<T>();
#endif
#ifdef CGM_CARTESIAN_FORWARD_Y
    return y<T>();
#endif
#ifdef CGM_CARTESIAN_FORWARD_Z
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

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END
