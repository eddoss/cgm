

#include "converters.hpp"


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Convert to Cartesian system */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
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
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
cartesian(const Spherical<T>& coord)
{
    T sinLat = std::sin(coord.latitude);
    T u = coord.radius * std::cos(coord.latitude);              // up
    T r = coord.radius * sinLat * std::sin(coord.longitude);    // right
    T f = coord.radius * sinLat * std::cos(coord.longitude);    // forward

    return cartesian(u, r, f);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
cartesian(const Cylindrical<T>& coord)
{
    T right     {coord.radius * std::sin(coord.angle)};
    T forward   {coord.radius * std::cos(coord.angle)};

    return cartesian(coord.height.get(), right, forward);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
cartesian(T up, T right, T forward)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return {up, forward, right};
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return {up, right, forward};
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return {forward, up, right};
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return {forward, right, up};
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return {right, forward, up};
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return {right, up, forward};
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<4,T>>
cartesian(T up, T right, T forward, T homogeneous)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return {up, forward, right, homogeneous};
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return {up, right, forward, homogeneous};
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return {forward, up, right, homogeneous};
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return {forward, right, up, homogeneous};
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return {right, forward, up, homogeneous};
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return {right, up, forward, homogeneous};
#endif
}

/* ####################################################################################### */
/* Convert to Polar system */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Polar<T>>
polar(const Vector<2,T>& coord)
{
    return
    {
        std::atan2(coord.y, coord.x),                       // angle
        std::sqrt(coord.x * coord.x + coord.y * coord.y)    // radius
    };
}

/* ####################################################################################### */
/* Convert to Spherical system */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Spherical<T>>
spherical(const Vector<3,T>& coord)
{
    T up        {CGM_COORD::up(coord)};
    T right     {CGM_COORD::right(coord)};
    T forward   {CGM_COORD::forward(coord)};

    T radius    {std::sqrt(coord.x * coord.x + coord.y * coord.y + coord.z * coord.z)};
    T longitude {std::atan2(right, forward)};
    T latitude  {std::atan2(std::sqrt(right * right + forward * forward), up)};

    return {longitude, latitude, radius};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Spherical<T>>
spherical(const Cylindrical<T>& coord)
{
    T radius    {std::sqrt(coord.radius * coord.radius + coord.height * coord.height)};
    T latitude  {std::atan2(coord.radius, coord.height)};

    return {coord.angle, latitude, radius};
}

/* ####################################################################################### */
/* Convert to Cylindrical system */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Cylindrical<T>>
cylindrical(const Spherical<T>& coord)
{
    return
    {
        coord.longitude,                              // angle
        coord.radius * std::cos(coord.latitude),    // height
        coord.radius * std::sin(coord.latitude)     // radius
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Cylindrical<T>>
cylindrical(const Vector<3,T>& coord)
{
    T right     {CGM_COORD::right(coord)};
    T forward   {CGM_COORD::forward(coord)};

    T radius    {std::sqrt(right * right + forward * forward)};
    T angle     {std::atan2(right, forward)};
    T height    {CGM_COORD::up(coord)};

    return {angle, height, radius};
}

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END