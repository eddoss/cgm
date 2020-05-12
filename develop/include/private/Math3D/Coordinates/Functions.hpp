

#include <Math3D/Coordinates/Functions.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector component extractors */
/* ####################################################################################### */


template<typename T>
constexpr FORCEINLINE T&
right(Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.x;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T&
up(Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T&
forward(Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T&
right(const Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.x;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T&
up(const Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T&
forward(const Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.z;
#endif
}

/* ####################################################################################### */
/* Convert to Cartesian system */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
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
constexpr FORCEINLINE Vector<3,T>
cartesian(const Spherical<T>& coord)
{
    T sinLat = std::sin(coord.latitude());
    T u = coord.radius() * std::cos(coord.latitude());              // up
    T r = coord.radius() * sinLat * std::sin(coord.longitude());    // right
    T f = coord.radius() * sinLat * std::cos(coord.longitude());    // forward

    return cartesian(r, u, f);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
cartesian(const Cylindrical<T>& coord)
{
    T right     {coord.radius() * std::sin(coord.angle())};
    T forward   {coord.radius() * std::cos(coord.angle())};

    return cartesian(right, coord.height(), forward);
}

/* ####################################################################################### */
/* Convert to Polar system */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Polar<T>
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
constexpr FORCEINLINE Spherical<T>
spherical(const Vector<3,T>& coord)
{
    T up        {coord::up(coord)};
    T right     {coord::right(coord)};
    T forward   {coord::forward(coord)};

    T radius    {std::sqrt(coord.x * coord.x + coord.y * coord.y + coord.z * coord.z)};
    T longitude {std::atan2(right, forward)};
    T latitude  {std::atan2(std::sqrt(right * right + forward * forward), up)};

    return {longitude, latitude, radius};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Spherical<T>
spherical(const Cylindrical<T>& coord)
{
    T radius    {std::sqrt(coord.radius() * coord.radius() + coord.height() * coord.height())};
    T latitude  {std::atan2(coord.radius(), coord.height())};

    return {coord.angle(), latitude, radius};
}

/* ####################################################################################### */
/* Convert to Cylindrical system */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Cylindrical<T>
cylindrical(const Spherical<T>& coord)
{
    return
    {
        coord.longitude(),                              // angle
        coord.radius() * std::cos(coord.latitude()),    // height
        coord.radius() * std::sin(coord.latitude())     // radius
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Cylindrical<T>
cylindrical(const Vector<3,T>& coord)
{
    T right     {coord::right(coord)};
    T forward   {coord::forward(coord)};

    T radius    {std::sqrt(right * right + forward * forward)};
    T angle     {std::atan2(right, forward)};
    T height    {coord::up(coord)};

    return {angle, height, radius};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
cartesian(T right, T up, T forward)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return {up, forward, right};
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return {up, right, forward};
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return {forward, up, right};
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return {forward, right, up};
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return {right, forward, up};
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return {right, up, forward};
#endif
}

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END