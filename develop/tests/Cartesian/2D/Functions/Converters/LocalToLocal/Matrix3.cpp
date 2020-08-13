

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Converters.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Orientation.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/BasisPackers.hpp>


using namespace std;
using namespace CGM;

constexpr EVectorRepresentation L2L2DMAT3_POINT = EVectorRepresentation::Point;
constexpr EVectorRepresentation L2L2DMAT3_DIRECTION = EVectorRepresentation::Direction;

static const auto L2L2DMAT3_A_COORD = Vector<2,double>{ 3.13, 2.2 };

static const auto L2L2DMAT3_A_X = Vector<2,double>{ +0.966269, +0.257534 };
static const auto L2L2DMAT3_A_Y = Vector<2,double>{ -0.257534, +0.966269 };
static const auto L2L2DMAT3_A_P = Vector<2,double>{ +0.220015, +0.163540 };
static const auto L2L2DMAT3_A_MAT3 = CGM_XY::packBasis(L2L2DMAT3_A_X, L2L2DMAT3_A_Y, L2L2DMAT3_A_P);

static const auto L2L2DMAT3_B_X = Vector<2,double>{ -0.847930, -0.530108 };
static const auto L2L2DMAT3_B_Y = Vector<2,double>{ +0.530108, -0.847930 };
static const auto L2L2DMAT3_B_P = Vector<2,double>{ -0.027047, +0.423891 };
static const auto L2L2DMAT3_B_MAT2 = CGM_XY::orientationMatrix(L2L2DMAT3_B_X, L2L2DMAT3_B_Y);
static const auto L2L2DMAT3_B_MAT3 = CGM_XY::packBasis(L2L2DMAT3_B_X, L2L2DMAT3_B_Y, L2L2DMAT3_B_P);
static const auto L2L2DMAT3_B_COORD_PT_PT = Vector<2,double>{ -2.692830, -2.932848 };
static const auto L2L2DMAT3_B_COORD_PT_DIR = Vector<2,double>{ -2.445188, -3.277940 };
static const auto L2L2DMAT3_B_COORD_DIR_DIR = Vector<2,double>{ -2.345325, -3.022638 };

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat3_Mat2)
{
    {
        auto result = CGM_XY::localToLocal<L2L2DMAT3_POINT>(L2L2DMAT3_A_COORD, L2L2DMAT3_A_MAT3, L2L2DMAT3_B_MAT2);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT3_B_COORD_PT_DIR, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<L2L2DMAT3_DIRECTION>(L2L2DMAT3_A_COORD, L2L2DMAT3_A_MAT3, L2L2DMAT3_B_MAT2);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT3_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat3_Mat2WithPos)
{
    {
        auto result = CGM_XY::localToLocal<L2L2DMAT3_POINT>(L2L2DMAT3_A_COORD, L2L2DMAT3_A_MAT3, L2L2DMAT3_B_MAT2, L2L2DMAT3_B_P);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT3_B_COORD_PT_PT, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<L2L2DMAT3_DIRECTION>(L2L2DMAT3_A_COORD, L2L2DMAT3_A_MAT3, L2L2DMAT3_B_MAT2, L2L2DMAT3_B_P);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT3_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat3_Mat3)
{
    {
        auto result = CGM_XY::localToLocal<L2L2DMAT3_POINT>(L2L2DMAT3_A_COORD, L2L2DMAT3_A_MAT3, L2L2DMAT3_B_MAT3);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT3_B_COORD_PT_PT, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<L2L2DMAT3_DIRECTION>(L2L2DMAT3_A_COORD, L2L2DMAT3_A_MAT3, L2L2DMAT3_B_MAT3);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT3_B_COORD_DIR_DIR, 0.0001));
    }
}