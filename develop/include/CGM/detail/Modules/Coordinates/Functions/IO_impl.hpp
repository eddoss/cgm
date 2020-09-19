

#include <CGM/detail/Modules/Coordinates/Functions/IO.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Polar<T>& polarCoord)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << typeid(polarCoord).name() << "\n{\n";
    stream << "    ang = " << polarCoord.angle() << "\n";
    stream << "    rad = " << polarCoord.radius() << "\n";
    stream << "}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Spherical<T>& sphericalCoord)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << typeid(sphericalCoord).name() << "\n{\n";
    stream << "    lon = " << sphericalCoord.longitude() << "\n";
    stream << "    lat = " << sphericalCoord.latitude() << "\n";
    stream << "    rad = " << sphericalCoord.radius() << "\n";
    stream << "}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Cylindrical<T>& cylindricalCoord)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << typeid(cylindricalCoord).name() << "\n{\n";
    stream << "    ang = " << cylindricalCoord.angle() << "\n";
    stream << "    hei = " << cylindricalCoord.height() << "\n";
    stream << "    rad = " << cylindricalCoord.radius() << "\n";
    stream << "}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}