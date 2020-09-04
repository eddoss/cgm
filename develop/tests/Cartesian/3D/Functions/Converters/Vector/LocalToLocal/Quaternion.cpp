

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters/Vector.hpp>
#include "../../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToLocal_Quat_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(VEC, A_QUAT, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT3, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToLocal_Quat_Mat3WithPos)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(VEC, A_QUAT, B_MAT3, B_P);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT4, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToLocal_Quat_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    {
        auto result = CGM_XYZ::converted<CGM_POINT>(VEC, A_QUAT, B_MAT4);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT4, 0.0001));
    }

    {
        auto result = CGM_XYZ::converted<CGM_DIRECTION>(VEC, A_QUAT, B_MAT4);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT3, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToLocal_Quat_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(VEC, A_QUAT, B_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT3, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToLocal_Quat_QuatWithPos)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::converted(VEC, A_QUAT, B_QUAT, B_P);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT4, 0.0001));
}