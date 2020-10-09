#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Coordinates/Types/Polar.hpp>
#include <CGM/Coordinates/Types/Spherical.hpp>
#include <CGM/Coordinates/Types/Cylindrical.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Polar<T>& polarCoord);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Spherical<T>& sphericalCoord);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Cylindrical<T>& cylindricalCoord);


#include <CGM/Coordinates/Functions/IO.inl>
