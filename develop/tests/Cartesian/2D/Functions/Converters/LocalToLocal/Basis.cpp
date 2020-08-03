

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Cartesian/2D/Types/Basis.hpp>
#include <Math3D/Cartesian/2D/Functions/Converters.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>
#include <Math3D/Cartesian/2D/Types/Enums.hpp>
#include <private/Math3D/Cartesian/2D/InternalUtils.hpp>

using namespace std;
using namespace MATH3D_NAMESPACE;

constexpr EVectorRepresentation L2L2DBASIS_POINT = EVectorRepresentation::Point;
constexpr EVectorRepresentation L2L2DBASIS_DIRECTION = EVectorRepresentation::Direction;

static const auto L2L2DBASIS_A_COORD = Vector<2,double>{ 3.13, 2.2 };

static const auto L2L2DBASIS_A_X = Vector<2,double>{ +0.966269, +0.257534 };
static const auto L2L2DBASIS_A_Y = Vector<2,double>{ -0.257534, +0.966269 };
static const auto L2L2DBASIS_A_P = Vector<2,double>{ +0.220015, +0.163540 };
static const auto L2L2DBASIS_A_BASIS_M2 = MATH3D_XY_NAMESPACE::Basis<MATH3D_XY_NAMESPACE::EBasisBase::Matrix2,double>(L2L2DBASIS_A_X, L2L2DBASIS_A_Y, L2L2DBASIS_A_P);
static const auto L2L2DBASIS_A_BASIS_M3 = MATH3D_XY_NAMESPACE::Basis<MATH3D_XY_NAMESPACE::EBasisBase::Matrix3,double>(L2L2DBASIS_A_X, L2L2DBASIS_A_Y, L2L2DBASIS_A_P);

static const auto L2L2DBASIS_B_X = Vector<2,double>{ -0.847930, -0.530108 };
static const auto L2L2DBASIS_B_Y = Vector<2,double>{ +0.530108, -0.847930 };
static const auto L2L2DBASIS_B_P = Vector<2,double>{ -0.027047, +0.423891 };
static const auto L2L2DBASIS_B_MAT2 = MATH3D_XY_NAMESPACE::orientationMatrix(L2L2DBASIS_B_X, L2L2DBASIS_B_Y);
static const auto L2L2DBASIS_B_MAT3 = MATH3D_XY_NAMESPACE::packBasis(L2L2DBASIS_B_X, L2L2DBASIS_B_Y, L2L2DBASIS_B_P);
static const auto L2L2DBASIS_B_BASIS_M2 = MATH3D_XY_NAMESPACE::Basis<MATH3D_XY_NAMESPACE::EBasisBase::Matrix2,double>(L2L2DBASIS_B_MAT3);
static const auto L2L2DBASIS_B_BASIS_M3 = MATH3D_XY_NAMESPACE::Basis<MATH3D_XY_NAMESPACE::EBasisBase::Matrix3,double>(L2L2DBASIS_B_MAT3);
static const auto L2L2DBASIS_B_COORD_PT_PT = Vector<2,double>{ -2.692830, -2.932848 };
static const auto L2L2DBASIS_B_COORD_PT_DIR = Vector<2,double>{ -2.445188, -3.277940 };
static const auto L2L2DBASIS_B_COORD_DIR_DIR = Vector<2,double>{ -2.345325, -3.022638 };

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Mat2)
{
    {
        auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_MAT2);
        auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_MAT2);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_MAT2);
        auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_MAT2);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Mat2WithPos)
{
    {
        auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_MAT2, L2L2DBASIS_B_P);
        auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_MAT2, L2L2DBASIS_B_P);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_MAT2, L2L2DBASIS_B_P);
        auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_MAT2, L2L2DBASIS_B_P);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Mat3)
{
    {
        auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_MAT3);
        auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_MAT3);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_MAT3);
        auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_MAT3);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Basis)
{
    {
        {
            auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_BASIS_M2);
            auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_BASIS_M2);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_BASIS_M2);
            auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_BASIS_M2);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
        }
    }

    {
        {
            auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_BASIS_M3);
            auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M2, L2L2DBASIS_B_BASIS_M3);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_POINT>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_BASIS_M3);
            auto result_d = MATH3D_XY_NAMESPACE::localToLocal<L2L2DBASIS_DIRECTION>(L2L2DBASIS_A_COORD, L2L2DBASIS_A_BASIS_M3, L2L2DBASIS_B_BASIS_M3);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_p, L2L2DBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(result_d, L2L2DBASIS_B_COORD_DIR_DIR, 0.0001));
        }
    }
}