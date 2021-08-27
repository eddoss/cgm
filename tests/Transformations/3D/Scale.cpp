

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Scale.hpp>


using namespace std;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations3D_Scale, Vector_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::scaled<CGM_3D_X>(cgm_test::vector, values.scale.x);
        const auto expect = CGM::Vector<3,double>{0.35, 1.2, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scaled<CGM_3D_Y>(cgm_test::vector, values.scale.x);
        const auto expect = CGM::Vector<3,double>{0.25, 1.68, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scaled<CGM_3D_Z>(cgm_test::vector, values.scale.x);
        const auto expect = CGM::Vector<3,double>{0.25, 1.2, -1.82};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Vector_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::vector, values.scale);
    const auto expect = CGM::Vector<3,double>{0.35, 2.52, -0.39};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Vector_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::vector, values.scale.x, cgm_test::axis.direction);
    const auto expect = CGM::Vector<3,double>{0.544753, 1.24668, -1.38557};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Vector_AlongArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::vector, values.scale.x, cgm_test::axis);
    const auto expect = CGM::Vector<3,double>{+0.438595, +1.229870, -1.354753};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Vector_RelatedToPivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::vector, values.scale, values.pivot);
    const auto expect = CGM::Vector<3,double>{0.861329, 1.2972, 0.138074};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations3D_Scale, Matrix3_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::scaled<CGM_3D_X>(cgm_test::orientation, values.scale.x);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+1.23613, +0.46947, +0.00000},
            CGM::Vector<3,double>{-0.64290, +0.86365, +0.20791},
            CGM::Vector<3,double>{+0.13665, -0.18358, +0.97815}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scaled<CGM_3D_Y>(cgm_test::orientation, values.scale.x);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.88295, +0.65726, +0.00000},
            CGM::Vector<3,double>{-0.45921, +1.20911, +0.20791},
            CGM::Vector<3,double>{+0.09761, -0.25701, +0.97815}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scaled<CGM_3D_Z>(cgm_test::orientation, values.scale.x);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.88295, +0.46947, +0.00000},
            CGM::Vector<3,double>{-0.45921, +0.86365, +0.29108},
            CGM::Vector<3,double>{+0.09761, -0.18358, +1.36941}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Matrix3_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::orientation, values.scale);
    const auto expect = CGM::orientationMatrix
    (
        CGM::Vector<3,double>{+1.23613, +0.98589, +0.00000},
        CGM::Vector<3,double>{-0.64290, +1.81367, +0.06237},
        CGM::Vector<3,double>{+0.13665, -0.38551, +0.29344}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Matrix3_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::orientation, values.scale.x, cgm_test::axis.direction);
    const auto expect = CGM::orientationMatrix
    (
        CGM::Vector<3,double>{+1.22812, +0.52414, -0.10021},
        CGM::Vector<3,double>{-0.59723, +0.84179, +0.24798},
        CGM::Vector<3,double>{+0.01993, -0.19588, +1.00070}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Matrix3_Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::orientation, values.scale, values.pivot);
    const auto expect = CGM::orientationMatrix
    (
        CGM::Vector<3,double>{+1.20649, +0.94942, +0.05732},
        CGM::Vector<3,double>{-0.53345, +1.59510, +0.87864},
        CGM::Vector<3,double>{-0.18947, +0.35538, +0.58016}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations3D_Scale, Matrix4_AlongDefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::scaled<CGM_3D_X>(cgm_test::space, values.scale.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.23613, +0.46947, +0.00000},
            CGM::Vector<3,double>{-0.64290, +0.86365, +0.20791},
            CGM::Vector<3,double>{+0.13665, -0.18358, +0.97815},
            CGM::Vector<3,double>{+0.35000, +1.20000, -1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scaled<CGM_3D_Y>(cgm_test::space, values.scale.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.88295, +0.65726, +0.00000},
            CGM::Vector<3,double>{-0.45921, +1.20911, +0.20791},
            CGM::Vector<3,double>{+0.09761, -0.25701, +0.97815},
            CGM::Vector<3,double>{+0.25000, +1.68000, -1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scaled<CGM_3D_Z>(cgm_test::space, values.scale.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.88295, +0.46947, +0.00000},
            CGM::Vector<3,double>{-0.45921, +0.86365, +0.29108},
            CGM::Vector<3,double>{+0.09761, -0.18358, +1.36941},
            CGM::Vector<3,double>{+0.25000, +1.20000, -1.82000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Matrix4_AlongDefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::space, values.scale);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.23613, +0.98589, +0.00000},
        CGM::Vector<3,double>{-0.64290, +1.81367, +0.06237},
        CGM::Vector<3,double>{+0.13665, -0.38551, +0.29344},
        CGM::Vector<3,double>{+0.35000, +2.52000, -0.39000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Matrix4_AlongArbitraryDirection)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::space, values.scale.x, cgm_test::axis.direction);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.22812, +0.52414, -0.10021},
        CGM::Vector<3,double>{-0.59723, +0.84179, +0.24798},
        CGM::Vector<3,double>{+0.01993, -0.19588, +1.00070},
        CGM::Vector<3,double>{+0.54475, +1.24668, -1.38557}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Matrix4_AlongArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::space, values.scale.x, cgm_test::axis);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.22812, +0.52414, -0.10021},
        CGM::Vector<3,double>{-0.59723, +0.84179, +0.24798},
        CGM::Vector<3,double>{+0.01993, -0.19588, +1.00070},
        CGM::Vector<3,double>{+0.43860, +1.22987, -1.35475}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Scale, Matrix4_RelatedToPivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scaled(cgm_test::space, values.scale, values.pivot);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.20649, +0.94942, +0.05732},
        CGM::Vector<3,double>{-0.53345, +1.59510, +0.87864},
        CGM::Vector<3,double>{-0.18947, +0.35538, +0.58016},
        CGM::Vector<3,double>{+0.86133, +1.29720, +0.13807}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations3D_ScalingMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::scalingMatrix<CGM_3D_X,4>(values.scale.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.40000, +0.00000, +0.00000},
            CGM::Vector<3,double>{+0.00000, +1.00000, +0.00000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +1.00000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scalingMatrix<CGM_3D_Y,4>(values.scale.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.00000, +0.00000, +0.00000},
            CGM::Vector<3,double>{+0.00000, +1.40000, +0.00000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +1.00000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::scalingMatrix<CGM_3D_Z,4>(values.scale.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.00000, +0.00000, +0.00000},
            CGM::Vector<3,double>{+0.00000, +1.00000, +0.00000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +1.40000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_ScalingMatrix, DefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scalingMatrix<4>(values.scale);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.40000, +0.00000, +0.00000},
        CGM::Vector<3,double>{+0.00000, +2.10000, +0.00000},
        CGM::Vector<3,double>{+0.00000, +0.00000, +0.30000},
        CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_ScalingMatrix, Direction)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scalingMatrix<4>(values.scale.x, cgm_test::axis.direction);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.36056, +0.05711, -0.10468},
        CGM::Vector<3,double>{+0.05711, +1.00904, -0.01658},
        CGM::Vector<3,double>{-0.10468, -0.01658, +1.03039},
        CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_ScalingMatrix, Axis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scalingMatrix(values.scale.x, cgm_test::axis);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.36056, +0.05711, -0.10468},
        CGM::Vector<3,double>{+0.05711, +1.00904, -0.01658},
        CGM::Vector<3,double>{-0.10468, -0.01658, +1.03039},
        CGM::Vector<3,double>{-0.10616, -0.01681, +0.03082}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */


TEST(Transformations3D_ScalingMatrix, Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::scalingMatrix(values.scale, values.pivot);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+1.29174, +0.14048, -0.29624},
        CGM::Vector<3,double>{+0.14048, +1.75810, +0.67925},
        CGM::Vector<3,double>{-0.29624, +0.67925, +0.75016},
        CGM::Vector<3,double>{-0.01530, +0.03539, +0.37224}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}