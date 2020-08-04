#pragma once


#include <CGM/Global.hpp>
#include <CGM/Common.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Polar
{
    CGM_RULE_OF_FIVE(Polar)

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /** Constructor initializing angle and radius. */
    constexpr
    Polar(T angle, T radius);

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /**
     * @brief Get rotation angle.
     * @return Angle in radians.
     */
    constexpr FORCEINLINE T
    angle() const;

    /**
     * @brief Get circle radius.
     * @return Circle radius.
     */
    constexpr FORCEINLINE T
    radius() const;

/* ####################################################################################### */
public: /* Properties setters */
/* ####################################################################################### */

    /**
     * @brief Set rotation angle.
     * @param angle Angle in radians.
     */
    constexpr FORCEINLINE void
    setAngle(T angle);

    /**
     * @brief Set circle radius. Value must be >= 0.
     * @param radius Circle radius.
     * @note If the given value is less than "0", then "0" will be set.
     */
    constexpr FORCEINLINE void
    setRadius(T radius);

/* ####################################################################################### */
protected: /* Protected members */
/* ####################################################################################### */

    T m_angle;
    T m_radius;
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include <private/CGM/Coordinates/Polar.hpp>