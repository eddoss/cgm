#pragma once


#include <CGM/Modules/Cartesian/Common.hpp>


constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::EHandedness handedness);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::EVectorRepresentation representation);

#include "CommonIO.inl"