

#include <CGM/Cartesian/Common.hpp>


constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space)
{
    switch (space)
    {
        case CGM::ESpace::World: stream << "CGM::ESpace::World"; break;
        case CGM::ESpace::Local: stream << "CGM::ESpace::Local"; break;
    }

    return stream;
}