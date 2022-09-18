

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/cartesian/3d/functions/converters/matrix3x3.hpp>
#include "../../input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, LocalToLocal_Mat3_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted(MAT3, A_MAT3, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_A2B, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, LocalToLocal_Mat3_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted(MAT3, A_MAT3, B_MAT4);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_A2B, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix3x3_Converters, LocalToLocal_Mat3_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted(MAT3, A_MAT3, B_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_A2B, 0.0001));
}