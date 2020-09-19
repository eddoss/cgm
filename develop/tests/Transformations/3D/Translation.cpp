

#include "Input.hpp"
#include <CGM/detail/Modules/Transformations/3D/Functions/Translate.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations3D_Translation, Vector_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_X>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM_XYZ::x<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Y>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM_XYZ::y<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Z>(cgm_test::vector, values.translation.x);
        const auto expect = cgm_test::vector + CGM_XYZ::z<double>() * values.translation.x;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Vector_ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM_XFORM3D::translated(cgm_test::vector, values.translation);
    const auto expect = cgm_test::vector + values.translation;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Vector_AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM_XFORM3D::translated(cgm_test::vector, values.translation.x, cgm_test::axis.direction);
    const auto expect = cgm_test::vector + values.translation.x * cgm_test::axis.direction;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Vector_AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM_XFORM3D::translated(cgm_test::vector, values.translation, values.pivot);
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
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_X,CGM_WORLD>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.75000, +1.20000, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Y,CGM_WORLD>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.25000, +1.70000, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Z,CGM_WORLD>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.25000, +1.20000, -0.80000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_X,CGM_LOCAL>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.691475, +1.434735, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Y,CGM_LOCAL>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.020395, +1.631825, -1.196045}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Z,CGM_LOCAL>(cgm_test::space, values.translation.x);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.298805, +1.108210, -0.810925}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Matrix4_ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM_XFORM3D::translated<CGM_WORLD>(cgm_test::space, values.translation);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            cgm_test::orientation,
            Vector<3,double>{+0.75000, -0.20000, +1.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_LOCAL>(cgm_test::space, values.translation);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            cgm_test::orientation,
            Vector<3,double>{+1.558872, -0.196609, +0.658671}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Matrix4_AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        {
            const auto result = CGM_XFORM3D::translated<CGM_WORLD,CGM_DIRECTION>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.72471, +1.27519, -1.43782}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_WORLD,CGM_POINT>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.72471, +1.27519, -1.43782}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::translated<CGM_LOCAL,CGM_DIRECTION>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.621170, +1.513099, -1.419175}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_LOCAL,CGM_POINT>(cgm_test::space, values.translation.x, cgm_test::axis.direction);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.746170, +2.113099, -2.069175}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Translation, Matrix4_AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM_XFORM3D::translated<CGM_WORLD>(cgm_test::space, values.translation, values.pivot);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            cgm_test::orientation,
            Vector<3,double>{+1.46093, -0.95299, -0.11751}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_LOCAL>(cgm_test::space, values.translation, values.pivot);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            cgm_test::orientation,
            Vector<3,double>{+1.460935, -0.952989, -0.117524}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations3D_TranslationMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM_XFORM3D::translationMatrix<CGM_3D_AXIS_X>(values.translation.x);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::x<double>(),
            CGM_XYZ::y<double>(),
            CGM_XYZ::z<double>(),
            Vector<3,double>{+0.50000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM_XFORM3D::translationMatrix<CGM_3D_AXIS_Y>(values.translation.x);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::x<double>(),
            CGM_XYZ::y<double>(),
            CGM_XYZ::z<double>(),
            Vector<3,double>{+0.00000, +0.50000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM_XFORM3D::translationMatrix<CGM_3D_AXIS_Z>(values.translation.x);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            CGM_XYZ::x<double>(),
            CGM_XYZ::y<double>(),
            CGM_XYZ::z<double>(),
            Vector<3,double>{+0.00000, +0.00000, +0.50000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_TranslationMatrix, ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM_XFORM3D::translationMatrix(values.translation);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        CGM_XYZ::x<double>(),
        CGM_XYZ::y<double>(),
        CGM_XYZ::z<double>(),
        values.translation
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_TranslationMatrix, AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM_XFORM3D::translationMatrix(values.translation.x, cgm_test::axis.direction);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        CGM_XYZ::x<double>(),
        CGM_XYZ::y<double>(),
        CGM_XYZ::z<double>(),
        Vector<3,double>{+0.47471, +0.07519, -0.13782}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_TranslationMatrix, AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM_XFORM3D::translationMatrix(values.translation, values.pivot);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        CGM_XYZ::x<double>(),
        CGM_XYZ::y<double>(),
        CGM_XYZ::z<double>(),
        Vector<3,double>{+1.21093, -2.15299, +1.18249}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}