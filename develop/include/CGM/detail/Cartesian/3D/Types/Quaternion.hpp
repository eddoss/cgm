#pragma once


#include <type_traits>
#include <CGM/detail/Cartesian/3D/ModuleGlobals.hpp>
#include <CGM/detail/Core/Types/Vector.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

template<typename T=FLOAT, typename = void> struct Quaternion;

template<typename T>
struct Quaternion <T, enable_if_floating<T,void>>
{
    CGM_RULE_OF_FIVE(Quaternion)

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using const_pointer     = const T*;
    using const_reference   = const T&;
    using VectorType        = Vector<3,T>;
    using ScalarType        = T;

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    VectorType vector;
    ScalarType scalar;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Separately initialize the i,j,k coefficients and the scalar component.
     * @param x i imaginary component coefficient.
     * @param y j imaginary component coefficient.
     * @param z k imaginary component coefficient.
     * @param w Scalar component value.
     */
    constexpr
    Quaternion(T x, T y, T z, T w);

    /**
     * Initialize scalar component and the i,j,k coefficients to a single value.
     * @param scalarValue Scalar component value.
     * @param coefficients Imaginary components coefficients.
     */
    constexpr
    Quaternion(T coefficientsValue, T scalarValue);

    /**
     * Initialize scalar component and the i,j,k coefficients from 3D vector..
     * @param scalarValue Scalar component value.
     * @param coefficients Imaginary components coefficients.
     */
    constexpr
    Quaternion(const VectorType& coefficients, T scalarValue);

    /**
     * Initialize from 4D vector.
     * @param values Scalar and imaginary coefficients.
     * @note Scalar component init from W.
     */
    constexpr explicit
    Quaternion(const Vector<4,T>& values);

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Gets a raw data.
     * @return pointer to a components.
     */
    constexpr CGM_FORCEINLINE pointer
    data();

    /**
     * Gets a raw data.
     * @return const pointer to a components.
     */
    constexpr CGM_FORCEINLINE const_pointer
    data() const;
};

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Cartesian/3D/Types/Quaternion_impl.hpp>
