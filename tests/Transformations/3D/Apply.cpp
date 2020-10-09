

#include "Input.hpp"
#include <CGM/Transformations/3D/Functions/Rotate.hpp>
#include <CGM/Transformations/3D/Functions/Apply.hpp>
#include <CGM/Core/Functions/IO.hpp>

using namespace std;
using namespace CGM;

#define CGM_PRINT(what) std::cout << "\n" << what << std::endl;

TEST(Transformations3D_Apply, Vector_Matrix3)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::applied(cgm_test::vector, cgm_test::mat3);
    const auto expect = Vector<3,double>{ +1.197280, +0.193243, -1.925383 };
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Apply, Vector_Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::applied<CGM_POINT>(cgm_test::vector, cgm_test::mat4);
        const auto expect = Vector<3,double>{ +1.497280, -1.006757, -0.925383 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::applied<CGM_DIRECTION>(cgm_test::vector, cgm_test::mat4);
        const auto expect = Vector<3,double>{ +1.197280, +0.193243, -1.925383 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Apply, Matrix3_Matrix3)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::applied(cgm_test::orientation, cgm_test::mat3);
    const auto expect = CGM_XYZ::orientationMatrix
    (
        Vector<3,double>{+0.565342, +0.713463, +0.767129},
        Vector<3,double>{-0.098305, +0.764397, -1.522012},
        Vector<3,double>{-0.557434, +0.588787, +1.046432}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Apply, Matrix4_Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::applied(cgm_test::space, cgm_test::mat4);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+0.565342, +0.713463, +0.767129},
        Vector<3,double>{-0.098305, +0.764397, -1.522012},
        Vector<3,double>{-0.557434, +0.588787, +1.046432},
        Vector<3,double>{+1.497280, -1.006757, -0.925383}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Apply, Vector_Matrix3_Variadic)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto A = CGM_XFORM3D::rotationMatrix<3>(CGM::radians(1.0, 2.3, 1.6));
    const auto B = CGM_XFORM3D::rotationMatrix<3>(CGM::radians(2.3, 0.5, 6.1));
    const auto C = CGM_XFORM3D::rotationMatrix<3>(CGM::radians(0.2, 0.7, 3.6));

    const auto result = CGM_XFORM3D::applied(cgm_test::vector, {A,B,C});

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    const auto expect = C * B * A * cgm_test::vector;
#else
    const auto expect = cgm_test::vector * A * B * C;
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Apply, Vector_Matrix4_Variadic)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto A = CGM_XFORM3D::rotationMatrix<4>(CGM::radians(1.0, 2.3, 1.6));
    const auto B = CGM_XFORM3D::rotationMatrix<4>(CGM::radians(2.3, 0.5, 6.1));
    const auto C = CGM_XFORM3D::rotationMatrix<4>(CGM::radians(0.2, 0.7, 3.6));

    const auto result = CGM_XFORM3D::applied<CGM_DIRECTION>(cgm_test::vector, {A,B,C});

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    const auto expect = CGM_XFORM3D::applied<CGM_DIRECTION>(cgm_test::vector, C * B * A);
#else
    const auto expect = CGM_XFORM3D::applied<CGM_DIRECTION>(cgm_test::vector, A * B * C);
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Apply, Matrix3_Variadic)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto A = CGM_XFORM3D::rotationMatrix<3>(CGM::radians(1.0, 2.3, 1.6));
    const auto B = CGM_XFORM3D::rotationMatrix<3>(CGM::radians(2.3, 0.5, 6.1));
    const auto C = CGM_XFORM3D::rotationMatrix<3>(CGM::radians(0.2, 0.7, 3.6));

    const auto result = CGM_XFORM3D::applied(cgm_test::orientation, {A,B,C});

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    const auto expect = C * B * A * cgm_test::orientation;
#else
    const auto expect = cgm_test::orientation * A * B * C;
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Apply, Matrix4_Variadic)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto A = CGM_XFORM3D::rotationMatrix<4>(CGM::radians(1.0, 2.3, 1.6));
    const auto B = CGM_XFORM3D::rotationMatrix<4>(CGM::radians(2.3, 0.5, 6.1));
    const auto C = CGM_XFORM3D::rotationMatrix<4>(CGM::radians(0.2, 0.7, 3.6));

    const auto result = CGM_XFORM3D::applied(cgm_test::space, {A,B,C});

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    const auto expect = CGM_XFORM3D::applied(cgm_test::space, C * B * A);
#else
    const auto expect = CGM_XFORM3D::applied(cgm_test::space, A * B * C);
#endif

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}