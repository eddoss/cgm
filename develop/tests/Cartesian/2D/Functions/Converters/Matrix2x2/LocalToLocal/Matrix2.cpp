

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Converters/Matrix2x2.hpp>
#include "../../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Matrix2x2_Converters, LocalToLocal_Mat2_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted(MAT2, A_MAT2, B_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT2_A2B, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Matrix2x2_Converters, LocalToLocal_Mat2_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted(MAT2, A_MAT2, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT2_A2B, 0.0001));
}