

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/cartesian/2d/functions/converters/matrix3x3.hpp>
#include "../input.hpp"

using namespace std;

TEST(Cartesian_2D_Functions_Matrix3x3_Converters, GlobalToLocal_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_LOCAL>(MAT3, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL_BY_MAT2, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Matrix3x3_Converters, GlobalToLocal_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_LOCAL>(MAT3, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL_BY_MAT3, 0.0001));
}