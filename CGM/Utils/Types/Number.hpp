#pragma once


#include <CGM/Utils/ModuleGlobals.hpp>
#include <CGM/Utils/Types/NumberConstraints.hpp>


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
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, void>
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
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number&>
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
    operator -- (int);

    /**
     * Exposes pre increment.
     */
    constexpr CGM_FORCEINLINE Number&
    operator ++ ();

    /**
     * Exposes post increment.
     */
    constexpr CGM_FORCEINLINE Number
    operator ++ (int);

    /**
     * Exposes binary minus (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator - (const Number& other);

    /**
     * Exposes binary minus (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number>
    operator - (U other);

    /**
     * Exposes minus with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator -= (const Number& other);

    /**
     * Exposes minus with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number&>
    operator -= (U other);

    /**
     * Exposes binary plus (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator + (const Number& other);

    /**
     * Exposes binary plus (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number>
    operator + (U other);

    /**
     * Exposes plus with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator += (const Number& other);

    /**
     * Exposes plus with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number&>
    operator += (U other);

    /**
     * Exposes binary multiplication (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator * (const Number& other);

    /**
     * Exposes binary multiplication (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number>
    operator * (U other);

    /**
     * Exposes multiplication with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator *= (const Number& other);

    /**
     * Exposes multiplication with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number&>
    operator *= (U other);

    /**
     * Exposes binary division (by other).
     */
    constexpr CGM_FORCEINLINE Number
    operator / (const Number& other);

    /**
     * Exposes binary division (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number>
    operator / (U other);

    /**
     * Exposes division with assignment (by other).
     */
    constexpr CGM_FORCEINLINE Number&
    operator /= (const Number& other);

    /**
     * Exposes division with assignment (by number).
     */
    template <typename U>
    constexpr CGM_FORCEINLINE enable_if_convertible<U, T, Number&>
    operator /= (U other);

/* ####################################################################################### */
private: /* Internal attributes */
/* ####################################################################################### */

    T m_value;
};


/* ####################################################################################### */
/* Aliases */
/* ####################################################################################### */

template<typename T=FLOAT>
using PositiveNumber    = Number<T, PositiveNumberConstraint<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using NegativeNumber    = Number<T, NegativeNumberConstraint<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Length            = PositiveNumber<T>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Angle             = Number<T, RadiansAngleConstraint_2PI_2PI<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Angle_0_PI        = Number<T, RadiansAngleConstraint_0_PI<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Angle_0_2PI       = Number<T, RadiansAngleConstraint_0_2PI<T>>;

/* --------------------------------------------------------------------------------------- */

template<typename T=FLOAT>
using Angle_PI_PI       = Number<T, RadiansAngleConstraint_PI_PI<T>>;

CGM_NAMESPACE_END


#include "Number.inl"