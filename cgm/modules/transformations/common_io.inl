

#include "common.hpp"


constexpr std::ostream&
operator << (std::ostream& stream, CGM::ETransformOrder transformOrder)
{
    switch (transformOrder)
    {
        case CGM::ETransformOrder::RST: stream << "CGM::ETransformOrder::RST"; break;
        case CGM::ETransformOrder::RTS: stream << "CGM::ETransformOrder::RTS"; break;
        case CGM::ETransformOrder::SRT: stream << "CGM::ETransformOrder::SRT"; break;
        case CGM::ETransformOrder::STR: stream << "CGM::ETransformOrder::STR"; break;
        case CGM::ETransformOrder::TRS: stream << "CGM::ETransformOrder::TRS"; break;
        case CGM::ETransformOrder::TSR: stream << "CGM::ETransformOrder::TSR"; break;
    }

    return stream;
}