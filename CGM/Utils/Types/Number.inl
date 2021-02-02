

#include "Number.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template<typename T, typename Constraint>
constexpr
Number<T,Constraint>::Number(T value)
{
    set(value);
}

/* ####################################################################################### */
/* Accessing via methods */
/* ####################################################################################### */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE T
Number<T,Constraint>::get() const
{
    return m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, void>
Number<T,Constraint>::set(U value)
{
    value = Constraint()(static_cast<T>(value));
}

/* ####################################################################################### */
/* Accessing via Value<T,Constraint>::operators */
/* ####################################################################################### */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE
Number<T,Constraint>::operator T () const
{
    return m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>&>
Number<T,Constraint>::operator = (U value)
{
    set(value);
}

/* ####################################################################################### */
/* Arithmetic operators exposing */
/* ####################################################################################### */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator -- ()
{
    --m_value;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator -- (int)
{
    auto copy = *this;
    --m_value;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator ++ ()
{
    --m_value;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator ++ (int)
{
    auto copy = *this;
    ++m_value;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator - (const Number& other)
{
    return Number<T,Constraint>(m_value - other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>>
Number<T,Constraint>::operator - (U other)
{
    return Number<T,Constraint>(m_value - other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator -= (const Number& other)
{
    m_value -= other.m_value;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>&>
Number<T,Constraint>::operator -= (U other)
{
    m_value -= other;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator + (const Number& other)
{
    return Number<T,Constraint>(m_value + other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>>
Number<T,Constraint>::operator + (U other)
{
    return Number<T,Constraint>(m_value + other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator += (const Number& other)
{
    m_value += other.m_value;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>&>
Number<T,Constraint>::operator += (U other)
{
    m_value += other;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator * (const Number& other)
{
    return Number<T,Constraint>(m_value * other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>>
Number<T,Constraint>::operator * (U other)
{
    return Number<T,Constraint>(m_value * other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator *= (const Number& other)
{
    m_value *= other.m_value;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>&>
Number<T,Constraint>::operator *= (U other)
{
    m_value *= other;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator / (const Number& other)
{
    return Number<T,Constraint>(m_value / other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>>
Number<T,Constraint>::operator / (U other)
{
    return Number<T,Constraint>(m_value / other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator /= (const Number& other)
{
    m_value /= other.m_value;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number<T,Constraint>&>
Number<T,Constraint>::operator /= (U other)
{
    m_value /= other;
    return *this;
}

CGM_NAMESPACE_END