#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/coordinates/types/polar.hpp>
#include <cgm/modules/coordinates/types/spherical.hpp>
#include <cgm/modules/coordinates/types/cylindrical.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Polar<T>& polarCoord);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Spherical<T>& sphericalCoord);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Cylindrical<T>& cylindricalCoord);


#include "io.inl"
