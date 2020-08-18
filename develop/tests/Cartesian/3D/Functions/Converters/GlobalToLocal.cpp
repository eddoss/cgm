

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>


using namespace std;
using namespace CGM;

static const auto G2L_X = Vector<3,double>{ 0.86603, 0.00000, -0.50000 };
static const auto G2L_Y = Vector<3,double>{ 0.00000, 1.00000, 0.00000 };
static const auto G2L_Z = Vector<3,double>{ 0.50000, 0.00000, 0.86603 };
static const auto G2L_P = Vector<3,double>{ +0.2, +1.16, -0.6 };
static const auto G2L_MAT3 = CGM_XYZ::orientationMatrix(G2L_X, G2L_Y, G2L_Z);
static const auto G2L_MAT4 = CGM_XYZ::spaceMatrix(G2L_X, G2L_Y, G2L_Z, G2L_P);
static const auto G2L_QUAT = Quaternion<double>{ 0.00000, 0.25882, 0.00000, 0.96593 };

static const auto G2L_EXPEC = Vector<3,double>{ 1.0, 0.0, 0.0 };
static const auto G2L_COORD_P = Vector<3,double>{ 1.066025, 1.16, -1.1 }; // for point representation
static const auto G2L_COORD_D = Vector<3,double>{ 0.866025, 0.0, -0.5 }; // for direction representation

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3)
{
    auto result = CGM_XYZ::globalToLocal(G2L_COORD_D, G2L_MAT3);
    ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3WithPos)
{
    {
        auto result = CGM_XYZ::globalToLocal<CGM_POINT>(G2L_COORD_P, G2L_MAT3, G2L_P);
        ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
    }

    {
        auto result = CGM_XYZ::globalToLocal<CGM_DIRECTION>(G2L_COORD_D, G2L_MAT3, G2L_P);
        ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat4)
{
    {
        auto result = CGM_XYZ::globalToLocal<CGM_POINT>(G2L_COORD_P, G2L_MAT4);
        ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
    }

    {
        auto result = CGM_XYZ::globalToLocal<CGM_DIRECTION>(G2L_COORD_D, G2L_MAT4);
        ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Quat)
{
    auto result = CGM_XYZ::globalToLocal(G2L_COORD_D, G2L_QUAT);
    ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_QuatWithPos)
{
    {
        auto result = CGM_XYZ::globalToLocal<CGM_POINT>(G2L_COORD_P, G2L_QUAT, G2L_P);
        ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
    }

    {
        auto result = CGM_XYZ::globalToLocal<CGM_DIRECTION>(G2L_COORD_D, G2L_QUAT, G2L_P);
        ASSERT_TRUE(CGM::eq(result, G2L_EXPEC, 0.0001));
    }
}