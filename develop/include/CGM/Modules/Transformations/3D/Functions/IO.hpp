#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/AxisAngle.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Axis<T>& axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Pivot<T>& pivot);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Transforms<T>& transforms);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::AxisAngle<T>& axisAngle);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XFORM3D::ERotationOrder rotationOrder);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ETransformOrder transformOrder);


#include <CGM/detail/Modules/Transformations/3D/Functions/IO.hpp>
