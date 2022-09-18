#pragma once


#include <cgm/modules/cartesian/common.hpp>


constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::EHandedness handedness);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::EVectorRepresentation representation);

#include "common_io.inl"
