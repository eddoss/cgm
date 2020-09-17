

#include "Input.hpp"
#include <CGM/Modules/Transformations/2D/Functions/Apply.hpp>


using namespace std;
using namespace CGM;

TEST(Transformations2D_Apply, Vector_Matrix2)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto result = CGM_XFORM2D::applied(cgm_test::vector, cgm_test::mat2);
    const auto expect = Vector<2,double>{ +0.784102, +0.942172 };
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Apply, Vector_Matrix3)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        const auto result = CGM_XFORM2D::applied<CGM_POINT>(cgm_test::vector, cgm_test::mat3);
        const auto expect = Vector<2,double>{ +1.184102, +0.642173 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::applied<CGM_DIRECTION>(cgm_test::vector, cgm_test::mat3);
        const auto expect = Vector<2,double>{ +0.784102, +0.942172 };
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
        Vector<2,double>{+1.184102, +0.642173}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}