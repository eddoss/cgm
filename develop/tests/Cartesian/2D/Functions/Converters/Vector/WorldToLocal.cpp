

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Modules/Core/Functions/Vector.hpp>
#include <CGM/detail/Modules/Cartesian/2D/Functions/Converters/Vector.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Vector_Converters, WorldToLocal_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted<CGM_LOCAL>(VEC, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REORIENTED, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Vector_Converters, WorldToLocal_Mat2WithPos)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted<CGM_LOCAL>(VEC, A_MAT2, A_P);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REBASED, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Vector_Converters, WorldToLocal_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    {
        auto result = CGM_XY::converted<CGM_LOCAL,CGM_POINT>(VEC, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REBASED, 0.0001));
    }

    {
        auto result = CGM_XY::converted<CGM_LOCAL,CGM_DIRECTION>(VEC, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REORIENTED, 0.0001));
    }
}