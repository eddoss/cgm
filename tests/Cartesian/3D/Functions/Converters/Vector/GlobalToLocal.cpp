

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters/Vector.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Vector_Converters, GlobalToLocal_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_LOCAL>(VEC, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REORIENTED, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, GlobalToLocal_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    {
        auto result = CGM::converted<CGM_LOCAL,CGM_POINT>(VEC, A_MAT4);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REBASED, 0.0001));
    }

    {
        auto result = CGM::converted<CGM_LOCAL,CGM_DIRECTION>(VEC, A_MAT4);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REORIENTED, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Vector_Converters, GlobalToLocal_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM::converted<CGM_LOCAL>(VEC, A_QUAT);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REORIENTED, 0.0001));
}
