

#include <Math3D/Core/Coordinates/Functions.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

template<typename T>
Vector<2,T>
cartesian(const Polar<T>& coord)
{
    return
    {
        coord.radius * std::cos(coord.angle),       // x
        coord.radius * std::sin(coord.angle)        // y
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
cartesian(const Spherical<T>& coord)
{
    T u = coord.radius * std::sin(coord.latitude);  // up
    T r = u * std::sin(coord.longitude);            // right
    T f = u * std::cos(coord.longitude)             // forward

    return axes::makeCoord(r, u, f);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
cartesian(const Cylindrical<T>& coord)
{
    T u = coord.height;                             // right
    T r = coord.radius * std::sin(coord.angle);     // right
    T f = coord.radius * std::cos(coord.angle);     // forward

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
    return axes::makeCoord();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Spherical<T>
spherical(const Cylindrical<T>& coord)
{
    T radius {std::sqrt(coord.radius * coord.radius + coord.height * coord.height)};

    return
    {
        coord.angle,            // longitude
        coord.height / radius,  // latitude
        radius                  // radius
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
        coord.longitude,                            // angle
        coord.radius * std::sin(coord.latitude),    // height
        coord.radius * std::cos(coord.latitude)     // radius
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Cylindrical<T>
cylindrical(const Vector<3,T>& coord)
{
    return
    {
        coord.longitude,                            // angle
        coord.radius * std::sin(coord.latitude),    // height
        coord.radius * std::cos(coord.latitude)     // radius
    };
}

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END