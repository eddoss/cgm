

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Cartesian/2D/Functions/Converters/Matrix2x2.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Matrix2x2_Converters, LocalToWorld_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_WORLD>(MAT2, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT2_TO_WORLD, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Matrix2x2_Converters, LocalToWorld_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_WORLD>(MAT2, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT2_TO_WORLD, 0.0001));
}