

#include "Input.hpp"
#include <CGM/Transformations/2D/Functions/Translate.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations2D_Translation, Vector_DefaultAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::translated<CGM_2D_X>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM_XY::x<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::translated<CGM_2D_Y>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM_XY::y<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Translation, Vector_ArbitraryOffset)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::translated(cgm_test::vector, values.translation);
    const auto expect = cgm_test::vector + values.translation;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Translation, Vector_AlongVector)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::translated(cgm_test::vector, values.translation.x, cgm_test::axis.direction);
    const auto expect = cgm_test::vector + values.translation.x * cgm_test::axis.direction;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Translation, Vector_AlongPivotAxes)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::translated(cgm_test::vector, values.translation, values.pivot);
    const auto expect = cgm_test::vector + values.translation.x * values.pivot.axes.x
                                         + values.translation.y * values.pivot.axes.y;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations2D_Translation, Matrix3_DefaultAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        {
            const auto result = CGM_XFORM2D::translated<CGM_2D_X,CGM_WORLD>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.75000, +1.20000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::translated<CGM_2D_Y,CGM_WORLD>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.25000, +1.70000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM2D::translated<CGM_2D_X,CGM_LOCAL>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.691475, +1.434735}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::translated<CGM_2D_Y,CGM_LOCAL>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.015265, +1.641475}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Translation, Matrix3_ArbitraryOffset)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::translated<CGM_WORLD>(cgm_test::space, values.translation);
        const auto expect = CGM_XY::spaceMatrix
        (
            cgm_test::orientation,
            Vector<2,double>{+0.75000, -0.20000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::translated<CGM_LOCAL>(cgm_test::space, values.translation);
        const auto expect = CGM_XY::spaceMatrix
        (
            cgm_test::orientation,
            Vector<2,double>{+1.348733, +0.198605}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Translation, Matrix3_AlongVector)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        {
            const auto result = CGM_XFORM2D::translated<CGM_WORLD,CGM_DIRECTION>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.69147, +1.43474}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::translated<CGM_WORLD,CGM_POINT>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.69147, +1.43474}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM2D::translated<CGM_LOCAL,CGM_DIRECTION>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.529599, +1.614517}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::translated<CGM_LOCAL,CGM_POINT>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XY::spaceMatrix
            (
                cgm_test::orientation,
                Vector<2,double>{+0.654599, +2.214517}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Translation, Matrix3_AlongPivotAxes)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::translated<CGM_WORLD>(cgm_test::space, values.translation, values.pivot);
        const auto expect = CGM_XY::spaceMatrix
        (
            cgm_test::orientation,
            Vector<2,double>{+1.34873, +0.19861}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::translated<CGM_LOCAL>(cgm_test::space, values.translation, values.pivot);
        const auto expect = CGM_XY::spaceMatrix
        (
            cgm_test::orientation,
            Vector<2,double>{+1.348733, +0.198605}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations2D_TranslationMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    {
        const auto result = CGM_XFORM2D::translationMatrix<CGM_2D_X>(values.translation.x);
        const auto expect = CGM_XY::spaceMatrix
        (
            CGM_XY::x<double>(),
            CGM_XY::y<double>(),
            Vector<2,double>{+0.50000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::translationMatrix<CGM_2D_Y>(values.translation.x);
        const auto expect = CGM_XY::spaceMatrix
        (
            CGM_XY::x<double>(),
            CGM_XY::y<double>(),
            Vector<2,double>{+0.00000, +0.50000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_TranslationMatrix, ArbitraryOffset)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::translationMatrix(values.translation);
    const auto expect = CGM_XY::spaceMatrix
    (
        CGM_XY::x<double>(),
        CGM_XY::y<double>(),
        values.translation
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_TranslationMatrix, AlongVector)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::translationMatrix(values.translation.x, cgm_test::axis.direction);
    const auto expect = CGM_XY::spaceMatrix
    (
        CGM_XY::x<double>(),
        CGM_XY::y<double>(),
        Vector<2,double>{+0.441475, +0.234735}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_TranslationMatrix, AlongPivotAxes)
{
    namespace cgm_test = cgm_xy_xform_tests_data;
    const auto values = cgm_xy_xform_tests_data::get();

    const auto result = CGM_XFORM2D::translationMatrix(values.translation, values.pivot);
    const auto expect = CGM_XY::spaceMatrix
    (
        CGM_XY::x<double>(),
        CGM_XY::y<double>(),
        Vector<2,double>{+1.09873, -1.00139}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}