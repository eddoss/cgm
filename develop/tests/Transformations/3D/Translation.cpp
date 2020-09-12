

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Translate.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations_Translation, Vector_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_X>(cgm_test::vector, cgm_test::translate::value);
        const auto expect = cgm_test::vector + CGM_XYZ::x<double>() * cgm_test::translate::value;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Y>(cgm_test::vector, cgm_test::translate::value);
        const auto expect = cgm_test::vector + CGM_XYZ::y<double>() * cgm_test::translate::value;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Z>(cgm_test::vector, cgm_test::translate::value);
        const auto expect = cgm_test::vector + CGM_XYZ::z<double>() * cgm_test::translate::value;
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Translation, Vector_ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::translated(cgm_test::vector, cgm_test::translate::values);
    const auto expect = cgm_test::vector + cgm_test::translate::values;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Translation, Vector_AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::translated(cgm_test::vector, cgm_test::translate::value, cgm_test::axis.direction);
    const auto expect = cgm_test::vector + cgm_test::translate::value * cgm_test::axis.direction;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Translation, Vector_AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::translated(cgm_test::vector, cgm_test::translate::values, cgm_test::pivot);
    const auto expect = cgm_test::vector + cgm_test::translate::values.x * cgm_test::pivot.axes.x
                                         + cgm_test::translate::values.y * cgm_test::pivot.axes.y
                                         + cgm_test::translate::values.z * cgm_test::pivot.axes.z;
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations_Translation, Matrix4_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_X,CGM_WORLD>(cgm_test::space, cgm_test::translate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.75000, +1.20000, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Y,CGM_WORLD>(cgm_test::space, cgm_test::translate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.25000, +1.70000, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Z,CGM_WORLD>(cgm_test::space, cgm_test::translate::value);
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
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_X,CGM_LOCAL>(cgm_test::space, cgm_test::translate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.691475, +1.434735, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Y,CGM_LOCAL>(cgm_test::space, cgm_test::translate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.020395, +1.631825, -1.196045}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_3D_AXIS_Z,CGM_LOCAL>(cgm_test::space, cgm_test::translate::value);
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

TEST(Transformations_Translation, Matrix4_ArbitraryOffset)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::translated<CGM_WORLD>(cgm_test::space, cgm_test::translate::values);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            cgm_test::orientation,
            Vector<3,double>{+0.75000, -0.20000, +1.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_LOCAL>(cgm_test::space, cgm_test::translate::values);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            cgm_test::orientation,
            Vector<3,double>{+1.558872, -0.196609, +0.658671}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Translation, Matrix4_AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::translated<CGM_WORLD,CGM_DIRECTION>(cgm_test::space, cgm_test::translate::value, cgm_test::axis.direction);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.72471, +1.27519, -1.43782}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_WORLD,CGM_POINT>(cgm_test::space, cgm_test::translate::value, cgm_test::axis.direction);
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
            const auto result = CGM_XFORM3D::translated<CGM_LOCAL,CGM_DIRECTION>(cgm_test::space, cgm_test::translate::value, cgm_test::axis.direction);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                cgm_test::orientation,
                Vector<3,double>{+0.621170, +1.513099, -1.419175}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::translated<CGM_LOCAL,CGM_POINT>(cgm_test::space, cgm_test::translate::value, cgm_test::axis.direction);
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

TEST(Transformations_Translation, Matrix4_AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::translated<CGM_WORLD>(cgm_test::space, cgm_test::translate::values, cgm_test::pivot);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            cgm_test::orientation,
            Vector<3,double>{+1.46093, -0.95299, -0.11751}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::translated<CGM_LOCAL>(cgm_test::space, cgm_test::translate::values, cgm_test::pivot);
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
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
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
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
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
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
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
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_TranslationMatrix, AlongVector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::translationMatrix(cgm_test::translate::value, cgm_test::axis.direction);
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

TEST(Transformations_TranslationMatrix, AlongPivotAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::translationMatrix(cgm_test::translate::values, cgm_test::pivot);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        CGM_XYZ::x<double>(),
        CGM_XYZ::y<double>(),
        CGM_XYZ::z<double>(),
        Vector<3,double>{+1.21093, -2.15299, +1.18249}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}