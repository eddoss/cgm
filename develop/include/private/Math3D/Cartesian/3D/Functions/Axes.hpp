

#include <Math3D/Cartesian/3D/Functions/Axes.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
x()
{
    return {T(1), T(0), T(0)};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
y()
{
    return {T(0), T(1), T(0)};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
z()
{
    return {T(0), T(0), T(1)};
}

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
up()
{
#ifdef MATH3D_CARTESIAN_UP_X
        return x<T>();
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
        return y<T>();
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
        return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
right()
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
        return x<T>();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
        return y<T>();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
        return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward()
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return x<T>();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return y<T>();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
down()
{
    return -up<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
left()
{
    return -right<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
backward()
{
    return -forward<T>();
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END
