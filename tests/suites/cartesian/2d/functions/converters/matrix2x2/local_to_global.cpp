

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/cartesian/2d/functions/converters/matrix2x2.hpp>
#include "../input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Matrix2x2_Converters, LocalToGlobal_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_GLOBAL>(MAT2, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT2_TO_GLOBAL, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Matrix2x2_Converters, LocalToGlobal_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_GLOBAL>(MAT2, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT2_TO_GLOBAL, 0.0001));
}