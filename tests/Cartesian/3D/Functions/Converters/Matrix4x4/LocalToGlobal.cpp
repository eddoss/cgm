

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters/Matrix4x4.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, LocalToGlobal_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_GLOBAL>(MAT4, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_TO_GLOBAL_BY_MAT3, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, LocalToGlobal_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_GLOBAL>(MAT4, A_MAT4);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_TO_GLOBAL_BY_MAT4, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Matrix4x4_Converters, LocalToGlobal_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_GLOBAL>(MAT4, A_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT4_TO_GLOBAL_BY_MAT3, 0.0001));
}
