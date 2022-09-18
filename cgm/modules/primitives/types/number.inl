

#include "number.hpp"


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
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, void>
Number<T,Constraint>::set(U value)
{
    m_value = Constraint()(static_cast<T>(value));
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
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>&>
Number<T,Constraint>::operator = (U value)
{
    set(value);
    return *this;
}

/* ####################################################################################### */
/* Arithmetic operators exposing */
/* ####################################################################################### */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator -- ()
{
    set(m_value--);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator -- (int) const
{
    auto copy = *this;
    set(m_value--);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator ++ ()
{
    set(m_value++);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator ++ (int) const
{
    auto copy = *this;
    set(m_value++);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator - () const
{
    return Number<T,Constraint>(-m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator - (const Number& other) const
{
    return Number<T,Constraint>(m_value - other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>>
Number<T,Constraint>::operator - (U other) const
{
    return Number<T,Constraint>(m_value - other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator -= (const Number& other)
{
    set(m_value - other.m_value);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>&>
Number<T,Constraint>::operator -= (U other)
{
    set(m_value - other);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator + (const Number& other) const
{
    return Number<T,Constraint>(m_value + other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>>
Number<T,Constraint>::operator + (U other) const
{
    return Number<T,Constraint>(m_value + other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator += (const Number& other)
{
    set(m_value + other.m_value);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>&>
Number<T,Constraint>::operator += (U other)
{
    set(m_value + other);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator * (const Number& other) const
{
    return Number<T,Constraint>(m_value * other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>>
Number<T,Constraint>::operator * (U other) const
{
    return Number<T,Constraint>(m_value * other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator *= (const Number& other)
{
    set(m_value * other.m_value);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>&>
Number<T,Constraint>::operator *= (U other)
{
    set(m_value * other);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>
Number<T,Constraint>::operator / (const Number& other) const
{
    return Number<T,Constraint>(m_value / other.m_value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>>
Number<T,Constraint>::operator / (U other) const
{
    return Number<T,Constraint>(m_value / other);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T,Constraint>&
Number<T,Constraint>::operator /= (const Number& other)
{
    set(m_value / other.m_value);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
template <typename U>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number<T,Constraint>&>
Number<T,Constraint>::operator /= (U other)
{
    set(m_value / other);
    return *this;
}

/* ####################################################################################### */
/* Comparison operators exposing */
/* ####################################################################################### */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator == (const Number<T, Constraint>& other) const
{
    return m_value == other.m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator == (T value) const
{
    return m_value == value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator != (const Number<T, Constraint>& other) const
{
    return m_value != other.m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator != (T value) const
{
    return m_value != value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator > (const Number<T, Constraint>& other) const
{
    return m_value > other.m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator > (T value) const
{
    return m_value > value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator >= (const Number<T, Constraint>& other) const
{
    return m_value >= other.m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator >= (T value) const
{
    return m_value >= value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator < (const Number<T, Constraint>& other) const
{
    return m_value < other.m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator < (T value) const
{
    return m_value < value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator <= (const Number<T, Constraint>& other) const
{
    return m_value <= other.m_value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
Number<T, Constraint>::operator <= (T value) const
{
    return m_value <= value;
}

CGM_NAMESPACE_END