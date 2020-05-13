

#include <Math3D/Cartesian/Functions/Axes.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr FORCEINLINE std::enable_if_t<(D == 2 || D == 3), Vector<D,T>>
x()
{
    if constexpr (D == 2)
    {
        return {T(1), T(0)};
    }
    else
    {
        return {T(1), T(0), T(0)};
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE std::enable_if_t<(D == 2 || D == 3), Vector<D,T>>
y()
{
    if constexpr (D == 2)
    {
        return {T(0), T(1)};
    }
    else
    {
        return {T(0), T(1), T(0)};
    }
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

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
up()
{
    if constexpr (D == 2)
    {
        return y<2,T>();
    }
    else
    {
 #ifdef MATH3D_CARTESIAN_UP_X
        return x<3,T>();
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
        return y<3,T>();
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
        return z<T>();
#endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
right()
{
    if constexpr (D == 2)
    {
        return x<2,T>();
    }
    else
    {
#ifdef MATH3D_CARTESIAN_RIGHT_X
        return x<3,T>();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
        return y<3,T>();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
        return z<T>();
#endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward()
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return x<3,T>();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return y<3,T>();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
down()
{
    return -up<D,T>();
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
left()
{
    return -right<D,T>();
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
