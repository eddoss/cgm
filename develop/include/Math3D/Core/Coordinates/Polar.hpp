#ifndef MATH3D_COORDINATES_SYSTEMS_POLAR_HPP
#define MATH3D_COORDINATES_SYSTEMS_POLAR_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Polar
{
    MATH3D_RULE_OF_FIVE(Polar)

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

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Coordinates/Polar.hpp>


#endif // MATH3D_COORDINATES_SYSTEMS_POLAR_HPP
