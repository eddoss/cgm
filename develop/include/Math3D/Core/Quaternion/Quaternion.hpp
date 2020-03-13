#ifndef MATH3D_QUATERNION_HPP
#define MATH3D_QUATERNION_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Platform.hpp>


template<typename T=FLOAT>
struct Quaternion
{

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    // Quaternion equation:
    // Q = s + ai + bj + ck

    T s; ///< scalar component;
    T a; ///< i imaginary component coefficient;
    T b; ///< j imaginary component coefficient;
    T c; ///< k imaginary component coefficient;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Separately initialize the i,j,k coefficients and the scalar component.
     * @param S Scalar component value.
     * @param A i imaginary component coefficient.
     * @param B j imaginary component coefficient.
     * @param C k imaginary component coefficient.
     */
    constexpr
    Quaternion(T S, T A, T B, T C);

    /**
     * Initialize scalar component and the i,j,k coefficients to a single value.
     * @param scalar Scalar component value.
     * @param coefficient Imaginary components coefficient.
     */
    constexpr
    Quaternion(T scalar, T coefficient);

    ~Quaternion()                       = default;

    constexpr
    Quaternion()                        = default;

    constexpr
    Quaternion(Quaternion&&) noexcept   = default;

    constexpr
    Quaternion(const Quaternion&)       = default;

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    constexpr Quaternion&
    operator = (Quaternion&&) noexcept  = default;

    constexpr Quaternion&
    operator = (const Quaternion&)      = default;

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get a raw data.
     * @return pointer to a components.
     */
    constexpr T*
    data();

    /**
     * Get a raw data.
     * @return const pointer to a components.
     */
    constexpr const T*
    data() const;
};

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

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

#endif // MATH3D_QUATERNION_HPP
