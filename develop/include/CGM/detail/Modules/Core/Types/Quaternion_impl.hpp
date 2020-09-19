

#include <CGM/detail/Modules/Core/Types/Quaternion.hpp>


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(T x, T y, T z, T w)
    : vector(x,y,z)
    , scalar(w)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(T coefficientsValue, T scalarValue)
    : vector(coefficientsValue, coefficientsValue, coefficientsValue)
    , scalar(scalarValue)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(const VectorType& coefficients, T scalarValue)
    : vector(coefficients)
    , scalar(scalarValue)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Quaternion<T, enable_if_floating<T,void>>::Quaternion(const Vector<4,T>& values)
    : vector(values.xyz())
    , scalar(values.w)
{

}

/* ####################################################################################### */
/* Components accessing */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE T*
Quaternion<T, enable_if_floating<T,void>>::data()
{
    return &vector.x;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE const T*
Quaternion<T, enable_if_floating<T,void>>::data() const
{
    return &vector.x;
}


CGM_NAMESPACE_END
