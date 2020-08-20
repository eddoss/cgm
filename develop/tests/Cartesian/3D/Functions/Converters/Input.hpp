#pragma once

#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>

namespace cgm_xyz_converters_tests_data
{

// ------------- A ------------- //

// axes and pos
static const auto A_X = CGM::Vector<3,double>{ 0.93358, 0.35837, 0.00000 };
static const auto A_Y = CGM::Vector<3,double>{ -0.35837, 0.93358, 0.00000 };
static const auto A_Z = CGM::Vector<3,double>{ 0.00000, 0.00000, 1.00000 };
static const auto A_P = CGM::Vector<3,double>{ 0.10000, 0.20000, 0.00000};

// orientation, space and orientation quaternion
static const auto A_MAT3 = CGM_XYZ::orientationMatrix(A_X, A_Y, A_Z);
static const auto A_MAT4 = CGM_XYZ::spaceMatrix(A_X, A_Y, A_Z, A_P);
static const auto A_QUAT = CGM::Quaternion<double>{0.00000, 0.00000, 0.18224, 0.98325};



// ------------- B ------------- //

// axes and pos
static const auto B_X = CGM::Vector<3,double> {0.70711, 0.00000, 0.70711};
static const auto B_Y = CGM::Vector<3,double> {0.00000, 1.00000, 0.00000};
static const auto B_Z = CGM::Vector<3,double> {-0.70711, 0.00000, 0.70711};
static const auto B_P = CGM::Vector<3,double> {-0.70000, 0.40000, 0.40000};

// orientation, space and orientation quaternion
static const auto B_MAT3 = CGM_XYZ::orientationMatrix(B_X, B_Y, B_Z);
static const auto B_MAT4 = CGM_XYZ::spaceMatrix(B_X, B_Y, B_Z, B_P);
static const auto B_QUAT = CGM::Quaternion<double>{0.00000, -0.38268, 0.00000, 0.92388};



// ------------- COORDS ------------- //

// input coord
static const auto A_LOCAL_COORD = CGM::Vector<3,double>{ 1.00000, 0.00000, 0.00000 };
static const auto GLOBAL_COORD = CGM::Vector<3,double>{ 1.00000, 0.00000, 0.00000 };

// output coord
static const auto A_LOCAL_COORD_CONVERTED_TO_GLOBAL__ORIENT_DIR = CGM::Vector<3,double>{ 0.93358, 0.358368, 0.0 };
static const auto A_LOCAL_COORD_CONVERTED_TO_GLOBAL__SPACE_POINT = CGM::Vector<3,double>{ 1.03358, 0.558368, 0.0 };

static const auto GLOBAL_COORD_CONVERTED_TO_LOCAL_A__ORIENT_DIR = CGM::Vector<3,double>{ 0.93358, -0.358368, 0.0 };
static const auto GLOBAL_COORD_CONVERTED_TO_LOCAL_A__SPACE_POINT = CGM::Vector<3,double>{ 0.768549, -0.509247, 0.0 };

static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT = CGM::Vector<3,double>{ 0.660141, 0.358368, -0.660141 };
static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_SPACE = CGM::Vector<3,double>{ 0.872272, -0.0416322, -1.43796 };
static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__SPACE_2_ORIENT = CGM::Vector<3,double>{ 0.730851, 0.558368, -0.730852 };
static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__SPACE_2_SPACE = CGM::Vector<3,double>{ 0.942983, 0.158368, -1.50867 };


}