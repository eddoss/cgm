#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>
#include <cgm/modules/transformations/3d/types/axis_angle.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Ray<T>& axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Pivot<T>& pivot);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Transforms<T>& transforms);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::AxisAngle<T>& axisAngle);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ERotationOrder rotationOrder);


#include "io.inl"
