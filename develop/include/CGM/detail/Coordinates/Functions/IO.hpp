#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/detail/Coordinates/Types/Polar.hpp>
#include <CGM/detail/Coordinates/Types/Spherical.hpp>
#include <CGM/detail/Coordinates/Types/Cylindrical.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Polar<T>& polarCoord);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Spherical<T>& sphericalCoord);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Cylindrical<T>& cylindricalCoord);


#include <CGM/detail/Coordinates/Functions/IO_impl.hpp>