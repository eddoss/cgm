

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Converters/Vector.hpp>
#include "../../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Vector_Converters, LocalToLocal_Mat2WithPos_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted(VEC, A_MAT2, A_P, B_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT2, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Vector_Converters, LocalToLocal_Mat2WithPos_Mat2WithPos)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted(VEC, A_MAT2, A_P, B_MAT2, B_P);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT3, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Vector_Converters, LocalToLocal_Mat2WithPos_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted(VEC, A_MAT2, A_P, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_A2B_MAT3_TO_MAT3, 0.0001));
}