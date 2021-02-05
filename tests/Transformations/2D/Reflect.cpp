

#include "Input.hpp"
#include <CGM/Transformations/2D/Functions/Reflect.hpp>


using namespace std;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations2D_Reflection, Vector_PlaneNormal)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto result = CGM_XFORM2D::reflected(cgm_test::vector, cgm_test::normal);
    const auto expect = CGM::Vector<2,double>{-0.81637, -0.91435};
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Reflection, Vector_PlaneNormalOrigin)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto result = CGM_XFORM2D::reflected(cgm_test::vector, cgm_test::normal, cgm_test::origin);
    const auto expect = CGM::Vector<2,double>{-0.79924, -0.88038};
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* ####################################################################################### */
/* Matrix2 */
/* ####################################################################################### */

TEST(Transformations2D_Reflection, Matrix2_PlaneNormal)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        const auto result = CGM_XFORM2D::reflected<CGM_WORLD>(cgm_test::orientation, cgm_test::normal);
        const auto expect = CGM_2D::orientationMatrix
        (
            CGM::Vector<2,double>{+0.147326, -0.989089},
            CGM::Vector<2,double>{-0.989089, -0.147325}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM2D::reflected<CGM_LOCAL>(cgm_test::orientation, cgm_test::normal);
        const auto expect = CGM_2D::orientationMatrix
        (
            CGM::Vector<2,double>{+0.902373, -0.430955},
            CGM::Vector<2,double>{-0.430958, -0.902368}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations2D_Reflection, Matrix3_AxisNormal)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        const auto result = CGM_XFORM2D::reflected<CGM_WORLD>(cgm_test::space, cgm_test::normal);
        const auto expect = CGM_2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.147326, -0.989089},
            CGM::Vector<2,double>{-0.989089, -0.147325},
            CGM::Vector<2,double>{-0.816372, -0.914349}
        );

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::reflected<CGM_LOCAL>(cgm_test::space, cgm_test::normal);
        const auto expect = CGM_2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.318984, -4.961410},
            CGM::Vector<2,double>{-1.307841, -7.190390},
            CGM::Vector<2,double>{-0.982093, -10.66480}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Reflection, Matrix3_AxisNormalOrigin)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        const auto result = CGM_XFORM2D::reflected<CGM_WORLD>(cgm_test::space, cgm_test::normal, cgm_test::origin);
        const auto expect = CGM_2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.147326, -0.989089},
            CGM::Vector<2,double>{-0.989089, -0.147325},
            CGM::Vector<2,double>{-0.799240, -0.880380}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM2D::reflected<CGM_WORLD>(cgm_test::space, cgm_test::normal, cgm_test::origin);
        const auto expect = CGM_2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.147326, -0.989089},
            CGM::Vector<2,double>{-0.989089, -0.147325},
            CGM::Vector<2,double>{-0.799240, -0.880380}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}