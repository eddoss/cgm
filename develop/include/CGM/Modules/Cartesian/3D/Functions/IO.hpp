#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Cartesian/Common.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Axes.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Enums.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XYZ::EAxes axis);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space);

#include <CGM/detail/Modules/Cartesian/3D/Functions/IO.hpp>
