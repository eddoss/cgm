

#include "CommonIO.hpp"


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