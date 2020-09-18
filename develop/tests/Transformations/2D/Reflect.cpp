

#include "Input.hpp"
#include <CGM/Modules/Transformations/2D/Functions/Reflect.hpp>


using namespace std;
using namespace CGM;

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
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+0.147326, -0.989089},
            Vector<2,double>{-0.989089, -0.147325}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM2D::reflected<CGM_LOCAL>(cgm_test::orientation, cgm_test::normal);
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+0.902373, -0.430955},
            Vector<2,double>{-0.430958, -0.902368}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations2D_Reflection, Matrix3_PlaneNormal)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        const auto result = CGM_XFORM2D::reflected<CGM_WORLD>(cgm_test::space, cgm_test::normal);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+0.147326, -0.989089},
            Vector<2,double>{-0.989089, -0.147325},
            Vector<2,double>{-0.816372, -0.914349}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM2D::reflected<CGM_LOCAL>(cgm_test::space, cgm_test::normal);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+0.318984, -4.961398},
            Vector<2,double>{-1.307840, -7.190369},
            Vector<2,double>{-0.982092, -10.664777}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Reflection, Matrix3_PlaneNormalOrigin)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        const auto result = CGM_XFORM2D::reflected<CGM_WORLD>(cgm_test::space, cgm_test::normal, cgm_test::origin);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+0.147326, -0.989089},
            Vector<2,double>{-0.989089, -0.147325},
            Vector<2,double>{-0.799240, -0.880380}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM2D::reflected<CGM_WORLD>(cgm_test::space, cgm_test::normal, cgm_test::origin);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+0.147326, -0.989089},
            Vector<2,double>{-0.989089, -0.147325},
            Vector<2,double>{-0.799240, -0.880380}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}