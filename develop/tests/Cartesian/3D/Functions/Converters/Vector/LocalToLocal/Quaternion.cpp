

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters/Vector.hpp>
#include "../Input.hpp"


using namespace std;

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Quat_Mat3)
{
    using namespace cgm_xyz_vector_converters_tests_data;

    auto result = CGM_XYZ::converted(A_LOCAL_COORD, A_QUAT, B_MAT3);
    ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Quat_Mat3WithPos)
{
    using namespace cgm_xyz_vector_converters_tests_data;

    auto result = CGM_XYZ::converted(A_LOCAL_COORD, A_QUAT, B_MAT3, B_P);
    ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_SPACE, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Quat_Mat4)
{
    using namespace cgm_xyz_vector_converters_tests_data;

    {
        auto result = CGM_XYZ::converted<CGM_POINT>(A_LOCAL_COORD, A_QUAT, B_MAT4);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_SPACE, 0.0001));
    }

    {
        auto result = CGM_XYZ::converted<CGM_DIRECTION>(A_LOCAL_COORD, A_QUAT, B_MAT4);
        ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Quat_Quat)
{
    using namespace cgm_xyz_vector_converters_tests_data;

    auto result = CGM_XYZ::converted(A_LOCAL_COORD, A_QUAT, B_QUAT);
    ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_ORIENT, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Quat_QuatWithPos)
{
    using namespace cgm_xyz_vector_converters_tests_data;

    auto result = CGM_XYZ::converted(A_LOCAL_COORD, A_QUAT, B_QUAT, B_P);
    ASSERT_TRUE(CGM::eq(result, A_LOCAL_COORD_CONVERTED_TO_LOCAL_B__ORIENT_2_SPACE, 0.0001));
}