

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Core/Functions/Quaternion.hpp>
#include <CGM/Cartesian/3D/Types/Basis.hpp>
#include <CGM/Cartesian/3D/Functions/Converters.hpp>
#include <CGM/IO.hpp>

using namespace std;
using namespace CGM;

constexpr EVectorRepresentation L2LMAT4_POINT = EVectorRepresentation::Point;
constexpr EVectorRepresentation L2LMAT4_DIRECTION = EVectorRepresentation::Direction;

static const auto L2LMAT4_A_COORD = Vector<3,double>{ 3.13, 2.2, 1.7 };

static const auto L2LMAT4_A_X = Vector<3,double>{ +0.559270, +0.302442, -0.77184 };
static const auto L2LMAT4_A_Y = Vector<3,double>{ -0.313298, +0.939132, +0.14098 };
static const auto L2LMAT4_A_Z = Vector<3,double>{ +0.767503, +0.162971, +0.61998 };
static const auto L2LMAT4_A_P = Vector<3,double>{ -1.200000, -0.600000, +4.40000 };
static const auto L2LMAT4_A_MAT4 = CGM_XYZ::packBasis(L2LMAT4_A_X, L2LMAT4_A_Y, L2LMAT4_A_Z, L2LMAT4_A_P);

static const auto L2LMAT4_B_X = Vector<3,double>{ +0.915829, -0.386754, -0.108065 };
static const auto L2LMAT4_B_Y = Vector<3,double>{ +0.367711, +0.915829, -0.161386 };
static const auto L2LMAT4_B_Z = Vector<3,double>{ +0.161386, +0.108065, +0.980957 };
static const auto L2LMAT4_B_P = Vector<3,double>{ +4.030000, +1.700000, +2.200000 };
static const auto L2LMAT4_B_QUAT = Quaternion<double>{ -0.068998, 0.068998, -0.193196, 0.976296 };
static const auto L2LMAT4_B_MAT4 = CGM_XYZ::packBasis(L2LMAT4_B_X, L2LMAT4_B_Y, L2LMAT4_B_Z, L2LMAT4_B_P);
static const auto L2LMAT4_B_MAT3 = CGM_XYZ::orientationMatrix(L2LMAT4_B_X, L2LMAT4_B_Y, L2LMAT4_B_Z);
static const auto L2LMAT4_B_BASIS_Q = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Quaternion,double>(L2LMAT4_B_QUAT, L2LMAT4_B_P);
static const auto L2LMAT4_B_BASIS_M3 = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Matrix3,double>(L2LMAT4_B_MAT3, L2LMAT4_B_P);
static const auto L2LMAT4_B_BASIS_M4 = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Matrix4,double>(L2LMAT4_B_MAT3, L2LMAT4_B_P);
static const auto L2LMAT4_B_COORD_PT_PT = Vector<3,double>{ -3.166704, +1.353024, +6.503487 };
static const auto L2LMAT4_B_COORD_PT_DIR = Vector<3,double>{ +1.504246, +1.589060, +7.951732 };
static const auto L2LMAT4_B_COORD_DIR_DIR = Vector<3,double>{ +2.113769, +1.198966, +3.409012 };

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat4_Mat3)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_MAT3);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_PT_DIR, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_MAT3);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat4_Mat3WithPos)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_MAT3, L2LMAT4_B_P);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_PT_PT, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_MAT3, L2LMAT4_B_P);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat4_Mat4)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_MAT4);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_PT_PT, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_MAT4);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat4_Quat)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_QUAT);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_PT_DIR, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_QUAT);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat4_QuatWithPos)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_QUAT, L2LMAT4_B_P);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_PT_PT, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_QUAT, L2LMAT4_B_P);
        ASSERT_TRUE(CGM::equal(result, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat4_Basis)
{
    {
        auto result_p = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_BASIS_Q);
        auto result_d = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_BASIS_Q);
        ASSERT_TRUE(CGM::equal(result_p, L2LMAT4_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::equal(result_d, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_BASIS_M3);
        auto result_d = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_BASIS_M3);
        ASSERT_TRUE(CGM::equal(result_p, L2LMAT4_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::equal(result_d, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LMAT4_POINT>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_BASIS_M4);
        auto result_d = CGM_XYZ::localToLocal<L2LMAT4_DIRECTION>(L2LMAT4_A_COORD, L2LMAT4_A_MAT4, L2LMAT4_B_BASIS_M4);

        ASSERT_TRUE(CGM::equal(result_p, L2LMAT4_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::equal(result_d, L2LMAT4_B_COORD_DIR_DIR, 0.0001));
    }
}