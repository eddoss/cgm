#ifndef MATH3D_PRIVATE_QUATERNION_HPP
#define MATH3D_PRIVATE_QUATERNION_HPP


#include <Math3D/Core/Quaternion/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
constexpr
Quaternion<T>::Quaternion(T S, T A, T B, T C)
    : s(S)
    , a(A)
    , b(B)
    , c(C) {}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T>::Quaternion(T scalar, T coefficient)
    : s(scalar)
    , a(coefficient)
    , b(coefficient)
    , c(coefficient) {}

/* ####################################################################################### */
/* Components accessing */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE T*
Quaternion<T>::data()
{
    return &s;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T*
Quaternion<T>::data() const
{
    return &s;
}

MATH3D_NAMESPACE_END

#endif // MATH3D_PRIVATE_QUATERNION_HPP
