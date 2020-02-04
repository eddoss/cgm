#ifndef MATH3D_QUATERNION_HPP
#define MATH3D_QUATERNION_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Platform.hpp>
#include <Math3D/Core/Structs/Vector/Vector.hpp>

template<typename T=FLOAT>
struct Quaternion
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using ScalarType    = T;
    using VectorType    = Vector<3,T>;

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    VectorType vector   {0,0,0};    /**< imaginary components. */
    ScalarType scalar   {0};        /**< Scalar component. */

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Constructor separately initializes the vector and the scalar.
     * @param v Value to set all imaginary components to.
     * @param s Scalar component value.
     */
    constexpr
    Quaternion(const VectorType& v, ScalarType s);

    /**
     * Constructor using initial values for imaginary and scalar components.
     * @param s Scalar component value.
     * @param x X imaginary component value.
     * @param y Y imaginary component value.
     * @param z Z imaginary component value.
     */
    constexpr
    Quaternion(T x, T y, T z, ScalarType s);

    /**
     * Construct from 4D vector. W component use as quaternion scalar.
     * @param vector 4D vector containing quaternion xyz and scalar values.
     */
    constexpr explicit
    Quaternion(const Vector<4,T>& values);

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
    T*
    data();

    /**
     * Get a raw data.
     * @return const pointer to a components.
     */
    const T*
    data() const;
};

#endif // MATH3D_QUATERNION_HPP
