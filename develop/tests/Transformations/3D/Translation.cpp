

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Translate.hpp>
#include "Input.hpp"


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

TEST(Transformations_Translation, Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::translated<CGM_WORLD>(cgm_test::space, cgm_test::translate::values);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::orientationMatrix(cgm_test::space),
            CGM_XYZ::position(cgm_test::space) + cgm_test::translate::values
        );

        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }

    {
        const auto result = CGM_XFORM3D::translated<CGM_LOCAL>(cgm_test::space, cgm_test::translate::values);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::orientationMatrix(cgm_test::space),
            {+1.558872, -0.196609, +0.658671}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations_TranslationMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::translationMatrix<CGM_3D_AXIS_X>(cgm_test::translate::value);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::x<double>(),
            CGM_XYZ::y<double>(),
            CGM_XYZ::z<double>(),
            Vector<3,double>{+0.50000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }

    {
        const auto result = CGM_XFORM3D::translationMatrix<CGM_3D_AXIS_Y>(cgm_test::translate::value);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::x<double>(),
            CGM_XYZ::y<double>(),
            CGM_XYZ::z<double>(),
            Vector<3,double>{+0.00000, +0.50000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }

    {
        const auto result = CGM_XFORM3D::translationMatrix<CGM_3D_AXIS_Z>(cgm_test::translate::value);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::x<double>(),
            CGM_XYZ::y<double>(),
            CGM_XYZ::z<double>(),
            Vector<3,double>{+0.00000, +0.00000, +0.50000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_TranslationMatrix, ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::translationMatrix(cgm_test::translate::values);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        CGM_XYZ::x<double>(),
        CGM_XYZ::y<double>(),
        CGM_XYZ::z<double>(),
        cgm_test::translate::values
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}