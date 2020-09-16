

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Apply.hpp>


using namespace std;
using namespace CGM;

TEST(Transformations_Apply, Vector_Matrix3)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::applied(cgm_test::vector, cgm_test::mat3);
    const auto expect = Vector<3,double>{ -1.39577, 2.62554, -0.178844 };
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Apply, Vector_Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::applied<CGM_POINT>(cgm_test::vector, cgm_test::mat4);
        const auto expect = Vector<3,double>{ -1.09577, 1.42554, 0.821156 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::applied<CGM_DIRECTION>(cgm_test::vector, cgm_test::mat4);
        const auto expect = Vector<3,double>{ -1.39577, 2.62554, -0.178844 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Apply, Matrix3_Matrix3)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::applied(cgm_test::orientation, cgm_test::mat3);
    const auto expect = CGM_XYZ::orientationMatrix
    (
        Vector<3,double>{+0.422386, +0.249121, +1.516038},
        Vector<3,double>{-0.269509, +1.109342, -0.936976},
        Vector<3,double>{-0.767905, +0.239267, +0.844442}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Apply, Matrix4_Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::applied(cgm_test::space, cgm_test::mat4);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+0.422386, +0.249121, +1.516038},
        Vector<3,double>{-0.269509, +1.109342, -0.936976},
        Vector<3,double>{-0.767905, +0.239267, +0.844442},
        Vector<3,double>{-1.095765, +1.425543, +0.821154}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}