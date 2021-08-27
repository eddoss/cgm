

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Rotate.hpp>


/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations3D_Rotate, Vector_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated<CGM_3D_X>(cgm_test::vector, values.rotation.x);
        const auto expect = CGM::Vector<3,double>{0.25, 1.59961, -0.755811};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated<CGM_3D_Y>(cgm_test::vector, values.rotation.x);
        const auto expect = CGM::Vector<3,double>{-0.255193, 1.2, -1.29899};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated<CGM_3D_Z>(cgm_test::vector, values.rotation.x);
        const auto expect = CGM::Vector<3,double>{-0.217732, 1.20627, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Vector_ArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation.x, cgm_test::axis.direction);
        const auto expect = CGM::Vector<3,double>{0.336132, 1.55767, -0.808204};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation.x, cgm_test::axis);
        const auto expect = CGM::Vector<3,double>{0.365645, 1.6452, -0.6588};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Vector_PivotPoint)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation, values.pivot, CGM::ERotationOrder::XYZ);
        const auto expect = CGM::Vector<3,double>{-0.0651531, 1.63494, -0.549767};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation, values.pivot, CGM::ERotationOrder::XZY);
        const auto expect = CGM::Vector<3,double>{-0.203716, 1.47929, -0.796071};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation, values.pivot, CGM::ERotationOrder::YXZ);
        const auto expect = CGM::Vector<3,double>{-0.228551, 1.63123, -0.430698};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation, values.pivot, CGM::ERotationOrder::YZX);
        const auto expect = CGM::Vector<3,double>{-0.402085, 1.59831, -0.324956};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation, values.pivot, CGM::ERotationOrder::ZXY);
        const auto expect = CGM::Vector<3,double>{-0.386189, 1.46773, -0.682916};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::vector, values.rotation, values.pivot, CGM::ERotationOrder::ZYX);
        const auto expect = CGM::Vector<3,double>{-0.525776, 1.44649, -0.584356};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations3D_Rotate, Matrix3_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated<CGM_3D_X>(cgm_test::orientation, values.rotation.x);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.88295, +0.43529, +0.17587},
            CGM::Vector<3,double>{-0.45921, +0.72288, +0.51630},
            CGM::Vector<3,double>{+0.09761, -0.53663, +0.83815}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated<CGM_3D_Y>(cgm_test::orientation, values.rotation.x);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.81865, +0.46947, -0.33076},
            CGM::Vector<3,double>{-0.34789, +0.86365, +0.36480},
            CGM::Vector<3,double>{+0.45692, -0.18358, +0.87036}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated<CGM_3D_Z>(cgm_test::orientation, values.rotation.x);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.64279, +0.76604, +0.00000},
            CGM::Vector<3,double>{-0.74930, +0.62874, +0.20791},
            CGM::Vector<3,double>{+0.15927, -0.13364, +0.97815}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Matrix3_DefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, CGM::ERotationOrder::XYZ);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.94260, +0.16699, -0.28917},
            CGM::Vector<3,double>{+0.07791, +0.73209, +0.67674},
            CGM::Vector<3,double>{+0.32471, -0.66042, +0.67706}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, CGM::ERotationOrder::XZY);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.92939, +0.15812, -0.33351},
            CGM::Vector<3,double>{+0.06087, +0.82555, +0.56103},
            CGM::Vector<3,double>{+0.36404, -0.54172, +0.75764}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, CGM::ERotationOrder::YXZ);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.90686, +0.35086, -0.23346},
            CGM::Vector<3,double>{-0.09165, +0.70490, +0.70336},
            CGM::Vector<3,double>{+0.41134, -0.61646, +0.67140}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, CGM::ERotationOrder::YZX);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.86850, +0.37436, -0.32489},
            CGM::Vector<3,double>{-0.02839, +0.69194, +0.72140},
            CGM::Vector<3,double>{+0.49487, -0.61731, +0.61158}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, CGM::ERotationOrder::ZXY);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.88585, +0.17692, -0.42891},
            CGM::Vector<3,double>{+0.11460, +0.81237, +0.57176},
            CGM::Vector<3,double>{+0.44959, -0.55565, +0.69937}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, CGM::ERotationOrder::ZYX);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.85011, +0.36078, -0.38360},
            CGM::Vector<3,double>{-0.05768, +0.78785, +0.61316},
            CGM::Vector<3,double>{+0.52343, -0.49913, +0.69057}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Matrix3_ArbitraryDirection)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::rotated(cgm_test::orientation, values.rotation.x, cgm_test::axis.direction);
    const auto expect = CGM::orientationMatrix
    (
        CGM::Vector<3,double>{+0.92997, +0.35407, +0.09899},
        CGM::Vector<3,double>{-0.35001, +0.77026, +0.53310},
        CGM::Vector<3,double>{+0.11250, -0.53042, +0.84024}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Matrix3_Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, values.pivot, CGM::ERotationOrder::XYZ);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.83215, +0.32006, -0.45287},
            CGM::Vector<3,double>{+0.03046, +0.78903, +0.61360},
            CGM::Vector<3,double>{+0.55372, -0.52440, +0.64684}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, values.pivot, CGM::ERotationOrder::XZY);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.81392, +0.32972, -0.47835},
            CGM::Vector<3,double>{-0.04927, +0.85956, +0.50866},
            CGM::Vector<3,double>{+0.57888, -0.39044, +0.71586}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, values.pivot, CGM::ERotationOrder::YXZ);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.82824, +0.46211, -0.31697},
            CGM::Vector<3,double>{-0.14216, +0.72041, +0.67882},
            CGM::Vector<3,double>{+0.54204, -0.51717, +0.66237}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, values.pivot, CGM::ERotationOrder::YZX);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.76549, +0.51974, -0.37933},
            CGM::Vector<3,double>{-0.12368, +0.69740, +0.70593},
            CGM::Vector<3,double>{+0.63144, -0.49347, +0.59813}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, values.pivot, CGM::ERotationOrder::ZXY);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.74585, +0.38293, -0.54504},
            CGM::Vector<3,double>{-0.04227, +0.84380, +0.53499},
            CGM::Vector<3,double>{+0.66477, -0.37598, +0.64554}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::orientation, values.rotation, values.pivot, CGM::ERotationOrder::ZYX);
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+0.73742, +0.53054, -0.41802},
            CGM::Vector<3,double>{-0.20652, +0.76636, +0.60831},
            CGM::Vector<3,double>{+0.64308, -0.36225, +0.67470}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations3D_Rotate, Matrix4_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated<CGM_3D_X>(cgm_test::space, values.rotation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.88295, +0.43529, +0.17587},
            CGM::Vector<3,double>{-0.45921, +0.72288, +0.51630},
            CGM::Vector<3,double>{+0.09761, -0.53663, +0.83815},
            CGM::Vector<3,double>{+0.25000, +1.59961, -0.75581}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated<CGM_3D_Y>(cgm_test::space, values.rotation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.81865, +0.46947, -0.33076},
            CGM::Vector<3,double>{-0.34789, +0.86365, +0.36480},
            CGM::Vector<3,double>{+0.45692, -0.18358, +0.87036},
            CGM::Vector<3,double>{-0.25519, +1.20000, -1.29899}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated<CGM_3D_Z>(cgm_test::space, values.rotation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.64279, +0.76604, +0.00000},
            CGM::Vector<3,double>{-0.74930, +0.62874, +0.20791},
            CGM::Vector<3,double>{+0.15927, -0.13364, +0.97815},
            CGM::Vector<3,double>{-0.21773, +1.20627, -1.30000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Matrix4_DefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, CGM::ERotationOrder::XYZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.94260, +0.16699, -0.28917},
            CGM::Vector<3,double>{+0.07791, +0.73209, +0.67674},
            CGM::Vector<3,double>{+0.32471, -0.66042, +0.67706},
            CGM::Vector<3,double>{+0.31333, +1.57690, -0.77955}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, CGM::ERotationOrder::XZY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.92939, +0.15812, -0.33351},
            CGM::Vector<3,double>{+0.06087, +0.82555, +0.56103},
            CGM::Vector<3,double>{+0.36404, -0.54172, +0.75764},
            CGM::Vector<3,double>{+0.23416, +1.45662, -1.00793}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, CGM::ERotationOrder::YXZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.90686, +0.35086, -0.23346},
            CGM::Vector<3,double>{-0.09165, +0.70490, +0.70336},
            CGM::Vector<3,double>{+0.41134, -0.61646, +0.67140},
            CGM::Vector<3,double>{+0.04774, +1.63884, -0.71022}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, CGM::ERotationOrder::YZX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.86850, +0.37436, -0.32489},
            CGM::Vector<3,double>{-0.02839, +0.69194, +0.72140},
            CGM::Vector<3,double>{+0.49487, -0.61731, +0.61158},
            CGM::Vector<3,double>{-0.06371, +1.65009, -0.68239}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, CGM::ERotationOrder::ZXY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.88585, +0.17692, -0.42891},
            CGM::Vector<3,double>{+0.11460, +0.81237, +0.57176},
            CGM::Vector<3,double>{+0.44959, -0.55565, +0.69937},
            CGM::Vector<3,double>{+0.10947, +1.48322, -0.99024}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, CGM::ERotationOrder::ZYX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.85011, +0.36078, -0.38360},
            CGM::Vector<3,double>{-0.05768, +0.78785, +0.61316},
            CGM::Vector<3,double>{+0.52343, -0.49913, +0.69057},
            CGM::Vector<3,double>{-0.13911, +1.52847, -0.91483}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Matrix4_ArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::rotated(cgm_test::space, values.rotation.x, cgm_test::axis);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+0.92997, +0.35407, +0.09899},
        CGM::Vector<3,double>{-0.35001, +0.77026, +0.53310},
        CGM::Vector<3,double>{+0.11250, -0.53042, +0.84024},
        CGM::Vector<3,double>{+0.36564, +1.64519, -0.65880}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Rotate, Matrix4_Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, values.pivot, CGM::ERotationOrder::XYZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.83215, +0.32006, -0.45287},
            CGM::Vector<3,double>{+0.03046, +0.78903, +0.61360},
            CGM::Vector<3,double>{+0.55372, -0.52440, +0.64684},
            CGM::Vector<3,double>{-0.06515, +1.63494, -0.54977}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, values.pivot, CGM::ERotationOrder::XZY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.81392, +0.32972, -0.47835},
            CGM::Vector<3,double>{-0.04927, +0.85956, +0.50866},
            CGM::Vector<3,double>{+0.57888, -0.39044, +0.71586},
            CGM::Vector<3,double>{-0.20372, +1.47929, -0.79607}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, values.pivot, CGM::ERotationOrder::YXZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.82824, +0.46211, -0.31697},
            CGM::Vector<3,double>{-0.14216, +0.72041, +0.67882},
            CGM::Vector<3,double>{+0.54204, -0.51717, +0.66237},
            CGM::Vector<3,double>{-0.22855, +1.63123, -0.43070}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, values.pivot, CGM::ERotationOrder::YZX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.76549, +0.51974, -0.37933},
            CGM::Vector<3,double>{-0.12368, +0.69740, +0.70593},
            CGM::Vector<3,double>{+0.63144, -0.49347, +0.59813},
            CGM::Vector<3,double>{-0.40209, +1.59831, -0.32496}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, values.pivot, CGM::ERotationOrder::ZXY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.74585, +0.38293, -0.54504},
            CGM::Vector<3,double>{-0.04227, +0.84380, +0.53499},
            CGM::Vector<3,double>{+0.66477, -0.37598, +0.64554},
            CGM::Vector<3,double>{-0.38619, +1.46773, -0.68292}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotated(cgm_test::space, values.rotation, values.pivot, CGM::ERotationOrder::ZYX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.73742, +0.53054, -0.41802},
            CGM::Vector<3,double>{-0.20652, +0.76636, +0.60831},
            CGM::Vector<3,double>{+0.64308, -0.36225, +0.67470},
            CGM::Vector<3,double>{-0.52578, +1.44649, -0.58436}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

