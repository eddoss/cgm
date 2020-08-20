

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Converters.hpp>
#include "Input.hpp"


using namespace std;

TEST(Cartesian_2D_Functions_Converters, GlobalToLocal_Mat3_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    auto result = CGM_XY::globalToLocal(GLOBAL_COORD, A_MAT2);
    ASSERT_TRUE(CGM::eq(result, GLOBAL_COORD_CONVERTED_TO_LOCAL_A__ORIENT_DIR, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, GlobalToLocal_Mat2_Mat2WithPos)
{
    using namespace cgm_xy_converters_tests_data;

    {
        auto result = CGM_XY::globalToLocal<CGM_POINT>(GLOBAL_COORD, A_MAT2, A_P);
        ASSERT_TRUE(CGM::eq(result, GLOBAL_COORD_CONVERTED_TO_LOCAL_A__SPACE_POINT, 0.0001));
    }

    {
        auto result = CGM_XY::globalToLocal<CGM_DIRECTION>(GLOBAL_COORD, A_MAT2, A_P);
        ASSERT_TRUE(CGM::eq(result, GLOBAL_COORD_CONVERTED_TO_LOCAL_A__ORIENT_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, GlobalToLocal_Mat2_Mat3)
{
    using namespace cgm_xy_converters_tests_data;

    {
        auto result = CGM_XY::globalToLocal<CGM_POINT>(GLOBAL_COORD, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, GLOBAL_COORD_CONVERTED_TO_LOCAL_A__SPACE_POINT, 0.0001));
    }

    {
        auto result = CGM_XY::globalToLocal<CGM_DIRECTION>(GLOBAL_COORD, A_MAT3);
        ASSERT_TRUE(CGM::eq(result, GLOBAL_COORD_CONVERTED_TO_LOCAL_A__ORIENT_DIR, 0.0001));
    }
}