

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Translate.hpp>
#include "Input.hpp"


using namespace std;
using namespace CGM;


TEST(Transformations_Translation, Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto offset = Vector<3,double>{ 2.0, 0.5, 1.2 };

    {
        const auto result = CGM_XFORM3D::translated<CGM_WORLD>(cgm_test::space, offset);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::orientationMatrix(cgm_test::space),
            CGM_XYZ::position(cgm_test::space) + offset
        );

        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }

    {
        const auto result = CGM_XFORM3D::translated<CGM_LOCAL>(cgm_test::space, offset);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::orientationMatrix(cgm_test::space),
            {+1.903427, +2.350469, -0.022265}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}