TEST(Transformations3D_RotationMatrix, DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotationMatrix<CGM_3D_X,4>(values.rotation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.00000, +0.00000, +0.00000},
            CGM::Vector<3,double>{+0.00000, +0.92718, -0.37461},
            CGM::Vector<3,double>{+0.00000, +0.37461, +0.92718},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix<CGM_3D_Y,4>(values.rotation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.92718, +0.00000, +0.37461},
            CGM::Vector<3,double>{+0.00000, +1.00000, +0.00000},
            CGM::Vector<3,double>{-0.37461, +0.00000, +0.92718},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix<CGM_3D_Z,4>(values.rotation.x);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.92718, -0.37461, +0.00000},
            CGM::Vector<3,double>{+0.37461, +0.92718, +0.00000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +1.00000},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_RotationMatrix, DefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotationMatrix<4>(values.rotation, CGM::ERotationOrder::XYZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.82818, +0.45020, +0.33381},
            CGM::Vector<3,double>{-0.25320, +0.83191, -0.49378},
            CGM::Vector<3,double>{-0.50000, +0.32442, +0.80296},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix<4>(values.rotation, CGM::ERotationOrder::XZY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.82818, +0.42207, +0.36874},
            CGM::Vector<3,double>{-0.29237, +0.88667, -0.35824},
            CGM::Vector<3,double>{-0.47815, +0.18888, +0.85773},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix<4>(values.rotation, CGM::ERotationOrder::YXZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.88295, +0.27108, +0.38330},
            CGM::Vector<3,double>{-0.07408, +0.88667, -0.45643},
            CGM::Vector<3,double>{-0.46359, +0.37461, +0.80296},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix<4>(values.rotation, CGM::ERotationOrder::YZX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.82818, +0.29237, +0.47815},
            CGM::Vector<3,double>{-0.04746, +0.88667, -0.45996},
            CGM::Vector<3,double>{-0.55844, +0.35824, +0.74820},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix<4>(values.rotation, CGM::ERotationOrder::ZXY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.77342, +0.43232, +0.46359},
            CGM::Vector<3,double>{-0.27108, +0.88667, -0.37461},
            CGM::Vector<3,double>{-0.57300, +0.16406, +0.80296},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix<4>(values.rotation, CGM::ERotationOrder::ZYX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.82818, +0.25320, +0.50000},
            CGM::Vector<3,double>{-0.09196, +0.94143, -0.32442},
            CGM::Vector<3,double>{-0.55286, +0.22270, +0.80296},
            CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_RotationMatrix, Direction)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::rotationMatrix<4>(values.rotation.x, cgm_test::axis.direction);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+0.99282, +0.11365, +0.03727},
        CGM::Vector<3,double>{-0.09286, +0.92883, -0.35868},
        CGM::Vector<3,double>{-0.07539, +0.35264, +0.93272},
        CGM::Vector<3,double>{+0.00000, +0.00000, +0.00000}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_RotationMatrix, Axis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    const auto result = CGM::rotationMatrix(values.rotation.x, cgm_test::axis);
    const auto expect = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+0.99282, +0.11365, +0.03727},
        CGM::Vector<3,double>{-0.09286, +0.92883, -0.35868},
        CGM::Vector<3,double>{-0.07539, +0.35264, +0.93272},
        CGM::Vector<3,double>{+0.02951, +0.08753, +0.14940}
    );
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_RotationMatrix, Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;
    const auto values = cgm_xyz_xform_tests_data::get();

    {
        const auto result = CGM::rotationMatrix(values.rotation, values.pivot, CGM::ERotationOrder::XYZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.77480, +0.31533, +0.54795},
            CGM::Vector<3,double>{-0.13092, +0.92797, -0.34889},
            CGM::Vector<3,double>{-0.61850, +0.19859, +0.76028},
            CGM::Vector<3,double>{+0.07509, +0.10054, +0.35492}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix(values.rotation, values.pivot, CGM::ERotationOrder::XZY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.79778, +0.23329, +0.55599},
            CGM::Vector<3,double>{-0.14170, +0.96883, -0.20319},
            CGM::Vector<3,double>{-0.58606, +0.08332, +0.80597},
            CGM::Vector<3,double>{+0.03968, +0.08797, +0.29823}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix(values.rotation, values.pivot, CGM::ERotationOrder::YXZ);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.84948, +0.16655, +0.50064},
            CGM::Vector<3,double>{+0.02672, +0.93407, -0.35609},
            CGM::Vector<3,double>{-0.52694, +0.31587, +0.78903},
            CGM::Vector<3,double>{+0.01004, +0.04075, +0.34773}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix(values.rotation, values.pivot, CGM::ERotationOrder::YZX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.79432, +0.13664, +0.59193},
            CGM::Vector<3,double>{+0.09048, +0.93690, -0.33769},
            CGM::Vector<3,double>{-0.60072, +0.32179, +0.73184},
            CGM::Vector<3,double>{+0.00488, +0.01241, +0.39046}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix(values.rotation, values.pivot, CGM::ERotationOrder::ZXY);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.74285, +0.19161, +0.64145},
            CGM::Vector<3,double>{-0.08607, +0.97755, -0.19233},
            CGM::Vector<3,double>{-0.66390, +0.08766, +0.74266},
            CGM::Vector<3,double>{+0.03205, +0.06616, +0.34333}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::rotationMatrix(values.rotation, values.pivot, CGM::ERotationOrder::ZYX);
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+0.80871, +0.04978, +0.58609},
            CGM::Vector<3,double>{+0.08116, +0.97744, -0.19500},
            CGM::Vector<3,double>{-0.58258, +0.20527, +0.78643},
            CGM::Vector<3,double>{-0.02577, -0.00023, +0.33733}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}