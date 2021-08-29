#pragma once


#include <type_traits>
#include <CGM/Modules/Primitives/ModuleGlobals.hpp>
#include <CGM/Modules/Primitives/Types/Constraints.hpp>
#include <CGM/Modules/Utils/TypeTraits.hpp>


CGM_NAMESPACE_BEGIN

template<typename T, typename Constraint>
struct Number
{
    static_assert
    (
        std::is_floating_point_v<T>                     &&
        std::is_invocable_v<Constraint, T>              &&
        std::is_default_constructible_v<Constraint>     &&
        std::is_same_v<T, std::invoke_result_t<Constraint, T>>
    );

    CGM_RULE_OF_FIVE(Number)

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize number.
     * @param value Init value.
     */
    constexpr
    Number(T value);

/* ####################################################################################### */
public: /* Accessing via methods */
/* ####################################################################################### */

    /**
     * Gets value.
     * @return Value.
     */
    constexpr CGM_FORCEINLINE T
    get() const;

    /**
     * Sets new value.
     * @param value New value.
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, void>
    set(U value);

/* ####################################################################################### */
public: /* Accessing via operators */
/* ####################################################################################### */

    /**
     * Converts value to T.
     * @return Converted value.
     */
    constexpr CGM_FORCEINLINE
    operator T () const;

    /**
     * Gets rectangle width.
     * @return Rectangle width.
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number&>
    operator = (U value);

/* ####################################################################################### */
public: /* Arithmetic operators exposing */
/* ####################################################################################### */

    /**
     * Exposes pre decrement.
     */
    constexpr CGM_FORCEINLINE Number&
    operator -- ();

    /**
     * Exposes post decrement.
     */
    constexpr CGM_FORCEINLINE Number
    operator -- (int) const;

    /**
     * Exposes pre increment.
     */
    constexpr CGM_FORCEINLINE Number&
    operator ++ ();

    /**
     * Exposes post increment.
     */
    constexpr CGM_FORCEINLINE Number
    operator ++ (int) const;

    /**
     * Exposes unary minus.
     */
    constexpr CGM_FORCEINLINE Number
    operator - () const;

    /**
     * Exposes binary minus (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator - (const Number& other) const;

    /**
     * Exposes binary minus (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number>
    operator - (U other) const;

    /**
     * Exposes minus with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator -= (const Number& other);

    /**
     * Exposes minus with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number&>
    operator -= (U other);

    /**
     * Exposes binary plus (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator + (const Number& other) const;

    /**
     * Exposes binary plus (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number>
    operator + (U other) const;

    /**
     * Exposes plus with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator += (const Number& other);

    /**
     * Exposes plus with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number&>
    operator += (U other);

    /**
     * Exposes binary multiplication (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator * (const Number& other) const;

    /**
     * Exposes binary multiplication (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number>
    operator * (U other) const;

    /**
     * Exposes multiplication with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator *= (const Number& other);

    /**
     * Exposes multiplication with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number&>
    operator *= (U other);

    /**
     * Exposes binary division (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator / (const Number& other) const;

    /**
     * Exposes binary division (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number>
    operator / (U other) const;

    /**
     * Exposes division with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator /= (const Number& other);

    /**
     * Exposes division with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_constructible_v<U, T>, Number&>
    operator /= (U other);

/* ####################################################################################### */
public: /* Comparison operators exposing */
/* ####################################################################################### */

    /**
     * Exposes equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator == (const Number& other) const;

    /**
     * Exposes equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator == (T value) const;

    /**
     * Exposes not equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator != (const Number& other) const;

    /**
     * Exposes not equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator != (T value) const;

    /**
     * Exposes greater operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator > (const Number& other) const;

    /**
     * Exposes greater operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator > (T value) const;

    /**
     * Exposes greater equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator >= (const Number& other) const;

    /**
     * Exposes greater equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator >= (T value) const;

    /**
     * Exposes less operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator < (const Number& other) const;

    /**
     * Exposes less operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator < (T value) const;

    /**
     * Exposes less equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator <= (const Number& other) const;

    /**
     * Exposes less equal operator.
     */
    constexpr CGM_FORCEINLINE bool
    operator <= (T value) const;

/* ####################################################################################### */
private: /* Internal attributes */
/* ####################################################################################### */

    T m_value;
};

/* ####################################################################################### */
/* Aliases */
/* ####################################################################################### */

template<typename T=FLOAT>
using NumberPositive    = std::conditional_t
<
    std::is_floating_point_v<floating_or_unsigned_t<T>>,
    Number<T, NumberConstraintPositive<T>>,
    T
>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using NumberNegative    = Number<T, NumberConstraintNegative<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Number10          = Number<T, NumberConstraintRange10<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Number01          = Number<T, NumberConstraintRange01<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Number11          = Number<T, NumberConstraintRange11<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Length            = NumberPositive<T>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Angle             = Number<T, NumberConstraintAngle2Pi2Pi<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Angle02Pi         = Number<T, NumberConstraintAngle02Pi<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using AnglePiPi         = Number<T, NumberConstraintAnglePiPi<T>>;

CGM_NAMESPACE_END

#include "Number.inl"