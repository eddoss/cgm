#pragma once

#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Orientation.hpp>

namespace cgm_xy_converters_tests_data
{

// ------------- A ------------- //

// axes and pos
static const auto A_X = CGM::Vector<2,double>{ 0.93358, 0.35837 };
static const auto A_Y = CGM::Vector<2,double>{ -0.35837, 0.93358};
static const auto A_P = CGM::Vector<2,double>{ 0.10000, 0.20000};

// orientation, space and orientation quaternion
static const auto A_MAT2 = CGM_XY::orientationMatrix(A_X, A_Y);
static const auto A_MAT3 = CGM_XY::spaceMatrix(A_X, A_Y, A_P);



// ------------- B ------------- //

// axes and pos
static const auto B_X = CGM::Vector<2,double> {0.96858, -0.24869};
static const auto B_Y = CGM::Vector<2,double> {0.24869, 0.96858};
static const auto B_P = CGM::Vector<2,double> {-0.70000, 0.40000};

// orientation, space and orientation quaternion
static const auto B_MAT2 = CGM_XY::orientationMatrix(B_X, B_Y);
static const auto B_MAT3 = CGM_XY::spaceMatrix(B_X, B_Y, B_P);



// ------------- COORDS ------------- //

// input coord
static const auto A_LOCAL_COORD = CGM::Vector<2,double>{ 1.00000, 0.00000 };
static const auto GLOBAL_COORD = CGM::Vector<2,double>{ 1.00000, 0.00000 };

// output coord
static const auto A_LOCAL_COORD_CONVERTED_TO_GLOBAL__ORIENT_DIR = CGM::Vector<2,double>{ 0.933579, 0.358370 };
static const auto A_LOCAL_COORD_CONVERTED_TO_GLOBAL__SPACE_POINT = CGM::Vector<2,double>{ 1.03358, 0.558368 };

static const auto GLOBAL_COORD_CONVERTED_TO_LOCAL_A__ORIENT_DIR = CGM::Vector<2,double>{ 0.93358, -0.358368 };
static const auto GLOBAL_COORD_CONVERTED_TO_LOCAL_A__SPACE_POINT = CGM::Vector<2,double>{ 0.768549, -0.509247 };

static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT = CGM::Vector<2,double>{ 0.81512, 0.57928 };
static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_SPACE = CGM::Vector<2,double>{ 1.592605, 0.36593 };
static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__SPACE_2_ORIENT = CGM::Vector<2,double>{ 0.862243, 0.79786 };
static const auto A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__SPACE_2_SPACE = CGM::Vector<2,double>{ 1.6397258, 0.58451 };

}