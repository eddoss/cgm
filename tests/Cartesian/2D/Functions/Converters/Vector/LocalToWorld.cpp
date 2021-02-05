

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Cartesian/2D/Functions/Converters/Vector.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Vector_Converters, LocalToWorld_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_2D::converted<CGM_WORLD>(VEC, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_WORLD_REORIENTED, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Vector_Converters, LocalToWorld_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    {
        auto result = CGM_2D::converted<CGM_WORLD,CGM_POINT>(VEC, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_WORLD_REBASED, 0.0001));
    }

    {
        auto result = CGM_2D::converted<CGM_WORLD,CGM_DIRECTION>(VEC, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, EXPECT_VEC_TO_WORLD_REORIENTED, 0.0001));
    }
}