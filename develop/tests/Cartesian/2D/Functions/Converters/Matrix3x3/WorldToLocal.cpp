

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Converters/Matrix3x3.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Matrix3x3_Converters, WorldToLocal_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted<CGM_LOCAL>(MAT3, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL_BY_MAT2, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Matrix3x3_Converters, WorldToLocal_Mat2WithPos)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted<CGM_LOCAL>(MAT3, A_MAT2, A_P);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL_BY_MAT3, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Matrix3x3_Converters, WorldToLocal_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::converted<CGM_LOCAL>(MAT3, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, EXPECT_MAT3_TO_LOCAL_BY_MAT3, 0.0001));
}