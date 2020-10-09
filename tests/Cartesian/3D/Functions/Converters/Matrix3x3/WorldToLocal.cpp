

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Cartesian/3D/Functions/Converters/Matrix3x3.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, WorldToLocal_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted<CGM_LOCAL>(MAT3, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, WorldToLocal_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted<CGM_LOCAL>(MAT3, A_MAT4);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, WorldToLocal_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted<CGM_LOCAL>(MAT3, A_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL, 0.0001));
}