

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/cartesian/3d/functions/converters/matrix4x4.hpp>
#include "../input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, GlobalToLocal_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_LOCAL>(MAT4, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_TO_LOCAL_BY_MAT3, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, GlobalToLocal_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_LOCAL>(MAT4, A_MAT4);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_TO_LOCAL_BY_MAT4, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, GlobalToLocal_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_LOCAL>(MAT4, A_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_TO_LOCAL_BY_MAT3, 0.0001));
}