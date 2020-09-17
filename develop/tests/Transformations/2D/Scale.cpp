

#include "Input.hpp"
#include <CGM/Modules/Transformations/2D/Functions/Scale.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations2D_Scale, Vector_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_X>(cgm_test::vector, values.scale.x);
        const auto expect = CGM::Vector<2,double>{+0.35000, +1.20000};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_Y>(cgm_test::vector, values.scale.x);
        const auto expect = CGM::Vector<2,double>{+0.25000, +1.68000};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Vector_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::scaled(cgm_test::vector, values.scale);
    const auto expect = CGM::Vector<2,double>{0.35, 2.52};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Vector_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::scaled(cgm_test::vector, values.scale.x, cgm_test::axis.direction);
    const auto expect = CGM::Vector<2,double>{+0.52693, +1.34725};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Vector_AlongArbitraryAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::scaled(cgm_test::vector, values.scale.x, cgm_test::axis);
    const auto expect = CGM::Vector<2,double>{+0.45194, +1.30737};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Vector_RelatedToPivot)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::scaled(cgm_test::vector, values.scale, values.pivot);
    const auto expect = CGM::Vector<2,double>{-0.26839, +2.66210};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations2D_Scale, Matrix3_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_X,CGM_WORLD>(cgm_test::orientation, values.scale.x);
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.23613, +0.46947},
                Vector<2,double>{-0.65726, +0.88295}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_Y,CGM_WORLD>(cgm_test::orientation, values.scale.x);
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+0.88295, +0.65726},
                Vector<2,double>{-0.46947, +1.23613}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_X,CGM_LOCAL>(cgm_test::orientation, values.scale.x);
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.236131, +0.657259},
                Vector<2,double>{-0.469470, +0.882950}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_Y,CGM_LOCAL>(cgm_test::orientation, values.scale.x);
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+0.882950, +0.469470},
                Vector<2,double>{-0.657259, +1.236131}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Matrix3_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_WORLD>(cgm_test::orientation, values.scale);
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+1.23613, +0.98589},
            Vector<2,double>{-0.65726, +1.85419}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_LOCAL>(cgm_test::orientation, values.scale);
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+1.236130, +0.657258},
            Vector<2,double>{-0.985887, +1.854195}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Matrix3_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_WORLD>(cgm_test::orientation, values.scale.x, cgm_test::axis.direction);
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+1.23613, +0.65726},
            Vector<2,double>{-0.46947, +0.88295}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_LOCAL>(cgm_test::orientation, values.scale.x, cgm_test::axis.direction);
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+1.080447, +0.762268},
            Vector<2,double>{-0.364460, +1.038633}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Matrix3_RelatedToPivot)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_WORLD>(cgm_test::orientation, values.scale, values.pivot);
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+1.23613, +0.65726},
            Vector<2,double>{-0.98589, +1.85419}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_LOCAL>(cgm_test::orientation, values.scale, values.pivot);
        const auto expect = CGM_XY::orientationMatrix
        (
            Vector<2,double>{+1.508575, +0.473490},
            Vector<2,double>{-1.169655, +1.581750}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations2D_Scale, Matrix4_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_X,CGM_WORLD>(cgm_test::space, values.scale.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.23613, +0.46947},
                Vector<2,double>{-0.65726, +0.88295},
                Vector<2,double>{+0.35000, +1.20000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_Y,CGM_WORLD>(cgm_test::space, values.scale.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+0.88295, +0.65726},
                Vector<2,double>{-0.46947, +1.23613},
                Vector<2,double>{+0.25000, +1.68000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_X,CGM_LOCAL>(cgm_test::space, values.scale.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.236131, +0.657259},
                Vector<2,double>{-0.469470, +0.882950},
                Vector<2,double>{+0.526929, +1.347245}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::scaled<CGM_2D_AXIS_Y,CGM_LOCAL>(cgm_test::space, values.scale.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+0.882950, +0.469470},
                Vector<2,double>{-0.657259, +1.236131},
                Vector<2,double>{+0.073071, +1.532756}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Matrix4_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_WORLD>(cgm_test::space, values.scale);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.23613, +0.98589},
            Vector<2,double>{-0.65726, +1.85419},
            Vector<2,double>{+0.35000, +2.52000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_LOCAL>(cgm_test::space, values.scale);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.236130, +0.657258},
            Vector<2,double>{-0.985887, +1.854195},
            Vector<2,double>{+0.250000, +1.200000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Matrix4_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_WORLD>(cgm_test::space, values.scale.x, cgm_test::axis.direction);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.23613, +0.65726},
            Vector<2,double>{-0.46947, +0.88295},
            Vector<2,double>{+0.52693, +1.34725}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_LOCAL>(cgm_test::space, values.scale.x, cgm_test::axis.direction);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.080447, +0.762268},
            Vector<2,double>{-0.364460, +1.038633},
            Vector<2,double>{+0.503795, +1.576263}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Matrix4_AlongArbitraryAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_WORLD>(cgm_test::space, values.scale.x, cgm_test::axis);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.23613, +0.65726},
            Vector<2,double>{-0.46947, +0.88295},
            Vector<2,double>{+0.45194, +1.30737}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_LOCAL>(cgm_test::space, values.scale.x, cgm_test::axis);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.080447, +0.762268},
            Vector<2,double>{-0.364460, +1.038633},
            Vector<2,double>{+0.202504, +1.129586}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Scale, Matrix4_RelatedToPivot)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::scaled<CGM_WORLD>(cgm_test::space, values.scale, values.pivot);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.23613, +0.65726},
            Vector<2,double>{-0.98589, +1.85419},
            Vector<2,double>{-0.26839, +2.66210}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::scaled<CGM_LOCAL>(cgm_test::space, values.scale, values.pivot);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.508575, +0.473490},
            Vector<2,double>{-1.169655, +1.581750},
            Vector<2,double>{-0.210304, +1.408032}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations2D_ScalingMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XY::scalingMatrix<CGM_2D_AXIS_X,3>(values.scale.x);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.40000, +0.00000},
            Vector<2,double>{+0.00000, +1.00000},
            Vector<2,double>{+0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XY::scalingMatrix<CGM_2D_AXIS_Y,3>(values.scale.x);
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.00000, +0.00000},
            Vector<2,double>{+0.00000, +1.40000},
            Vector<2,double>{+0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_ScalingMatrix, DefaultAxes)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XY::scalingMatrix<3>(values.scale);
    const auto expect = CGM_XY::spaceMatrix
    (
        Vector<2,double>{+1.40000, +0.00000},
        Vector<2,double>{+0.00000, +2.10000},
        Vector<2,double>{+0.00000, +0.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_ScalingMatrix, Direction)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XY::scalingMatrix<3>(values.scale.x, cgm_test::axis.direction);
    const auto expect = CGM_XY::spaceMatrix
    (
        Vector<2,double>{+1.31184, +0.16581},
        Vector<2,double>{+0.16581, +1.08816},
        Vector<2,double>{+0.00000, +0.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_ScalingMatrix, Axis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XY::scalingMatrix(values.scale.x, cgm_test::axis);
    const auto expect = CGM_XY::spaceMatrix
    (
        Vector<2,double>{+1.31184, +0.16581},
        Vector<2,double>{+0.16581, +1.08816},
        Vector<2,double>{-0.07499, -0.03987}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_ScalingMatrix, Pivot)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XY::scalingMatrix(values.scale, values.pivot);
    const auto expect = CGM_XY::spaceMatrix
    (
        Vector<2,double>{+1.55428, -0.29016},
        Vector<2,double>{-0.29016, +1.94572},
        Vector<2,double>{-0.30876, +0.39978}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}