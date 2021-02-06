

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Cartesian/3D/Functions/Converters/Vector.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToGlobal_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_GLOBAL>(VEC, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_GLOBAL_REORIENTED, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToGlobal_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    {
        auto result = CGM::converted<CGM_GLOBAL,CGM_POINT>(VEC, A_MAT4);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_GLOBAL_REBASED, 0.0001));
    }

    {
        auto result = CGM::converted<CGM_GLOBAL,CGM_DIRECTION>(VEC, A_MAT4);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_GLOBAL_REORIENTED, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, LocalToGlobal_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_GLOBAL>(VEC, A_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_GLOBAL_REORIENTED, 0.0001));
}