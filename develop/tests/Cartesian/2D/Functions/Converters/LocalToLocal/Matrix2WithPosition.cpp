

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Core/Functions/Quaternion.hpp>
#include <CGM/Cartesian/2D/Types/Basis.hpp>
#include <CGM/Cartesian/2D/Functions/Converters.hpp>
#include <CGM/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/Cartesian/2D/Types/Enums.hpp>
#include <private/CGM/Cartesian/2D/InternalUtils.hpp>

using namespace std;
using namespace CGM;

constexpr EVectorRepresentation L2L2DMAT2P_POINT = EVectorRepresentation::Point;
constexpr EVectorRepresentation L2L2DMAT2P_DIRECTION = EVectorRepresentation::Direction;

static const auto L2L2DMAT2P_A_COORD = Vector<2,double>{ 3.13, 2.2 };

static const auto L2L2DMAT2P_A_X = Vector<2,double>{ +0.966269, +0.257534 };
static const auto L2L2DMAT2P_A_Y = Vector<2,double>{ -0.257534, +0.966269 };
static const auto L2L2DMAT2P_A_P = Vector<2,double>{ +0.220015, +0.163540 };
static const auto L2L2DMAT2P_A_MAT2 = CGM_XY::orientationMatrix(L2L2DMAT2P_A_X, L2L2DMAT2P_A_Y);

static const auto L2L2DMAT2P_B_X = Vector<2,double>{ -0.847930, -0.530108 };
static const auto L2L2DMAT2P_B_Y = Vector<2,double>{ +0.530108, -0.847930 };
static const auto L2L2DMAT2P_B_P = Vector<2,double>{ -0.027047, +0.423891 };
static const auto L2L2DMAT2P_B_MAT2 = CGM_XY::orientationMatrix(L2L2DMAT2P_B_X, L2L2DMAT2P_B_Y);
static const auto L2L2DMAT2P_B_MAT3 = CGM_XY::packBasis(L2L2DMAT2P_B_X, L2L2DMAT2P_B_Y, L2L2DMAT2P_B_P);
static const auto L2L2DMAT2P_B_BASIS_M2 = CGM_XY::Basis<CGM_XY::EBasisBase::Matrix2,double>(L2L2DMAT2P_B_MAT3);
static const auto L2L2DMAT2P_B_BASIS_M3 = CGM_XY::Basis<CGM_XY::EBasisBase::Matrix3,double>(L2L2DMAT2P_B_MAT3);
static const auto L2L2DMAT2P_B_COORD_PT_PT = Vector<2,double>{ -2.692830, -2.932848 };
static const auto L2L2DMAT2P_B_COORD_PT_DIR = Vector<2,double>{ -2.445188, -3.277940 };
static const auto L2L2DMAT2P_B_COORD_DIR_DIR = Vector<2,double>{ -2.345325, -3.022638 };


TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat2WithPos_Mat2)
{
    {
        auto result = CGM_XY::localToLocal<L2L2DMAT2P_POINT>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_MAT2);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT2P_B_COORD_PT_DIR, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<L2L2DMAT2P_DIRECTION>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_MAT2);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT2P_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat2WithPos_Mat2WithPos)
{
    {
        auto result = CGM_XY::localToLocal<L2L2DMAT2P_POINT>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_MAT2, L2L2DMAT2P_B_P);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT2P_B_COORD_PT_PT, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<L2L2DMAT2P_DIRECTION>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_MAT2, L2L2DMAT2P_B_P);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT2P_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat2WithPos_Mat3)
{
    {
        auto result = CGM_XY::localToLocal<L2L2DMAT2P_POINT>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_MAT3);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT2P_B_COORD_PT_PT, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<L2L2DMAT2P_DIRECTION>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_MAT3);
        ASSERT_TRUE(CGM::eq(result, L2L2DMAT2P_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat2WithPos_Basis)
{
    {
        auto result_p = CGM_XY::localToLocal<L2L2DMAT2P_POINT>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_BASIS_M2);
        auto result_d = CGM_XY::localToLocal<L2L2DMAT2P_DIRECTION>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_BASIS_M2);
        ASSERT_TRUE(CGM::eq(result_p, L2L2DMAT2P_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2L2DMAT2P_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XY::localToLocal<L2L2DMAT2P_POINT>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_BASIS_M3);
        auto result_d = CGM_XY::localToLocal<L2L2DMAT2P_DIRECTION>(L2L2DMAT2P_A_COORD, L2L2DMAT2P_A_MAT2, L2L2DMAT2P_A_P, L2L2DMAT2P_B_BASIS_M3);
        ASSERT_TRUE(CGM::eq(result_p, L2L2DMAT2P_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2L2DMAT2P_B_COORD_DIR_DIR, 0.0001));
    }
}