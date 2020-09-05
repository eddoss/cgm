

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Rotate.hpp>


/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations_Rotate, Vector_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X>(cgm_test::vector, cgm_test::rotate::value);
        const auto expect = Vector<3,double>{0.25, 1.59961, -0.755811};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y>(cgm_test::vector, cgm_test::rotate::value);
        const auto expect = Vector<3,double>{-0.255193, 1.2, -1.29899};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z>(cgm_test::vector, cgm_test::rotate::value);
        const auto expect = Vector<3,double>{-0.217732, 1.20627, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Vector_ArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::value, cgm_test::axis.direction);
        const auto expect = Vector<3,double>{0.336132, 1.55767, -0.808204};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::value, cgm_test::axis);
        const auto expect = Vector<3,double>{0.365645, 1.6452, -0.6588};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Vector_PivotPoint)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XYZ);
        const auto expect = Vector<3,double>{-0.0651531, 1.63494, -0.549767};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XZY);
        const auto expect = Vector<3,double>{-0.203716, 1.47929, -0.796071};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YXZ);
        const auto expect = Vector<3,double>{-0.228551, 1.63123, -0.430698};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YZX);
        const auto expect = Vector<3,double>{-0.402085, 1.59831, -0.324956};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZXY);
        const auto expect = Vector<3,double>{-0.386189, 1.46773, -0.682916};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZYX);
        const auto expect = Vector<3,double>{-0.525776, 1.44649, -0.584356};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations_Rotate, Matrix3_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.88295, +0.43529, +0.17587},
                Vector<3,double>{-0.45921, +0.72288, +0.51630},
                Vector<3,double>{+0.09761, -0.53663, +0.83815}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.81865, +0.46947, -0.33076},
                Vector<3,double>{-0.34789, +0.86365, +0.36480},
                Vector<3,double>{+0.45692, -0.18358, +0.87036}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.64279, +0.76604, +0.00000},
                Vector<3,double>{-0.74930, +0.62874, +0.20791},
                Vector<3,double>{+0.15927, -0.13364, +0.97815}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.882950, +0.469470, +0.000000},
                Vector<3,double>{-0.389208, +0.731994, +0.559190},
                Vector<3,double>{+0.262526, -0.493744, +0.829038}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.782093, +0.504053, -0.366419},
                Vector<3,double>{-0.459210, +0.863650, +0.207910},
                Vector<3,double>{+0.421260, +0.005654, +0.906926}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.646633, +0.758816, +0.077887},
                Vector<3,double>{-0.756530, +0.624896, +0.192770},
                Vector<3,double>{+0.097610, -0.183580, +0.978150}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Matrix3_DefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XYZ);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.94260, +0.16699, -0.28917},
                Vector<3,double>{+0.07791, +0.73209, +0.67674},
                Vector<3,double>{+0.32471, -0.66042, +0.67706}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XZY);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.92939, +0.15812, -0.33351},
                Vector<3,double>{+0.06087, +0.82555, +0.56103},
                Vector<3,double>{+0.36404, -0.54172, +0.75764}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YXZ);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.90686, +0.35086, -0.23346},
                Vector<3,double>{-0.09165, +0.70490, +0.70336},
                Vector<3,double>{+0.41134, -0.61646, +0.67140}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YZX);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.86850, +0.37436, -0.32489},
                Vector<3,double>{-0.02839, +0.69194, +0.72140},
                Vector<3,double>{+0.49487, -0.61731, +0.61158}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZXY);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.88585, +0.17692, -0.42891},
                Vector<3,double>{+0.11460, +0.81237, +0.57176},
                Vector<3,double>{+0.44959, -0.55565, +0.69937}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZYX);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.85011, +0.36078, -0.38360},
                Vector<3,double>{-0.05768, +0.78785, +0.61316},
                Vector<3,double>{+0.52343, -0.49913, +0.69057}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XYZ);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.719513, +0.410873, -0.559899},
                Vector<3,double>{-0.187015, +0.891057, +0.413563},
                Vector<3,double>{+0.668829, -0.192861, +0.717969}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XZY);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.698532, +0.450333, -0.556108},
                Vector<3,double>{-0.114052, +0.837269, +0.534756},
                Vector<3,double>{+0.706435, -0.310125, +0.636222}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YXZ);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.751448, +0.234165, -0.616843},
                Vector<3,double>{-0.009439, +0.938617, +0.344820},
                Vector<3,double>{+0.659728, -0.253298, +0.707535}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YZX);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.818835, +0.224075, -0.528491},
                Vector<3,double>{-0.016069, +0.929247, +0.369097},
                Vector<3,double>{+0.573807, -0.293744, +0.764504}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZXY);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.768368, +0.435637, -0.468865},
                Vector<3,double>{-0.131252, +0.824270, +0.550767},
                Vector<3,double>{+0.626410, -0.361659, +0.690522}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZYX);
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.798715, +0.261915, -0.541718},
                Vector<3,double>{+0.047149, +0.870278, +0.490291},
                Vector<3,double>{+0.599863, -0.417151, +0.682757}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Matrix3_ArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value, cgm_test::axis.direction);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.92997, +0.35407, +0.09899},
            Vector<3,double>{-0.35001, +0.77026, +0.53310},
            Vector<3,double>{+0.11250, -0.53042, +0.84024}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value, cgm_test::axis.direction);
        const auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.911896, +0.399739, -0.093046},
            Vector<3,double>{-0.291758, +0.790804, +0.538050},
            Vector<3,double>{+0.288663, -0.463506, +0.837760}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations_Rotate, Matrix4_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_WORLD>(cgm_test::space, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.88295, +0.43529, +0.17587},
                Vector<3,double>{-0.45921, +0.72288, +0.51630},
                Vector<3,double>{+0.09761, -0.53663, +0.83815},
                Vector<3,double>{+0.25000, +1.59961, -0.75581}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_WORLD>(cgm_test::space, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.81865, +0.46947, -0.33076},
                Vector<3,double>{-0.34789, +0.86365, +0.36480},
                Vector<3,double>{+0.45692, -0.18358, +0.87036},
                Vector<3,double>{-0.25519, +1.20000, -1.29899}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_WORLD>(cgm_test::space, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.64279, +0.76604, +0.00000},
                Vector<3,double>{-0.74930, +0.62874, +0.20791},
                Vector<3,double>{+0.15927, -0.13364, +0.97815},
                Vector<3,double>{-0.21773, +1.20627, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.882950, +0.469470, +0.000000},
                Vector<3,double>{-0.389208, +0.731994, +0.559190},
                Vector<3,double>{+0.262526, -0.493744, +0.829038},
                Vector<3,double>{+0.053582, +1.569411, -0.852395}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.782093, +0.504053, -0.366419},
                Vector<3,double>{-0.459210, +0.863650, +0.207910},
                Vector<3,double>{+0.421260, +0.005654, +0.906926},
                Vector<3,double>{-0.304030, +0.949421, -1.482790}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.646633, +0.758816, +0.077887},
                Vector<3,double>{-0.756530, +0.624896, +0.192770},
                Vector<3,double>{+0.097610, -0.183580, +0.978150},
                Vector<3,double>{-0.128938, +1.271377, -1.248789}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Matrix4_DefaultAxes)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XYZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.94260, +0.16699, -0.28917},
                Vector<3,double>{+0.07791, +0.73209, +0.67674},
                Vector<3,double>{+0.32471, -0.66042, +0.67706},
                Vector<3,double>{+0.31333, +1.57690, -0.77955}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XZY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.92939, +0.15812, -0.33351},
                Vector<3,double>{+0.06087, +0.82555, +0.56103},
                Vector<3,double>{+0.36404, -0.54172, +0.75764},
                Vector<3,double>{+0.23416, +1.45662, -1.00793}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YXZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.90686, +0.35086, -0.23346},
                Vector<3,double>{-0.09165, +0.70490, +0.70336},
                Vector<3,double>{+0.41134, -0.61646, +0.67140},
                Vector<3,double>{+0.04774, +1.63884, -0.71022}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YZX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.86850, +0.37436, -0.32489},
                Vector<3,double>{-0.02839, +0.69194, +0.72140},
                Vector<3,double>{+0.49487, -0.61731, +0.61158},
                Vector<3,double>{-0.06371, +1.65009, -0.68239}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZXY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.88585, +0.17692, -0.42891},
                Vector<3,double>{+0.11460, +0.81237, +0.57176},
                Vector<3,double>{+0.44959, -0.55565, +0.69937},
                Vector<3,double>{+0.10947, +1.48322, -0.99024}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZYX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.85011, +0.36078, -0.38360},
                Vector<3,double>{-0.05768, +0.78785, +0.61316},
                Vector<3,double>{+0.52343, -0.49913, +0.69057},
                Vector<3,double>{-0.13911, +1.52847, -0.91483}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }

    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XYZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.798715, +0.261915, -0.541718},
                Vector<3,double>{+0.047149, +0.870278, +0.490291},
                Vector<3,double>{+0.599863, -0.417151, +0.682757},
                Vector<3,double>{+0.250000, +1.200000, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XZY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.818835, +0.224075, -0.528491},
                Vector<3,double>{-0.016069, +0.929247, +0.369097},
                Vector<3,double>{+0.573807, -0.293744, +0.764504},
                Vector<3,double>{+0.250000, +1.200000, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YXZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.768368, +0.435637, -0.468865},
                Vector<3,double>{-0.131252, +0.824270, +0.550767},
                Vector<3,double>{+0.626410, -0.361659, +0.690522},
                Vector<3,double>{+0.250000, +1.200000, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YZX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.698532, +0.450333, -0.556108},
                Vector<3,double>{-0.114052, +0.837269, +0.534756},
                Vector<3,double>{+0.706435, -0.310125, +0.636222},
                Vector<3,double>{+0.250000, +1.200000, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZXY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.751448, +0.234165, -0.616843},
                Vector<3,double>{-0.009439, +0.938617, +0.344820},
                Vector<3,double>{+0.659728, -0.253298, +0.707535},
                Vector<3,double>{+0.250000, +1.200000, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZYX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.719513, +0.410873, -0.559899},
                Vector<3,double>{-0.187015, +0.891057, +0.413563},
                Vector<3,double>{+0.668829, -0.192861, +0.717969},
                Vector<3,double>{+0.250000, +1.200000, -1.300000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Matrix4_ArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::value, cgm_test::axis);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.92997, +0.35407, +0.09899},
            Vector<3,double>{-0.35001, +0.77026, +0.53310},
            Vector<3,double>{+0.11250, -0.53042, +0.84024},
            Vector<3,double>{+0.36564, +1.64519, -0.65880}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value, cgm_test::axis);
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.911895, +0.399740, -0.093046},
            Vector<3,double>{-0.291760, +0.790804, +0.538050},
            Vector<3,double>{+0.288663, -0.463505, +0.837761},
            Vector<3,double>{+0.250447, +1.262022, -1.135662}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Matrix4_Pivot)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XYZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.83215, +0.32006, -0.45287},
                Vector<3,double>{+0.03046, +0.78903, +0.61360},
                Vector<3,double>{+0.55372, -0.52440, +0.64684},
                Vector<3,double>{-0.06515, +1.63494, -0.54977}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XZY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.81392, +0.32972, -0.47835},
                Vector<3,double>{-0.04927, +0.85956, +0.50866},
                Vector<3,double>{+0.57888, -0.39044, +0.71586},
                Vector<3,double>{-0.20372, +1.47929, -0.79607}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YXZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.82824, +0.46211, -0.31697},
                Vector<3,double>{-0.14216, +0.72041, +0.67882},
                Vector<3,double>{+0.54204, -0.51717, +0.66237},
                Vector<3,double>{-0.22855, +1.63123, -0.43070}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YZX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.76549, +0.51974, -0.37933},
                Vector<3,double>{-0.12368, +0.69740, +0.70593},
                Vector<3,double>{+0.63144, -0.49347, +0.59813},
                Vector<3,double>{-0.40209, +1.59831, -0.32496}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZXY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.74585, +0.38293, -0.54504},
                Vector<3,double>{-0.04227, +0.84380, +0.53499},
                Vector<3,double>{+0.66477, -0.37598, +0.64554},
                Vector<3,double>{-0.38619, +1.46773, -0.68292}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZYX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.73742, +0.53054, -0.41802},
                Vector<3,double>{-0.20652, +0.76636, +0.60831},
                Vector<3,double>{+0.64308, -0.36225, +0.67470},
                Vector<3,double>{-0.52578, +1.44649, -0.58436}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }

    {
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XYZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.619918, +0.556712, -0.552971},
                Vector<3,double>{-0.384867, +0.829849, +0.404005},
                Vector<3,double>{+0.683803, -0.037634, +0.728701},
                Vector<3,double>{+0.260279, +1.125774, -0.970095}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XZY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.601158, +0.561339, -0.568779},
                Vector<3,double>{-0.278183, +0.814223, +0.509556},
                Vector<3,double>{+0.749152, -0.148104, +0.645634},
                Vector<3,double>{+0.286718, +1.141329, -0.915493}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YXZ);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.630617, +0.396290, -0.667293},
                Vector<3,double>{-0.271165, +0.918120, +0.288991},
                Vector<3,double>{+0.727185, -0.001301, +0.686445},
                Vector<3,double>{+0.281433, +1.209158, -0.950419}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YZX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.712262, +0.359745, -0.602718},
                Vector<3,double>{-0.230788, +0.930956, +0.282930},
                Vector<3,double>{+0.662892, -0.062425, +0.746113},
                Vector<3,double>{+0.273747, +1.239851, -0.990001}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZXY);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.686344, +0.518624, -0.509867},
                Vector<3,double>{-0.251052, +0.826912, +0.503170},
                Vector<3,double>{+0.682576, -0.217351, +0.697750},
                Vector<3,double>{+0.274098, +1.176071, -0.951396}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZYX);
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.683861, +0.364222, -0.632202},
                Vector<3,double>{-0.128339, +0.913022, +0.387184},
                Vector<3,double>{+0.718240, -0.183650, +0.671126},
                Vector<3,double>{+0.304772, +1.256924, -0.931934}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}