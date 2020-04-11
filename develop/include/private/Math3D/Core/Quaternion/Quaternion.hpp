

#include <Math3D/Core/Quaternion/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(T S, T A, T B, T C)
    : s(S)
    , a(A)
    , b(B)
    , c(C) {}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(T scalar, T coefficient)
    : s(scalar)
    , a(coefficient)
    , b(coefficient)
    , c(coefficient) {}

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

MATH3D_NAMESPACE_END
