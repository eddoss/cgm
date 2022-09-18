

#include "input.hpp"
#include <cgm/modules/transformations/3d/functions/translate.hpp>


using namespace std;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations3D_Translation, Vector_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::translated<CGM_3D_X>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM::x<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::translated<CGM_3D_Y>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM::y<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::translated<CGM_3D_Z>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM::z<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Vector_ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translated(cgm_test::vector, values.translation);
    const auto expect = cgm_test::vector + values.translation;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Vector_AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translated(cgm_test::vector, values.translation.x, cgm_test::axis.direction);
    const auto expect = cgm_test::vector + values.translation.x * cgm_test::axis.direction;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Vector_AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translated(cgm_test::vector, values.translation, values.pivot);
    const auto expect = cgm_test::vector + values.translation.x * values.pivot.axes.x
                                         + values.translation.y * values.pivot.axes.y
                                         + values.translation.z * values.pivot.axes.z;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations3D_Translation, Matrix4_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::translated<CGM_3D_X>(cgm_test::space, values.translation.x);
        const auto expect = CGM::spaceMatrix
        (
            cgm_test::orientation,
            CGM::Vector<3,double>{+0.75000, +1.20000, -1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::translated<CGM_3D_Y>(cgm_test::space, values.translation.x);
        const auto expect = CGM::spaceMatrix
        (
            cgm_test::orientation,
            CGM::Vector<3,double>{+0.25000, +1.70000, -1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::translated<CGM_3D_Z>(cgm_test::space, values.translation.x);
        const auto expect = CGM::spaceMatrix
        (
            cgm_test::orientation,
            CGM::Vector<3,double>{+0.25000, +1.20000, -0.80000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Matrix4_ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translated(cgm_test::space, values.translation);
    const auto expect = CGM::spaceMatrix
    (
        cgm_test::orientation,
        CGM::Vector<3,double>{+0.75000, -0.20000, +1.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Matrix4_AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::translated(cgm_test::space, values.translation.x, cgm_test::axis.direction);
        const auto expect = CGM::spaceMatrix
        (
            cgm_test::orientation,
            CGM::Vector<3,double>{+0.72471, +1.27519, -1.43782}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::translated(cgm_test::space, values.translation.x, cgm_test::axis.direction);
        const auto expect = CGM::spaceMatrix
        (
            cgm_test::orientation,
            CGM::Vector<3,double>{+0.72471, +1.27519, -1.43782}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Matrix4_AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translated(cgm_test::space, values.translation, values.pivot);
    const auto expect = CGM::spaceMatrix
    (
        cgm_test::orientation,
        CGM::Vector<3,double>{+1.46093, -0.95299, -0.11751}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations3D_TranslationMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::translationMatrix<CGM_3D_X>(values.translation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::x<double>(),
            CGM::y<double>(),
            CGM::z<double>(),
            CGM::Vector<3,double>{+0.50000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM::translationMatrix<CGM_3D_Y>(values.translation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::x<double>(),
            CGM::y<double>(),
            CGM::z<double>(),
            CGM::Vector<3,double>{+0.00000, +0.50000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM::translationMatrix<CGM_3D_Z>(values.translation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::x<double>(),
            CGM::y<double>(),
            CGM::z<double>(),
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.50000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_TranslationMatrix, ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translationMatrix(values.translation);
    const auto expect = CGM::spaceMatrix
    (
        CGM::x<double>(),
        CGM::y<double>(),
        CGM::z<double>(),
        values.translation
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_TranslationMatrix, AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translationMatrix(values.translation.x, cgm_test::axis.direction);
    const auto expect = CGM::spaceMatrix
    (
        CGM::x<double>(),
        CGM::y<double>(),
        CGM::z<double>(),
        CGM::Vector<3,double>{+0.47471, +0.07519, -0.13782}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_TranslationMatrix, AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::translationMatrix(values.translation, values.pivot);
    const auto expect = CGM::spaceMatrix
    (
        CGM::x<double>(),
        CGM::y<double>(),
        CGM::z<double>(),
        CGM::Vector<3,double>{+1.21093, -2.15299, +1.18249}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}