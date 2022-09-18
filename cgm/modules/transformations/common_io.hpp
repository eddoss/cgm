#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/transformations/common.hpp>


constexpr std::ostream&
operator << (std::ostream& stream, CGM::ETransformOrder transformOrder);


#include "common_io.inl"
