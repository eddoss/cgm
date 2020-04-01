

#include <Math3D/Core/Coordinates/Functions.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

template<typename T>
Vector<2,T>
cartesian(const Polar<T>& coord)
{
    return
    {
        coord.radius() * std::cos(coord.angle()),       // x
        coord.radius() * std::sin(coord.angle())        // y
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
cartesian(const Spherical<T>& coord)
{
    T sinLat = std::sin(coord.latitude());
    T u = coord.radius() * std::cos(coord.latitude());              // up
    T r = coord.radius() * sinLat * std::sin(coord.longitude());    // right
    T f = coord.radius() * sinLat * std::cos(coord.longitude());    // forward

    return axes::makeCoord(r, u, f);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
cartesian(const Cylindrical<T>& coord)
{
    T u = coord.height();                               // right
    T r = coord.radius() * std::sin(coord.angle());     // right
    T f = coord.radius() * std::cos(coord.angle());     // forward

    return axes::makeCoord(r, u, f);
}

/* ####################################################################################### */
/* Convert to Polar system */
/* ####################################################################################### */

template<typename T>
Polar<T>
polar(const Vector<2,T>& coord)
{
    return
    {
        std::atan2(coord.y, coord.x),                       // angle
        std::sqrt(coord.x * coord.x + coord.y * coord.y)    // radius
    }
}

/* ####################################################################################### */
/* Convert to Spherical system */
/* ####################################################################################### */

template<typename T>
Spherical<T>
spherical(const Vector<3,T>& coord)
{
    T up        {axes::upComponent(coord)};
    T right     {axes::rightComponent(coord)};
    T forward   {axes::forwardComponent(coord)};

    T radius    {std::sqrt(coord.x * coord.x + coord.y * coord.y + coord.z * coord.z)};
    T longitude {std::atan2(right, forward)};
    T latitude  {std::atan2(std::sqrt(right * right + forward * forward), up)};

    return {longitude, latitude, radius};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Spherical<T>
spherical(const Cylindrical<T>& coord)
{
    T radius {std::sqrt(coord.radius() * coord.radius() + coord.height() * coord.height())};

    return
    {
        coord.angle(),              // longitude
        coord.height() / radius,    // latitude
        radius                      // radius
    };
}

/* ####################################################################################### */
/* Convert to Cylindrical system */
/* ####################################################################################### */

template<typename T>
Cylindrical<T>
cylindrical(const Spherical<T>& coord)
{
    return
    {
        coord.longitude(),                              // angle
        coord.radius() * std::sin(coord.latitude()),    // height
        coord.radius() * std::cos(coord.latitude())     // radius
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Cylindrical<T>
cylindrical(const Vector<3,T>& coord)
{
    T right     {axes::rightComponent(coord)};
    T forward   {axes::forwardComponent(coord)};

    T radius    {std::sqrt(right * right + forward * forward)};
    T angle     {std::atan2(right/forward)};
    T height    {axes::upComponent(coord)};

    return
    {
        angle,
        height,
        radius
    };
}

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END