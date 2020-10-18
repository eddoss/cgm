#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Cartesian/2D/Types/Axes.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::E2D axis);


#include "IO.inl"
