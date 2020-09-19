#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/detail/Cartesian/2D/Types/Axes.hpp>
#include <CGM/detail/Cartesian/2D/Types/Enums.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XY::EAxes axis);


#include <CGM/detail/Cartesian/2D/Functions/IO_impl.hpp>
