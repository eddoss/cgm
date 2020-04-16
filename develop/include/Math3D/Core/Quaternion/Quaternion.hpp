#ifndef MATH3D_QUATERNION_HPP
#define MATH3D_QUATERNION_HPP


#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T=FLOAT, typename = void> struct Quaternion;

template<typename T>
struct Quaternion <T, enable_if_floating<T,void>>
{
    MATH3D_RULE_OF_FIVE(Quaternion)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    // Quaternion equation: Q = s + xi + yj + zk

    T s; ///< scalar component.
    T x; ///< i imaginary component coefficient.
    T y; ///< j imaginary component coefficient.
    T z; ///< k imaginary component coefficient.

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Separately initialize the i,j,k coefficients and the scalar component.
     * @param S Scalar component value.
     * @param X i imaginary component coefficient.
     * @param Y j imaginary component coefficient.
     * @param Z k imaginary component coefficient.
     */
    constexpr
    Quaternion(T S, T X, T Y, T Z);

    /**
     * Initialize scalar component and the i,j,k coefficients to a single value.
     * @param scalar Scalar component value.
     * @param coefficients Imaginary components coefficients.
     */
    constexpr
    Quaternion(T scalar, T coefficients);

    /**
     * Initialize scalar component and the i,j,k coefficients from 3D vector..
     * @param scalar Scalar component value.
     * @param coefficients Imaginary components coefficients.
     */
    constexpr
    Quaternion(T scalar, const Vector<3,T>& coefficients);

    /**
     * Initialize from 4D vector.
     * @param values Scalar and imaginary coefficients.
     * @note Scalar component init from W.
     */
    constexpr
    Quaternion(const Vector<4,T>& values);

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
