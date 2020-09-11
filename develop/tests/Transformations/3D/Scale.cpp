

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Scale.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations_Scale, Vector_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_X>(cgm_test::vector, cgm_test::scale::value);
        const auto expect = CGM::Vector<3,double>{0.35, 1.2, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Y>(cgm_test::vector, cgm_test::scale::value);
        const auto expect = CGM::Vector<3,double>{0.25, 1.68, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Z>(cgm_test::vector, cgm_test::scale::value);
        const auto expect = CGM::Vector<3,double>{0.25, 1.2, -1.82};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Vector_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::scaled(cgm_test::vector, cgm_test::scale::values);
    const auto expect = CGM::Vector<3,double>{0.35, 2.52, -0.39};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Vector_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::scaled(cgm_test::vector, cgm_test::scale::value, cgm_test::axis.direction);
    const auto expect = CGM::Vector<3,double>{0.544753, 1.24668, -1.38557};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Vector_AlongArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::scaled(cgm_test::vector, cgm_test::scale::value, cgm_test::axis);
    const auto expect = CGM::Vector<3,double>{+0.438595, +1.229870, -1.354753};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Vector_RelatedToPivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XFORM3D::scaled(cgm_test::vector, cgm_test::scale::values, cgm_test::pivot);
    const auto expect = CGM::Vector<3,double>{0.861329, 1.2972, 0.138074};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations_Scale, Matrix3_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_X,CGM_WORLD>(cgm_test::orientation, cgm_test::scale::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.23613, +0.46947, +0.00000},
                Vector<3,double>{-0.64290, +0.86365, +0.20791},
                Vector<3,double>{+0.13665, -0.18358, +0.97815}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Y,CGM_WORLD>(cgm_test::orientation, cgm_test::scale::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.88295, +0.65726, +0.00000},
                Vector<3,double>{-0.45921, +1.20911, +0.20791},
                Vector<3,double>{+0.09761, -0.25701, +0.97815}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Z,CGM_WORLD>(cgm_test::orientation, cgm_test::scale::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.88295, +0.46947, +0.00000},
                Vector<3,double>{-0.45921, +0.86365, +0.29108},
                Vector<3,double>{+0.09761, -0.18358, +1.36941}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_X,CGM_LOCAL>(cgm_test::orientation, cgm_test::scale::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.236131, +0.657259, +0.000000},
                Vector<3,double>{-0.459211, +0.863650, +0.207910},
                Vector<3,double>{+0.097610, -0.183580, +0.978150}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Y,CGM_LOCAL>(cgm_test::orientation, cgm_test::scale::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.882950, +0.469469, -0.000000},
                Vector<3,double>{-0.642892, +1.209107, +0.291073},
                Vector<3,double>{+0.097611, -0.183582, +0.978150}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Z,CGM_LOCAL>(cgm_test::orientation, cgm_test::scale::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.882950, +0.469470, -0.000000},
                Vector<3,double>{-0.459210, +0.863650, +0.207908},
                Vector<3,double>{+0.136654, -0.257012, +1.369413}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix3_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_WORLD>(cgm_test::orientation, cgm_test::scale::values);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+1.23613, +0.98589, +0.00000},
            Vector<3,double>{-0.64290, +1.81367, +0.06237},
            Vector<3,double>{+0.13665, -0.38551, +0.29344}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_LOCAL>(cgm_test::orientation, cgm_test::scale::values);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+1.236130, +0.657258, +0.000000},
            Vector<3,double>{-0.964341, +1.813665, +0.436611},
            Vector<3,double>{+0.029283, -0.055074, +0.293445}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix3_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_WORLD>(cgm_test::orientation, cgm_test::scale::value, cgm_test::axis.direction);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+1.22812, +0.52414, -0.10021},
            Vector<3,double>{-0.59723, +0.84179, +0.24798},
            Vector<3,double>{+0.01993, -0.19588, +1.00070}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_LOCAL>(cgm_test::orientation, cgm_test::scale::value, cgm_test::axis.direction);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+1.164870, +0.707282, -0.090519},
            Vector<3,double>{-0.414560, +0.901315, +0.193574},
            Vector<3,double>{+0.015763, -0.252622, +1.004430}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix3_Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_WORLD>(cgm_test::orientation, cgm_test::scale::values, cgm_test::pivot);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+1.20649, +0.94942, +0.05732},
            Vector<3,double>{-0.53345, +1.59510, +0.87864},
            Vector<3,double>{-0.18947, +0.35538, +0.58016}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_LOCAL>(cgm_test::orientation, cgm_test::scale::values, cgm_test::pivot);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+1.047118, +0.782149, -0.260561},
            Vector<3,double>{-0.616996, +1.459645, +1.029940},
            Vector<3,double>{-0.500265, +0.309847, +0.875006}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations_Scale, Matrix4_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_X,CGM_WORLD>(cgm_test::space, cgm_test::scale::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.23613, +0.46947, +0.00000},
                Vector<3,double>{-0.64290, +0.86365, +0.20791},
                Vector<3,double>{+0.13665, -0.18358, +0.97815},
                Vector<3,double>{+0.35000, +1.20000, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Y,CGM_WORLD>(cgm_test::space, cgm_test::scale::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.88295, +0.65726, +0.00000},
                Vector<3,double>{-0.45921, +1.20911, +0.20791},
                Vector<3,double>{+0.09761, -0.25701, +0.97815},
                Vector<3,double>{+0.25000, +1.68000, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Z,CGM_WORLD>(cgm_test::space, cgm_test::scale::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.88295, +0.46947, +0.00000},
                Vector<3,double>{-0.45921, +0.86365, +0.29108},
                Vector<3,double>{+0.09761, -0.18358, +1.36941},
                Vector<3,double>{+0.25000, +1.20000, -1.82000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_X,CGM_LOCAL>(cgm_test::space, cgm_test::scale::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.236131, +0.657259, +0.000000},
                Vector<3,double>{-0.459211, +0.863650, +0.207910},
                Vector<3,double>{+0.097610, -0.183580, +0.978150},
                Vector<3,double>{+0.526929, +1.347245, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Y,CGM_LOCAL>(cgm_test::space, cgm_test::scale::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.882950, +0.469469, -0.000000},
                Vector<3,double>{-0.642892, +1.209107, +0.291073},
                Vector<3,double>{+0.097611, -0.183582, +0.978150},
                Vector<3,double>{+0.130368, +1.424996, -1.245836}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::scaled<CGM_3D_AXIS_Z,CGM_LOCAL>(cgm_test::space, cgm_test::scale::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.882950, +0.469470, -0.000000},
                Vector<3,double>{-0.459210, +0.863650, +0.207908},
                Vector<3,double>{+0.136654, -0.257012, +1.369413},
                Vector<3,double>{+0.192703, +1.307761, -1.874170}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix4_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_WORLD>(cgm_test::space, cgm_test::scale::values);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.23613, +0.98589, +0.00000},
            Vector<3,double>{-0.64290, +1.81367, +0.06237},
            Vector<3,double>{+0.13665, -0.38551, +0.29344},
            Vector<3,double>{+0.35000, +2.52000, -0.39000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_LOCAL>(cgm_test::space, cgm_test::scale::values);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.236130, +0.657258, +0.000000},
            Vector<3,double>{-0.964341, +1.813665, +0.436611},
            Vector<3,double>{+0.029283, -0.055074, +0.293445},
            Vector<3,double>{+0.250000, +1.200000, -1.300000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix4_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_WORLD>(cgm_test::space, cgm_test::scale::value, cgm_test::axis.direction);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.22812, +0.52414, -0.10021},
            Vector<3,double>{-0.59723, +0.84179, +0.24798},
            Vector<3,double>{+0.01993, -0.19588, +1.00070},
            Vector<3,double>{+0.54475, +1.24668, -1.38557}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_LOCAL>(cgm_test::space, cgm_test::scale::value, cgm_test::axis.direction);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.164870, +0.707282, -0.090519},
            Vector<3,double>{-0.414560, +0.901315, +0.193574},
            Vector<3,double>{+0.015763, -0.252622, +1.004430},
            Vector<3,double>{+0.620243, +1.512317, -1.418878}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix4_AlongArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_WORLD>(cgm_test::space, cgm_test::scale::value, cgm_test::axis);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.22812, +0.52414, -0.10021},
            Vector<3,double>{-0.59723, +0.84179, +0.24798},
            Vector<3,double>{+0.01993, -0.19588, +1.00070},
            Vector<3,double>{+0.43860, +1.22987, -1.35475}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_LOCAL>(cgm_test::space, cgm_test::scale::value, cgm_test::axis);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.164870, +0.707282, -0.090519},
            Vector<3,double>{-0.414560, +0.901315, +0.193574},
            Vector<3,double>{+0.015763, -0.252622, +1.004430},
            Vector<3,double>{+0.166997, +1.129983, -1.273349}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix4_RelatedToPivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::scaled<CGM_WORLD>(cgm_test::space, cgm_test::scale::values, cgm_test::pivot);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.20649, +0.94942, +0.05732},
            Vector<3,double>{-0.53345, +1.59510, +0.87864},
            Vector<3,double>{-0.18947, +0.35538, +0.58016},
            Vector<3,double>{+0.86133, +1.29720, +0.13807}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::scaled<CGM_LOCAL>(cgm_test::space, cgm_test::scale::values, cgm_test::pivot);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.047118, +0.782149, -0.260561},
            Vector<3,double>{-0.616996, +1.459645, +1.029940},
            Vector<3,double>{-0.500265, +0.309847, +0.875006},
            Vector<3,double>{+0.256570, +1.155044, -0.928538}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations_ScalingMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XYZ::scalingMatrix<CGM_3D_AXIS_X,4>(cgm_test::scale::value);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.40000, +0.00000, +0.00000},
            Vector<3,double>{+0.00000, +1.00000, +0.00000},
            Vector<3,double>{+0.00000, +0.00000, +1.00000},
            Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XYZ::scalingMatrix<CGM_3D_AXIS_Y,4>(cgm_test::scale::value);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.00000, +0.00000, +0.00000},
            Vector<3,double>{+0.00000, +1.40000, +0.00000},
            Vector<3,double>{+0.00000, +0.00000, +1.00000},
            Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XYZ::scalingMatrix<CGM_3D_AXIS_Z,4>(cgm_test::scale::value);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.00000, +0.00000, +0.00000},
            Vector<3,double>{+0.00000, +1.00000, +0.00000},
            Vector<3,double>{+0.00000, +0.00000, +1.40000},
            Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_ScalingMatrix, DefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XYZ::scalingMatrix<4>(cgm_test::scale::values);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+1.40000, +0.00000, +0.00000},
        Vector<3,double>{+0.00000, +2.10000, +0.00000},
        Vector<3,double>{+0.00000, +0.00000, +0.30000},
        Vector<3,double>{+0.00000, +0.00000, +0.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_ScalingMatrix, Direction)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XYZ::scalingMatrix<4>(cgm_test::scale::value, cgm_test::axis.direction);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+1.36056, +0.05711, -0.10468},
        Vector<3,double>{+0.05711, +1.00904, -0.01658},
        Vector<3,double>{-0.10468, -0.01658, +1.03039},
        Vector<3,double>{+0.00000, +0.00000, +0.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_ScalingMatrix, Axis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XYZ::scalingMatrix(cgm_test::scale::value, cgm_test::axis);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+1.36056, +0.05711, -0.10468},
        Vector<3,double>{+0.05711, +1.00904, -0.01658},
        Vector<3,double>{-0.10468, -0.01658, +1.03039},
        Vector<3,double>{-0.10616, -0.01681, +0.03082}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */


TEST(Transformations_ScalingMatrix, Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM_XYZ::scalingMatrix(cgm_test::scale::values, cgm_test::pivot);
    const auto expect = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+1.29174, +0.14048, -0.29624},
        Vector<3,double>{+0.14048, +1.75810, +0.67925},
        Vector<3,double>{-0.29624, +0.67925, +0.75016},
        Vector<3,double>{-0.01530, +0.03539, +0.37224}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}