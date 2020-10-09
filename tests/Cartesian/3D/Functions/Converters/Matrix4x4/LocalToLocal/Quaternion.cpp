

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Cartesian/3D/Functions/Converters/Matrix4x4.hpp>
#include "../../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, LocalToLocal_Quat_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(MAT4, A_QUAT, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_A2B_MAT3_TO_MAT3, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, LocalToLocal_Quat_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(MAT4, A_QUAT, B_MAT4);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_A2B_MAT3_TO_MAT4, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, LocalToLocal_Quat_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(MAT4, A_QUAT, B_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_A2B_MAT3_TO_MAT3, 0.0001));
}
