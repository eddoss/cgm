

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/cartesian/2d/functions/converters/vector.hpp>
#include "../input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Vector_Converters, GlobalToLocal_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_LOCAL>(VEC, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REORIENTED, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Vector_Converters, GlobalToLocal_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    {
        auto result = CGM_2D::converted<CGM_LOCAL,CGM_POINT>(VEC, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REBASED, 0.0001));
    }

    {
        auto result = CGM_2D::converted<CGM_LOCAL,CGM_DIRECTION>(VEC, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_LOCAL_REORIENTED, 0.0001));
    }
}