

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Reflect.hpp>
#include "Input.hpp"


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations3D_Reflection, Vector_DefaultPlane)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_XY>(cgm_test::vector);
        const auto expect = CGM::Vector<3,double>{cgm_test::vector.x, cgm_test::vector.y, -cgm_test::vector.z};
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_YZ>(cgm_test::vector);
        const auto expect = CGM::Vector<3,double>{-cgm_test::vector.x, cgm_test::vector.y, cgm_test::vector.z};
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_ZX>(cgm_test::vector);
        const auto expect = CGM::Vector<3,double>{cgm_test::vector.x, -cgm_test::vector.y, cgm_test::vector.z};
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Reflection, Vector_PlaneNormal)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::reflected(cgm_test::vector, cgm_test::normal);
    const auto expect = CGM::Vector<3,double>{0.95247, 1.51101, 0.0462915};
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Reflection, Vector_PlaneNormalOrigin)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::reflected(cgm_test::vector, cgm_test::normal, cgm_test::origin);
    const auto expect = CGM::Vector<3,double>{1.21966, 1.62931, 0.558365};
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations3D_Reflection, Matrix3x3_DefaultPlane)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_XY>(cgm_test::orientation);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.88295, +0.46947, +0.00000},
            Vector<3,double>{-0.45921, +0.86365, -0.20791},
            Vector<3,double>{+0.09761, -0.18358, -0.97815}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_YZ>(cgm_test::orientation);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{-0.88295, +0.46947, +0.00000},
            Vector<3,double>{+0.45921, +0.86365, +0.20791},
            Vector<3,double>{-0.09761, -0.18358, +0.97815}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_ZX>(cgm_test::orientation);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.88295, -0.46947, +0.00000},
            Vector<3,double>{-0.45921, -0.86365, +0.20791},
            Vector<3,double>{+0.09761, +0.18358, +0.97815}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Reflection, Matrix3x3_PlaneNormal)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::reflected(cgm_test::orientation, cgm_test::normal);
    const auto expect = CGM_XYZ::orientationMatrix
    (
        Vector<3,double>{+0.43489, +0.27110, -0.85871},
        Vector<3,double>{-0.59132, +0.80516, -0.04528},
        Vector<3,double>{-0.67912, -0.52747, -0.51046}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations3D_Reflection, Matrix4x4_DefaultPlane)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_XY>(cgm_test::space);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.88295, +0.46947, +0.00000},
            Vector<3,double>{-0.45921, +0.86365, -0.20791},
            Vector<3,double>{+0.09761, -0.18358, -0.97815},
            Vector<3,double>{+0.25000, +1.20000, +1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_YZ>(cgm_test::space);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{-0.88295, +0.46947, +0.00000},
            Vector<3,double>{+0.45921, +0.86365, +0.20791},
            Vector<3,double>{-0.09761, -0.18358, +0.97815},
            Vector<3,double>{-0.25000, +1.20000, -1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM_XFORM3D::reflected<CGM_PLANE_ZX>(cgm_test::space);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.88295, -0.46947, +0.00000},
            Vector<3,double>{-0.45921, -0.86365, +0.20791},
            Vector<3,double>{+0.09761, +0.18358, +0.97815},
            Vector<3,double>{+0.25000, -1.20000, -1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Reflection, Matrix4x4_PlaneNormal)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::reflected(cgm_test::space, cgm_test::normal);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+0.43489, +0.27110, -0.85871},
        Vector<3,double>{-0.59132, +0.80516, -0.04528},
        Vector<3,double>{-0.67912, -0.52747, -0.51046},
        Vector<3,double>{+0.95247, +1.51101, +0.04629}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Reflection, Matrix4x4_PlaneNormalOrigin)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::reflected(cgm_test::space, cgm_test::normal, cgm_test::origin);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+0.43489, +0.27110, -0.85871},
        Vector<3,double>{-0.59132, +0.80516, -0.04528},
        Vector<3,double>{-0.67912, -0.52747, -0.51046},
        Vector<3,double>{+1.21966, +1.62931, +0.55837}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}