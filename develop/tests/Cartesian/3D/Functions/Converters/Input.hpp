#pragma once

#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>

namespace cgm_xyz_converters_tests_data
{

/* ####################################################################################### */
/* Input values */
/* ####################################################################################### */

static const auto X     = CGM::Vector<3,double>{ +0.88295, +0.46947, +0.00000 };
static const auto Y     = CGM::Vector<3,double>{ -0.45921, +0.86365, +0.20791 };
static const auto Z     = CGM::Vector<3,double>{ +0.09761, -0.18358, +0.97815 };
static const auto P     = CGM::Vector<3,double>{ +0.25000, +1.20000, -1.30000 };
static const auto MAT3  = CGM_XYZ::orientationMatrix(X, Y, Z);
static const auto MAT4  = CGM_XYZ::spaceMatrix(X, Y, Z, P);
static const auto VEC   = Y;

/* ####################################################################################### */
/* A orientation and basis */
/* ####################################################################################### */

static const auto A_X       = CGM::Vector<3,double>{ +0.93969, +0.00000, -0.34202 };
static const auto A_Y       = CGM::Vector<3,double>{ +0.00000, +1.00000, +0.00000 };
static const auto A_Z       = CGM::Vector<3,double>{ +0.34202, +0.00000, +0.93969 };
static const auto A_P       = CGM::Vector<3,double>{ -0.40000, +1.00000, +0.60000 };
static const auto A_MAT3    = CGM_XYZ::orientationMatrix(A_X, A_Y, A_Z);
static const auto A_MAT4    = CGM_XYZ::spaceMatrix(A_X, A_Y, A_Z, A_P);
static const auto A_QUAT    = CGM::Quaternion<double>{+0.00000, +0.17365, +0.00000, +0.98481};

/* ####################################################################################### */
/* B orientation and basis */
/* ####################################################################################### */

static const auto B_X       = CGM::Vector<3,double>{ +1.00000, +0.00000, +0.00000 };
static const auto B_Y       = CGM::Vector<3,double>{ +0.00000, +0.81915, +0.57358 };
static const auto B_Z       = CGM::Vector<3,double>{ +0.00000, -0.57358, +0.81915 };
static const auto B_P       = CGM::Vector<3,double>{ +0.20000, -0.50000, +0.00000 };
static const auto B_MAT3    = CGM_XYZ::orientationMatrix(B_X, B_Y, B_Z);
static const auto B_MAT4    = CGM_XYZ::spaceMatrix(B_X, B_Y, B_Z, B_P);
static const auto B_QUAT    = CGM::Quaternion<double>{+0.30071, +0.00000, +0.00000, +0.95372};

/* ####################################################################################### */
/* Expect vector */
/* ####################################################################################### */

static const auto EXPECT_VEC_TO_WORLD_REORIENTED    = CGM::Vector<3, double>{ -0.360407, +0.863650, +0.352432 };
static const auto EXPECT_VEC_TO_WORLD_REBASED       = CGM::Vector<3, double>{ -0.760407, +1.863650, +0.952432 };
static const auto EXPECT_VEC_TO_LOCAL_REORIENTED    = CGM::Vector<3, double>{ -0.502627, +0.863650, +0.038312 };
static const auto EXPECT_VEC_TO_LOCAL_REBASED       = CGM::Vector<3, double>{ +0.078464, -0.136350, -0.388694 };
static const auto EXPECT_VEC_A2B_MAT3_TO_MAT3       = CGM::Vector<3, double>{ -0.360406, +0.909605, -0.206679 };
static const auto EXPECT_VEC_A2B_MAT3_TO_MAT4       = CGM::Vector<3, double>{-0.560407, +1.319182, -0.493468 };
static const auto EXPECT_VEC_A2B_MAT4_TO_MAT3       = CGM::Vector<3, double>{-0.760407, +2.072905, -0.288768 };
static const auto EXPECT_VEC_A2B_MAT4_TO_MAT4       = CGM::Vector<3, double>{-0.960407, +2.482480, -0.575558 };

/* ####################################################################################### */
/* Expect 3x3 matrix */
/* ####################################################################################### */

static const auto EXPECT_MAT3_TO_WORLD = CGM_XYZ::orientationMatrix
(
    CGM::Vector<3, double>{ +0.829703, +0.469470, -0.301988 },
    CGM::Vector<3, double>{ -0.360407, +0.863650, +0.352432 },
    CGM::Vector<3, double>{ +0.426272, -0.183580, +0.885778 }
);

static const auto EXPECT_MAT3_TO_LOCAL = CGM_XYZ::orientationMatrix
(
    CGM::Vector<3, double>{ +0.829703, +0.469470, +0.301988 },
    CGM::Vector<3, double>{ -0.502627, +0.863650, +0.038312 },
    CGM::Vector<3, double>{ -0.242825, -0.183580, +0.952547 }
);

static const auto EXPECT_MAT3_A2B = CGM_XYZ::orientationMatrix
(
    CGM::Vector<3, double>{ +0.829699, +0.211353, -0.516651 },
    CGM::Vector<3, double>{ -0.360406, +0.909605, -0.206679 },
    CGM::Vector<3, double>{ +0.426270, +0.357682, +0.830878 }
);

}

#define CGM_PRINT(what) std::cout << "\n\n" << what << std::endl;