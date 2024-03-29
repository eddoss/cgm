#pragma once


#include <gtest/gtest.h>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/cartesian/2d/functions/utils.hpp>
#include <cgm/modules/cartesian/2d/functions/orientation.hpp>


namespace cgm_xy_converters_tests_data
{

/* ####################################################################################### */
/* Input values */
/* ####################################################################################### */

static const auto X     = CGM::Vector<2,double>{ +0.88295, +0.46947 };
static const auto Y     = CGM::Vector<2,double>{ -0.46947, +0.88295 };
static const auto P     = CGM::Vector<2,double>{ +0.25000, +1.20000 };
static const auto MAT2  = CGM_2D::orientationMatrix(X, Y);
static const auto MAT3  = CGM_2D::spaceMatrix(X, Y, P);
static const auto VEC   = Y;

/* ####################################################################################### */
/* A orientation and basis */
/* ####################################################################################### */

static const auto A_X       = CGM::Vector<2,double>{ +0.39073, +0.92050 };
static const auto A_Y       = CGM::Vector<2,double>{ -0.92050, +0.39073 };
static const auto A_P       = CGM::Vector<2,double>{ -0.40000, +0.00000 };
static const auto A_MAT2    = CGM_2D::orientationMatrix(A_X, A_Y);
static const auto A_MAT3    = CGM_2D::spaceMatrix(A_X, A_Y, A_P);

/* ####################################################################################### */
/* B orientation and basis */
/* ####################################################################################### */

static const auto B_X       = CGM::Vector<2,double>{ +0.73135, -0.68200 };
static const auto B_Y       = CGM::Vector<2,double>{ +0.68200, +0.73135 };
static const auto B_P       = CGM::Vector<2,double>{ +0.20000, -0.50000 };
static const auto B_MAT2    = CGM_2D::orientationMatrix(B_X, B_Y);
static const auto B_MAT3    = CGM_2D::spaceMatrix(B_X, B_Y, B_P);

/* ####################################################################################### */
/* Expect vector */
/* ####################################################################################### */

static const auto EXPECT_VEC_TO_GLOBAL_REORIENTED   = CGM::Vector<2, double>{ -0.996201, -0.087153 };
static const auto EXPECT_VEC_TO_GLOBAL_REBASED      = CGM::Vector<2, double>{ -1.396201, -0.087153 };
static const auto EXPECT_VEC_TO_LOCAL_REORIENTED    = CGM::Vector<2, double>{ +0.629319, +0.777142 };
static const auto EXPECT_VEC_TO_LOCAL_REBASED       = CGM::Vector<2, double>{ +0.785611, +0.408942 };
static const auto EXPECT_VEC_A2B_MAT2_TO_MAT2       = CGM::Vector<2, double>{ -0.669133, -0.743149 };
static const auto EXPECT_VEC_A2B_MAT2_TO_MAT3       = CGM::Vector<2, double>{ -1.156403, -0.513874 };
static const auto EXPECT_VEC_A2B_MAT3_TO_MAT2       = CGM::Vector<2, double>{ -0.961673, -1.015949 };
static const auto EXPECT_VEC_A2B_MAT3_TO_MAT3       = CGM::Vector<2, double>{ -1.448943, -0.786674 };

/* ####################################################################################### */
/* Expect 2x2 matrix */
/* ####################################################################################### */

static const auto EXPECT_MAT2_TO_GLOBAL = CGM_2D::orientationMatrix
(
    CGM::Vector<2, double>{ -0.087152, +0.996191 },
    CGM::Vector<2, double>{ -0.996191, -0.087152 }
);

static const auto EXPECT_MAT2_TO_LOCAL = CGM_2D::orientationMatrix
(
    CGM::Vector<2, double>{ +0.777150, -0.629326 },
    CGM::Vector<2, double>{ +0.629326, +0.777150 }
);

static const auto EXPECT_MAT2_A2B = CGM_2D::orientationMatrix
(
    CGM::Vector<2, double>{ -0.743144, +0.669129 },
    CGM::Vector<2, double>{ -0.669129, -0.743144 }
);

/* ####################################################################################### */
/* Expect 3x3 matrix */
/* ####################################################################################### */

static const auto EXPECT_MAT3_TO_GLOBAL_BY_MAT2 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ -0.087152, +0.996191 },
    CGM::Vector<2, double>{ -0.996191, -0.087152 },
    CGM::Vector<2, double>{ -1.006918, +0.699001 }
);

static const auto EXPECT_MAT3_TO_GLOBAL_BY_MAT3 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ -0.087153, +0.996201 },
    CGM::Vector<2, double>{ -0.996201, -0.087153 },
    CGM::Vector<2, double>{ -1.406927, +0.699008 }
);

static const auto EXPECT_MAT3_TO_LOCAL_BY_MAT2 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ +0.777150, -0.629326 },
    CGM::Vector<2, double>{ +0.629326, +0.777150 },
    CGM::Vector<2, double>{ +1.202294, +0.238753 }
);

static const auto EXPECT_MAT3_TO_LOCAL_BY_MAT3 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ +0.777150, -0.629326 },
    CGM::Vector<2, double>{ +0.629326, +0.777150 },
    CGM::Vector<2, double>{ +0.560860, +0.948270 }
);

static const auto EXPECT_MAT3_A2B_MAT2_TO_MAT2 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ -0.743144, +0.669129 },
    CGM::Vector<2, double>{ -0.669129, -0.743144 },
    CGM::Vector<2, double>{ -1.213132, -0.175504 }
);

static const auto EXPECT_MAT3_A2B_MAT2_TO_MAT3 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ -0.743144, +0.669129 },
    CGM::Vector<2, double>{ -0.669129, -0.743144 },
    CGM::Vector<2, double>{ -1.192853, +0.193603 }
);

static const auto EXPECT_MAT3_A2B_MAT3_TO_MAT2 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ -0.743151, +0.669136 },
    CGM::Vector<2, double>{ -0.669136, -0.743151 },
    CGM::Vector<2, double>{ -1.505684, -0.448307 }
);

static const auto EXPECT_MAT3_A2B_MAT3_TO_MAT3 = CGM_2D::spaceMatrix
(
    CGM::Vector<2, double>{ -0.743144, +0.669129 },
    CGM::Vector<2, double>{ -0.669129, -0.743144 },
    CGM::Vector<2, double>{ -1.592853, +0.193603 }
);
}