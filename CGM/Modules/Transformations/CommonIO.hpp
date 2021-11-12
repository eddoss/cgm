#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Transformations/Common.hpp>


constexpr std::ostream&
operator << (std::ostream& stream, CGM::ETransformOrder transformOrder);


#include "CommonIO.inl"