#pragma once


#include <CGM/detail/Common.hpp>
#include <CGM/detail/Coordinates/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Cylindrical
{
    CGM_RULE_OF_FIVE(Cylindrical)

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /** Constructor initializing angle, height and radius. */
    constexpr
    Cylindrical(T angle, T height, T radius);

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /**
     * @brief Get rotation angle.
     * @return Angle in radians.
     */
    constexpr CGM_FORCEINLINE T
    angle() const;

    /**
     * @brief Get cylinder radius.
     * @return Cylinder radius.
     */
    constexpr CGM_FORCEINLINE T
    radius() const;

    /**
     * @brief Get cylinder radius.
     * @return Cylinder radius.
     */
    constexpr CGM_FORCEINLINE T
    height() const;

/* ####################################################################################### */
public: /* Properties setters */
/* ####################################################################################### */

    /**
     * @brief Set rotation angle.
     * @param angle Angle in radians.
     */
    constexpr CGM_FORCEINLINE void
    setAngle(T angle);

    /**
     * @brief Set cylinder radius. Value must be >= 0.
     * @param radius Cylinder radius.
     * @note If the given value is less than "0", then "0" will be set.
     */
    constexpr CGM_FORCEINLINE void
    setRadius(T radius);

    /**
     * @brief Set cylinder height.
     * @param radius Cylinder height.
     */
    constexpr CGM_FORCEINLINE void
    setHeight(T height);

/* ####################################################################################### */
protected: /* Protected members */
/* ####################################################################################### */

    T m_angle;
    T m_height;
    T m_radius;
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Coordinates/Types/Cylindrical_impl.hpp>
