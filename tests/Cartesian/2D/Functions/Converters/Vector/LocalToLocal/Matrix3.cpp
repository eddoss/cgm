

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Cartesian/2D/Functions/Converters/Vector.hpp>
#include "../../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Vector_Converters, LocalToLocal_Mat3_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted(VEC, A_MAT3, B_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT2, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Vector_Converters, LocalToLocal_Mat3_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted(VEC, A_MAT3, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT3, 0.0001));
}