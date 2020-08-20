

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Converters.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat2_Mat2)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::localToLocal(A_LOCAL_COORD, A_MAT2, B_MAT2);
    ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat2_Mat2WithPos)
{
    using namespace cgm_xy_converters_tests_data;

    {
        auto result = CGM_XY::localToLocal<CGM_POINT>(A_LOCAL_COORD, A_MAT2, B_MAT2, B_P);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_SPACE, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<CGM_DIRECTION>(A_LOCAL_COORD, A_MAT2, B_MAT2, B_P);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToLocal_Mat2_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    {
        auto result = CGM_XY::localToLocal<CGM_POINT>(A_LOCAL_COORD, A_MAT2, B_MAT3);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_SPACE, 0.0001));
    }

    {
        auto result = CGM_XY::localToLocal<CGM_DIRECTION>(A_LOCAL_COORD, A_MAT2, B_MAT3);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT, 0.0001));
    }
}