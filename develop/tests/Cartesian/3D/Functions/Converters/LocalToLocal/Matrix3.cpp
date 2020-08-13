

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/BasisPackers.hpp>
#include <CGM/detail/Modules/Cartesian/3D/InternalUtils.hpp>


using namespace std;
using namespace CGM;

constexpr EVectorRepresentation L2LMAT3_POINT = EVectorRepresentation::Point;
constexpr EVectorRepresentation L2LMAT3_DIRECTION = EVectorRepresentation::Direction;

static const auto L2LMAT3_A_COORD = Vector<3,double>{ 3.13, 2.2, 1.7 };

static const auto L2LMAT3_A_X = Vector<3,double>{ +0.559270, +0.302442, -0.77184 };
static const auto L2LMAT3_A_Y = Vector<3,double>{ -0.313298, +0.939132, +0.14098 };
static const auto L2LMAT3_A_Z = Vector<3,double>{ +0.767503, +0.162971, +0.61998 };
static const auto L2LMAT3_A_MAT3 = CGM_XYZ::orientationMatrix(L2LMAT3_A_X, L2LMAT3_A_Y, L2LMAT3_A_Z);

static const auto L2LMAT3_B_X = Vector<3,double>{ +0.915829, -0.386754, -0.108065 };
static const auto L2LMAT3_B_Y = Vector<3,double>{ +0.367711, +0.915829, -0.161386 };
static const auto L2LMAT3_B_Z = Vector<3,double>{ +0.161386, +0.108065, +0.980957 };
static const auto L2LMAT3_B_P = Vector<3,double>{ +4.030000, +1.700000, +2.200000 };
static const auto L2LMAT3_B_QUAT = Quaternion<double>{ -0.068998, 0.068998, -0.193196, 0.976296 };
static const auto L2LMAT3_B_MAT4 = CGM_XYZ::packBasis(L2LMAT3_B_X, L2LMAT3_B_Y, L2LMAT3_B_Z, L2LMAT3_B_P);
static const auto L2LMAT3_B_MAT3 = CGM_XYZ::orientationMatrix(L2LMAT3_B_X, L2LMAT3_B_Y, L2LMAT3_B_Z);
static const auto L2LMAT3_B_COORD_PT = Vector<3,double>{ -2.557181, +0.962929, +1.960766 };
static const auto L2LMAT3_B_COORD_DIR = Vector<3,double>{ +2.113769, +1.198966, +3.409012 };

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat3)
{
    auto result = CGM_XYZ::localToLocal(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_MAT3);
    ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_DIR, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat3WithPos)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT3_POINT>(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_MAT3, L2LMAT3_B_P);
        ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_PT, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT3_DIRECTION>(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_MAT3, L2LMAT3_B_P);
        ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat4)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT3_POINT>(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_MAT4);
        ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_PT, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT3_DIRECTION>(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_MAT4);
        ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Quat)
{
    auto result = CGM_XYZ::localToLocal(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_QUAT);
    ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_DIR, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_QuatWithPos)
{
    {
        auto result = CGM_XYZ::localToLocal<L2LMAT3_POINT>(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_QUAT, L2LMAT3_B_P);
        ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_PT, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToLocal<L2LMAT3_DIRECTION>(L2LMAT3_A_COORD, L2LMAT3_A_MAT3, L2LMAT3_B_QUAT, L2LMAT3_B_P);
        ASSERT_TRUE(CGM::eq(result, L2LMAT3_B_COORD_DIR, 0.0001));
    }
}