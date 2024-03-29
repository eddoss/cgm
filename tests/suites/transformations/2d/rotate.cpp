

#include "input.hpp"
#include <cgm/modules/transformations/2d/functions/rotate.hpp>


/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations2D_Rotate, Vector_AroundOrigin)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::rotated(cgm_test::vector, values.rotation);
#ifdef CGM_CFG_LHS
    const auto expect = CGM::Vector<2,double>{+0.68132, +1.01897};
#else
    const auto expect = CGM::Vector<2,double>{-0.21773, +1.20627};
#endif
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Rotate, Vector_ArounArbitraryPoint)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::rotated(cgm_test::vector, values.rotation, values.pivot.position);
#ifdef CGM_CFG_LHS
    const auto expect = CGM::Vector<2,double>{+0.82283, +1.14697};
#else
    const auto expect = CGM::Vector<2,double>{-0.30099, +1.03458};
#endif
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix2 */
/* ####################################################################################### */

TEST(Transformations2D_Rotate, Matrix2_AroundOrigin)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::rotated(cgm_test::orientation, values.rotation);
#ifdef CGM_CFG_LHS
    const auto expect = CGM_XFORM2D::orientationMatrix
    (
        CGM::Vector<2,double>{+0.99452, +0.10453},
        CGM::Vector<2,double>{-0.10453, +0.99452}
    );
#else
    const auto expect = CGM_XFORM2D::orientationMatrix
    (
        CGM::Vector<2,double>{+0.64279, +0.76604},
        CGM::Vector<2,double>{-0.76604, +0.64279}
    );
#endif
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations2D_Rotate, Matrix3_AroundOrigin)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::rotated<CGM_GLOBAL>(cgm_test::space, values.rotation);
    #ifdef CGM_CFG_LHS
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.99452, +0.10453},
            CGM::Vector<2,double>{-0.10453, +0.99452},
            CGM::Vector<2,double>{+0.68132, +1.01897}
        );
    #else
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.64279, +0.76604},
            CGM::Vector<2,double>{-0.76604, +0.64279},
            CGM::Vector<2,double>{-0.21773, +1.20627}
        );
    #endif
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::rotated<CGM_LOCAL>(cgm_test::space, values.rotation);
    #ifdef CGM_CFG_LHS
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.99452, +0.10453},
            CGM::Vector<2,double>{-0.10453, +0.99452},
            CGM_2D::position(cgm_test::space)
        );
    #else
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.64279, +0.76604},
            CGM::Vector<2,double>{-0.76604, +0.64279},
            CGM_2D::position(cgm_test::space)
        );
    #endif
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Rotate, Matrix3_ArounArbitraryPoint)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::rotated<CGM_GLOBAL>(cgm_test::space, values.rotation, values.pivot.position);
    #ifdef CGM_CFG_LHS
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.99452, +0.10453},
            CGM::Vector<2,double>{-0.10453, +0.99452},
            CGM::Vector<2,double>{+0.82283, +1.14697}
        );
    #else
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.64279, +0.76604},
            CGM::Vector<2,double>{-0.76604, +0.64279},
            CGM::Vector<2,double>{-0.30099, +1.03458}
        );
    #endif
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::rotated<CGM_LOCAL>(cgm_test::space, values.rotation, values.pivot.position);
    #ifdef CGM_CFG_LHS
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.994524, +0.104526},
            CGM::Vector<2,double>{-0.104526, +0.994524},
            CGM::Vector<2,double>{+0.314854, +1.379449}
        );
    #else
        const auto expect = CGM_XFORM2D::spaceMatrix
        (
            CGM::Vector<2,double>{+0.642790, +0.766044},
            CGM::Vector<2,double>{-0.766044, +0.642790},
            CGM::Vector<2,double>{+0.257092, +1.009323}
        );
    #endif
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}