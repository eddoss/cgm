#pragma once


#include <CGM/Modules/Common.hpp>
#include <CGM/Modules/Coordinates/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Spherical
{
    CGM_RULE_OF_FIVE(Spherical)

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * @brief Constructor initializing longitude (horizontal) angle,
     * latitude (vertical) angle and sphere radius.
     */
    constexpr
    Spherical(T longitude, T latitude, T radius);

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /**
     * @brief Get longitude angle.
     * @return Horizontal angle in radians.
     */
    constexpr CGM_FORCEINLINE T
    longitude() const;

    /**
     * @brief Get latitude angle.
     * @return Vertical angle in radians.
     */
    constexpr CGM_FORCEINLINE T
    latitude() const;

    /**
     * @brief Get sphere radius.
     * @return Sphere radius.
     */
    constexpr CGM_FORCEINLINE T
    radius() const;

/* ####################################################################################### */
public: /* Properties setters */
/* ####################################################################################### */

    /**
     * @brief Set longitude angle.
     * @param longitude Horizontal angle in radians.
     */
    constexpr CGM_FORCEINLINE void
    setLongitude(T longitude);

    /**
     * Set longitude angle in radians. Value must be in range [0, PI].
     * @note If the given value is out of range, given value
     * will be clamped.
     */
    constexpr CGM_FORCEINLINE void
    setLatitude(T latitude);

    /**
     * Set sphere radius. Value must be >= 0.
     * @note If the given value is less than "0", then "0" will be set.
     */
    constexpr CGM_FORCEINLINE void
    setRadius(T radius);

/* ####################################################################################### */
protected: /* Protected members */
/* ####################################################################################### */

    T m_longitude;    // azimuth, horizontal
    T m_latitude;     // elevation, vertical
    T m_radius;
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Coordinates/Types/Spherical.hpp>