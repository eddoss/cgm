

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>
#include "Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::globalToLocal(A_LOCAL_COORD, A_MAT3);
    ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__ORIENT_DIR, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3WithPos)
{
    using namespace cgm_xyz_converters_tests_data;

    {
        auto result = CGM_XYZ::globalToLocal<CGM_POINT>(A_LOCAL_COORD, A_MAT3, A_P);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__SPACE_POINT, 0.0001));
    }

    {
        auto result = CGM_XYZ::globalToLocal<CGM_DIRECTION>(A_LOCAL_COORD, A_MAT3, A_P);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__ORIENT_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat4)
{
    using namespace cgm_xyz_converters_tests_data;

    {
        auto result = CGM_XYZ::globalToLocal<CGM_POINT>(A_LOCAL_COORD, A_MAT4);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__SPACE_POINT, 0.0001));
    }

    {
        auto result = CGM_XYZ::globalToLocal<CGM_DIRECTION>(A_LOCAL_COORD, A_MAT4);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__ORIENT_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Quat)
{
    using namespace cgm_xyz_converters_tests_data;

    auto result = CGM_XYZ::globalToLocal(A_LOCAL_COORD, A_QUAT);
    ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__ORIENT_DIR, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_QuatWithPos)
{
    using namespace cgm_xyz_converters_tests_data;

    {
        auto result = CGM_XYZ::globalToLocal<CGM_POINT>(A_LOCAL_COORD, A_QUAT, A_P);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__SPACE_POINT, 0.0001));
    }

    {
        auto result = CGM_XYZ::globalToLocal<CGM_DIRECTION>(A_LOCAL_COORD, A_QUAT, A_P);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_GLOBAL__ORIENT_DIR, 0.0001));
    }
}