#ifndef MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP
#define MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Cylindrical
{
    MATH3D_RULE_OF_FIVE(Cylindrical)

/* ####################################################################################### */
/* Constructors */
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
    constexpr FORCEINLINE T
    angle() const;

    /**
     * @brief Get cylinder radius.
     * @return Cylinder radius.
     */
    constexpr FORCEINLINE T
    radius() const;

    /**
     * @brief Get cylinder radius.
     * @return Cylinder radius.
     */
    constexpr FORCEINLINE T
    height() const;

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
     * @brief Set cylinder radius. Value must be >= 0.
     * @param radius Cylinder radius.
     * @note If the given value is less than "0", then "0" will be set.
     */
    constexpr FORCEINLINE void
    setRadius(T radius);

    /**
     * @brief Set cylinder height.
     * @param radius Cylinder height.
     */
    constexpr FORCEINLINE void
    setHeight(T height);

/* ####################################################################################### */
protected: /* Protected members */
/* ####################################################################################### */

    T m_angle;
    T m_height;
    T m_radius;
};

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Coordinates/Cylindrical.hpp>


#endif // MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP