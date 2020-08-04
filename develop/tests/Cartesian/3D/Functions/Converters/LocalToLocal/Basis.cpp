

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Basis.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>


using namespace std;
using namespace CGM;

constexpr EVectorRepresentation L2LBASIS_POINT = EVectorRepresentation::Point;
constexpr EVectorRepresentation L2LBASIS_DIRECTION = EVectorRepresentation::Direction;

static const auto L2LBASIS_A_COORD = Vector<3,double>{ 3.13, 2.2, 1.7 };

static const auto L2LBASIS_A_P = Vector<3,double>{ -1.200000, -0.600000, +4.40000 };
static const auto L2LBASIS_A_QUAT = Quaternion<double>{ -0.006227, 0.435855, 0.174342, 0.882948 };
static const auto L2LBASIS_A_BASIS_Q = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Quaternion,double>(L2LBASIS_A_QUAT, L2LBASIS_A_P);
static const auto L2LBASIS_A_BASIS_M3 = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Matrix3,double>(L2LBASIS_A_QUAT, L2LBASIS_A_P);
static const auto L2LBASIS_A_BASIS_M4 = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Matrix4,double>(L2LBASIS_A_QUAT, L2LBASIS_A_P);

static const auto L2LBASIS_B_X = Vector<3,double>{ +0.915829, -0.386754, -0.108065 };
static const auto L2LBASIS_B_Y = Vector<3,double>{ +0.367711, +0.915829, -0.161386 };
static const auto L2LBASIS_B_Z = Vector<3,double>{ +0.161386, +0.108065, +0.980957 };
static const auto L2LBASIS_B_P = Vector<3,double>{ +4.030000, +1.700000, +2.200000 };
static const auto L2LBASIS_B_QUAT = Quaternion<double>{ -0.068998, 0.068998, -0.193196, 0.976296 };
static const auto L2LBASIS_B_MAT4 = CGM_XYZ::packBasis(L2LBASIS_B_X, L2LBASIS_B_Y, L2LBASIS_B_Z, L2LBASIS_B_P);
static const auto L2LBASIS_B_MAT3 = CGM_XYZ::orientationMatrix(L2LBASIS_B_X, L2LBASIS_B_Y, L2LBASIS_B_Z);
static const auto L2LBASIS_B_BASIS_Q = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Quaternion,double>(L2LBASIS_B_QUAT, L2LBASIS_B_P);
static const auto L2LBASIS_B_BASIS_M3 = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Matrix3,double>(L2LBASIS_B_MAT3, L2LBASIS_B_P);
static const auto L2LBASIS_B_BASIS_M4 = CGM_XYZ::Basis<CGM_XYZ::EBasisBase::Matrix4,double>(L2LBASIS_B_MAT3, L2LBASIS_B_P);
static const auto L2LBASIS_B_COORD_PT_PT = Vector<3,double>{ -3.166704, +1.353024, +6.503487 };
static const auto L2LBASIS_B_COORD_PT_DIR = Vector<3,double>{ +1.504246, +1.589060, +7.951732 };
static const auto L2LBASIS_B_COORD_DIR_DIR = Vector<3,double>{ +2.113769, +1.198966, +3.409012 };

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Mat3)
{
    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_MAT3);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_MAT3);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_MAT3);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_MAT3);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_MAT3);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_MAT3);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Mat3WithPos)
{
    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_MAT3, L2LBASIS_B_P);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_MAT3, L2LBASIS_B_P);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_MAT3, L2LBASIS_B_P);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_MAT3, L2LBASIS_B_P);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_MAT3, L2LBASIS_B_P);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_MAT3, L2LBASIS_B_P);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Mat4)
{
    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_MAT4);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_MAT4);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_MAT4);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_MAT4);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_MAT4);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_MAT4);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Quat)
{
    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_QUAT);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_QUAT);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_QUAT);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_QUAT);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_QUAT);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_QUAT);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_DIR, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_QuatWithPos)
{
    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_QUAT, L2LBASIS_B_P);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_QUAT, L2LBASIS_B_P);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_QUAT, L2LBASIS_B_P);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_QUAT, L2LBASIS_B_P);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_QUAT, L2LBASIS_B_P);
        auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_QUAT, L2LBASIS_B_P);
        ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_BasisStruct_Basis)
{
    {
        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_BASIS_Q);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_BASIS_Q);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_BASIS_Q);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_BASIS_Q);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_BASIS_Q);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_BASIS_Q);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }
    }

    {
        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_BASIS_M3);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_BASIS_M3);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_BASIS_M3);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_BASIS_M3);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_BASIS_M3);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_BASIS_M3);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }
    }

    {
        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_BASIS_M4);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_Q, L2LBASIS_B_BASIS_M4);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_BASIS_M4);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M3, L2LBASIS_B_BASIS_M4);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }

        {
            auto result_p = CGM_XYZ::localToLocal<L2LBASIS_POINT>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_BASIS_M4);
            auto result_d = CGM_XYZ::localToLocal<L2LBASIS_DIRECTION>(L2LBASIS_A_COORD, L2LBASIS_A_BASIS_M4, L2LBASIS_B_BASIS_M4);
            ASSERT_TRUE(CGM::eq(result_p, L2LBASIS_B_COORD_PT_PT, 0.0001));
            ASSERT_TRUE(CGM::eq(result_d, L2LBASIS_B_COORD_DIR_DIR, 0.0001));
        }
    }
}