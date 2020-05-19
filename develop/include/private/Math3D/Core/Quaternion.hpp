

#include <Math3D/Core/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(T S, T X, T Y, T Z)
    : s(S)
    , x(X)
    , y(Y)
    , z(Z)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(T scalar, T coefficients)
    : s(scalar)
    , x(coefficients)
    , y(coefficients)
    , z(coefficients)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(T scalar, const Vector<3,T>& coefficients)
    : s(scalar)
    , x(coefficients.x)
    , y(coefficients.y)
    , z(coefficients.z)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(const Vector<4,T>& values)
    : s(values.w)
    , x(values.x)
    , y(values.y)
    , z(values.z)
{

}

/* ####################################################################################### */
/* Components accessing */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE T*
Quaternion<T, enable_if_floating<T,void>>::data()
{
    return &s;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T*
Quaternion<T, enable_if_floating<T,void>>::data() const
{
    return &s;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
Quaternion<T, enable_if_floating<T,void>>::imaginary() const
{
    return {x,y,z};
}

MATH3D_NAMESPACE_END
