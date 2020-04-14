#ifndef MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP
#define MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Spherical
{
    MATH3D_RULE_OF_FIVE(Spherical)

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
    constexpr FORCEINLINE T
    longitude() const;

    /**
     * @brief Get latitude angle.
     * @return Vertical angle in radians.
     */
    constexpr FORCEINLINE T
    latitude() const;

    /**
     * @brief Get sphere radius.
     * @return Sphere radius.
     */
    constexpr FORCEINLINE T
    radius() const;

/* ####################################################################################### */
public: /* Properties setters */
/* ####################################################################################### */

    /**
     * @brief Set longitude angle.
     * @param longitude Horizontal angle in radians.
     */
    constexpr FORCEINLINE void
    setLongitude(T longitude);

    /**
     * Set longitude angle in radians. Value must be in range [0, PI].
     * @note If the given value is out of range, given value
     * will be clamped.
     */
    constexpr FORCEINLINE void
    setLatitude(T latitude);

    /**
     * Set sphere radius. Value must be >= 0.
     * @note If the given value is less than "0", then "0" will be set.
     */
    constexpr FORCEINLINE void
    setRadius(T radius);

/* ####################################################################################### */
protected: /* Protected members */
/* ####################################################################################### */

    T m_longitude;    // azimuth, horizontal
    T m_latitude;     // elevation, vertical
    T m_radius;
};

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Coordinates/Spherical.hpp>


#endif // MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP