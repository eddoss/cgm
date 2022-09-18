

#include "common_io.hpp"


constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space)
{
    switch (space)
    {
        case CGM::ESpace::Global: stream << "CGM::ESpace::Global"; break;
        case CGM::ESpace::Local: stream << "CGM::ESpace::Local"; break;
    }

    return stream;
}

constexpr std::ostream&
operator << (std::ostream& stream, CGM::EHandedness handedness)
{
    switch (handedness)
    {
        case CGM::EHandedness::Left: stream << "CGM::EHandedness::Left"; break;
        case CGM::EHandedness::Right: stream << "CGM::EHandedness::Right"; break;
    }

    return stream;
}

constexpr std::ostream&
operator << (std::ostream& stream, CGM::EVectorRepresentation representation)
{
    switch (representation)
    {
        case CGM::EVectorRepresentation::Point: stream << "CGM::EVectorRepresentation::Point"; break;
        case CGM::EVectorRepresentation::Direction: stream << "CGM::EVectorRepresentation::Direction"; break;
    }

    return stream;
}