

#include "Input.hpp"
#include <CGM/Transformations/2D/Functions/Scale.hpp>
#include <CGM/Transformations/2D/Functions/Apply.hpp>


using namespace std;
using namespace CGM;

TEST(Transformations2D_Apply, Vector_Matrix2)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto result = CGM_XFORM2D::applied(cgm_test::vector, cgm_test::mat2);
    const auto expect = Vector<2,double>{ -0.342626, +1.176907 };
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Vector_Matrix3)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        const auto result = CGM_XFORM2D::applied<CGM_POINT>(cgm_test::vector, cgm_test::mat3);
        const auto expect = Vector<2,double>{ +0.057374, +0.876907 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::applied<CGM_DIRECTION>(cgm_test::vector, cgm_test::mat3);
        const auto expect = Vector<2,double>{ -0.342626, +1.176907 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Matrix2_Matrix2)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto result = CGM_XFORM2D::applied(cgm_test::orientation, cgm_test::mat2);
    const auto expect = CGM_XY::orientationMatrix
    (
        Vector<2,double>{+0.559199, +0.829037},
        Vector<2,double>{-0.829037, +0.559199}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Matrix3_Matrix3)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto result = CGM_XFORM2D::applied(cgm_test::space, cgm_test::mat3);
    const auto expect = CGM_XY::spaceMatrix
    (
        Vector<2,double>{+0.559199, +0.829037},
        Vector<2,double>{-0.829037, +0.559199},
        Vector<2,double>{+0.057374, +0.876907}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Vector_Matrix2_Variadic)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto A = CGM_XFORM2D::scalingMatrix<CGM_2D_X,2>(2.1);
    const auto B = CGM_XFORM2D::scalingMatrix<CGM_2D_Y,2>(1.1);
    const auto C = CGM_XFORM2D::scalingMatrix<CGM_2D_X,2>(0.7);

    const auto result = CGM_XFORM2D::applied(cgm_test::vector, {A,B,C});

#ifdef CGM_CFG_MATRIX_POSTMULT
    const auto expect = C * B * A * cgm_test::vector;
#else
    const auto expect = cgm_test::vector * A * B * C;
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Vector_Matrix3_Variadic)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto A = CGM_XFORM2D::scalingMatrix<CGM_2D_X,3>(2.1);
    const auto B = CGM_XFORM2D::scalingMatrix<CGM_2D_Y,3>(1.1);
    const auto C = CGM_XFORM2D::scalingMatrix<CGM_2D_X,3>(0.7);

    const auto result = CGM_XFORM2D::applied<CGM_DIRECTION>(cgm_test::vector, {A,B,C});

#ifdef CGM_CFG_MATRIX_POSTMULT
    const auto expect = CGM_XFORM2D::applied<CGM_DIRECTION>(cgm_test::vector, C * B * A);
#else
    const auto expect = CGM_XFORM2D::applied<CGM_DIRECTION>(cgm_test::vector, A * B * C);
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Matrix2_Variadic)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto A = CGM_XFORM2D::scalingMatrix<CGM_2D_X,2>(2.1);
    const auto B = CGM_XFORM2D::scalingMatrix<CGM_2D_Y,2>(1.1);
    const auto C = CGM_XFORM2D::scalingMatrix<CGM_2D_X,2>(0.7);

    const auto result = CGM_XFORM2D::applied(cgm_test::orientation, {A,B,C});

#ifdef CGM_CFG_MATRIX_POSTMULT
    const auto expect = C * B * A * cgm_test::orientation;
#else
    const auto expect = cgm_test::orientation * A * B * C;
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Matrix3_Variadic)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto A = CGM_XFORM2D::scalingMatrix<CGM_2D_X,3>(2.1);
    const auto B = CGM_XFORM2D::scalingMatrix<CGM_2D_Y,3>(1.1);
    const auto C = CGM_XFORM2D::scalingMatrix<CGM_2D_X,3>(0.7);

    const auto result = CGM_XFORM2D::applied(cgm_test::space, {A,B,C});

#ifdef CGM_CFG_MATRIX_POSTMULT
    const auto expect = CGM_XFORM2D::applied(cgm_test::space, C * B * A);
#else
    const auto expect = CGM_XFORM2D::applied(cgm_test::space, A * B * C);
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}