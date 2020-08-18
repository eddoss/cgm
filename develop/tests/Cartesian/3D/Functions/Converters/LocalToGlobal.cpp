

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>


using namespace std;
using namespace CGM;

static const auto L2G_X = Vector<3,double>{ 0.86603, 0.00000, -0.50000 };
static const auto L2G_Y = Vector<3,double>{ 0.00000, 1.00000, 0.00000 };
static const auto L2G_Z = Vector<3,double>{ 0.50000, 0.00000, 0.86603 };
static const auto L2G_P = Vector<3,double>{ +0.2, +1.16, -0.6 };
static const auto L2G_MAT3 = CGM_XYZ::orientationMatrix(L2G_X, L2G_Y, L2G_Z);
static const auto L2G_MAT4 = CGM_XYZ::spaceMatrix(L2G_X, L2G_Y, L2G_Z, L2G_P);
static const auto L2G_QUAT = Quaternion<double>{ 0.00000, 0.25882, 0.00000, 0.96593 };

static const auto L2G_COORD = Vector<3,double>{ 1.0, 0.0, 0.0 };
static const auto L2G_EXPEC_P = Vector<3,double>{ 1.066025, 1.16, -1.1 }; // for point representation
static const auto L2G_EXPEC_D = Vector<3,double>{ 0.866025, 0.0, -0.5 }; // for direction representation

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Mat3)
{
    auto result = CGM_XYZ::localToGlobal(L2G_COORD, L2G_MAT3);
    ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_D, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Mat3WithPos)
{
    {
        auto result = CGM_XYZ::localToGlobal<CGM_POINT>(L2G_COORD, L2G_MAT3, L2G_P);
        ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_P, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToGlobal<CGM_DIRECTION>(L2G_COORD, L2G_MAT3, L2G_P);
        ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_D, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Mat4)
{
    {
        auto result = CGM_XYZ::localToGlobal<CGM_POINT>(L2G_COORD, L2G_MAT4);
        ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_P, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToGlobal<CGM_DIRECTION>(L2G_COORD, L2G_MAT4);
        ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_D, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Quat)
{
    auto result = CGM_XYZ::localToGlobal(L2G_COORD, L2G_QUAT);
    ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_D, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_QuatWithPos)
{
    {
        auto result = CGM_XYZ::localToGlobal<CGM_POINT>(L2G_COORD, L2G_QUAT, L2G_P);
        ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_P, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToGlobal<CGM_DIRECTION>(L2G_COORD, L2G_QUAT, L2G_P);
        ASSERT_TRUE(CGM::eq(result, L2G_EXPEC_D, 0.0001));
    }
}