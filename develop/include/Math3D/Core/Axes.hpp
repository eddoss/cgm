#ifndef MATH3D_AXES_HPP
#define MATH3D_AXES_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Platform.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


namespace axes
{

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Cartesian x axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
x();

/**
 * Cartesian system y axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
y();

/**
 * Cartesian system z axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
z();

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

/**
 * Return Cartesian system up axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
up();

/**
 * Return Cartesian system right axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
right();

/**
 * Return Cartesian system forward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
forward();

/**
 * Return Cartesian system down axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
down();

/**
 * Return Cartesian system left axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
left();

/**
 * Return Cartesian system backward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
backward();

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<typename T>
constexpr Vector<3,T>
x()
{
    return
    {
        number<T>(1),
        number<T>(0),
        number<T>(0)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
y()
{
    return
    {
        number<T>(0),
        number<T>(1),
        number<T>(0)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
z()
{
    return
    {
        number<T>(0),
        number<T>(0),
        number<T>(1)
    };
}

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

template<typename T>
constexpr Vector<3,T>
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
constexpr Vector<3,T>
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
constexpr Vector<3,T>
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
constexpr Vector<3,T>
down()
{
    return -up<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
left()
{
    return -right<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
backward()
{
    return -forward<T>();
}

};

#endif // MATH3D_AXES_HPP