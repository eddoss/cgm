#ifndef MATH3D_QUATERNION_HPP
#define MATH3D_QUATERNION_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Quaternion
{
    MATH3D_RULE_OF_FIVE(Quaternion)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    // Quaternion equation: Q = s + ai + bj + ck

    T s; ///< scalar component.
    T a; ///< i imaginary component coefficient.
    T b; ///< j imaginary component coefficient.
    T c; ///< k imaginary component coefficient.

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

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Quaternion/Quaternion.hpp>


#endif // MATH3D_QUATERNION_HPP
