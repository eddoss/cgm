

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Core/Functions/Vector.hpp>
#include <CGM/detail/Cartesian/3D/Functions/Converters/Matrix3x3.hpp>
#include "../../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, LocalToLocal_Quat_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(MAT3, A_QUAT, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_A2B, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, LocalToLocal_Quat_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(MAT3, A_QUAT, B_MAT4);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_A2B, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, LocalToLocal_Quat_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(MAT3, A_QUAT, B_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_A2B, 0.0001));
}