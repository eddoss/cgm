

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Rotate.hpp>


/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations_Rotate, Vector_DefaultAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X>(cgm_test::vector, cgm_test::rotate::value);
        auto expect = Vector<3,double>{0.25, 1.59961, -0.755811};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y>(cgm_test::vector, cgm_test::rotate::value);
        auto expect = Vector<3,double>{-0.255193, 1.2, -1.29899};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z>(cgm_test::vector, cgm_test::rotate::value);
        auto expect = Vector<3,double>{-0.217732, 1.20627, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Vector_ArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::value, cgm_test::axis.direction);
        auto expect = Vector<3,double>{0.336132, 1.55767, -0.808204};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::value, cgm_test::axis);
        auto expect = Vector<3,double>{0.365645, 1.6452, -0.6588};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Vector_PivotPoint)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XYZ);
        auto expect = Vector<3,double>{-0.0651531, 1.63494, -0.549767};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XZY);
        auto expect = Vector<3,double>{-0.203716, 1.47929, -0.796071};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YXZ);
        auto expect = Vector<3,double>{-0.228551, 1.63123, -0.430698};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YZX);
        auto expect = Vector<3,double>{-0.402085, 1.59831, -0.324956};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZXY);
        auto expect = Vector<3,double>{-0.386189, 1.46773, -0.682916};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated(cgm_test::vector, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZYX);
        auto expect = Vector<3,double>{-0.525776, 1.44649, -0.584356};
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.88295, +0.43529, +0.17587},
                Vector<3,double>{-0.45921, +0.72288, +0.51630},
                Vector<3,double>{+0.09761, -0.53663, +0.83815}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.81865, +0.46947, -0.33076},
                Vector<3,double>{-0.34789, +0.86365, +0.36480},
                Vector<3,double>{+0.45692, -0.18358, +0.87036}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value);
            auto expect = CGM_XYZ::orientationMatrix
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.882950, +0.469470, +0.000000},
                Vector<3,double>{-0.389208, +0.731994, +0.559190},
                Vector<3,double>{+0.262526, -0.493744, +0.829038}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.782093, +0.504053, -0.366419},
                Vector<3,double>{-0.459210, +0.863650, +0.207910},
                Vector<3,double>{+0.421260, +0.005654, +0.906926}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value);
            auto expect = CGM_XYZ::orientationMatrix
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

TEST(Transformations_Rotate, Matrix3_ArbitraryAxis)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::value, cgm_test::axis.direction);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.92997, +0.35407, +0.09899},
            Vector<3,double>{-0.35001, +0.77026, +0.53310},
            Vector<3,double>{+0.11250, -0.53042, +0.84024}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::orientation, cgm_test::rotate::value, cgm_test::axis.direction);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.911896, +0.399739, -0.093046},
            Vector<3,double>{-0.291758, +0.790804, +0.538050},
            Vector<3,double>{+0.288663, -0.463506, +0.837760}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Matrix3_RotationOrder)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XYZ);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.83215, +0.32006, -0.45287},
            Vector<3,double>{+0.03046, +0.78903, +0.61360},
            Vector<3,double>{+0.55372, -0.52440, +0.64684}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::XZY);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.81392, +0.32972, -0.47835},
            Vector<3,double>{-0.04927, +0.85956, +0.50866},
            Vector<3,double>{+0.57888, -0.39044, +0.71586}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YXZ);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.82824, +0.46211, -0.31697},
            Vector<3,double>{-0.14216, +0.72041, +0.67882},
            Vector<3,double>{+0.54204, -0.51717, +0.66237}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::YZX);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.76549, +0.51974, -0.37933},
            Vector<3,double>{-0.12368, +0.69740, +0.70593},
            Vector<3,double>{+0.63144, -0.49347, +0.59813}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZXY);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.74585, +0.38293, -0.54504},
            Vector<3,double>{-0.04227, +0.84380, +0.53499},
            Vector<3,double>{+0.66477, -0.37598, +0.64554}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::orientation, cgm_test::rotate::values, CGM_XFORM3D::ERotationOrder::ZYX);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.73742, +0.53054, -0.41802},
            Vector<3,double>{-0.20652, +0.76636, +0.60831},
            Vector<3,double>{+0.64308, -0.36225, +0.67470}
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_WORLD>(cgm_test::space, cgm_test::rotate::value);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.88295, -0.46234, -0.08152},
                Vector<3,double>{+0.46947, +0.86953, +0.15332},
                Vector<3,double>{+0.00000, -0.17365, +0.98481},
                Vector<3,double>{+0.25000, +1.59961, -0.75581}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_WORLD>(cgm_test::space, cgm_test::rotate::value);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.85522, -0.45921, -0.24026},
                Vector<3,double>{+0.36652, +0.86365, -0.34608},
                Vector<3,double>{+0.36642, +0.20791, +0.90692},
                Vector<3,double>{-0.25519, +1.20000, -1.29899}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_WORLD>(cgm_test::space, cgm_test::rotate::value);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.99068, -0.09502, +0.09761},
                Vector<3,double>{+0.11176, +0.97663, -0.18358},
                Vector<3,double>{-0.07789, +0.19277, +0.97815},
                Vector<3,double>{-0.21773, +1.20627, -1.30000}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.882950, -0.459210, +0.097610},
                Vector<3,double>{+0.435286, +0.878649, +0.196207},
                Vector<3,double>{-0.175866, -0.130761, +0.975693},
                Vector<3,double>{+0.382152, +1.567036, -0.768673}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.818657, -0.503659, -0.275917},
                Vector<3,double>{+0.469470, +0.863650, -0.183580},
                Vector<3,double>{+0.330757, +0.020747, +0.943490},
                Vector<3,double>{-0.058668, +1.411620, -1.093795}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.994523, -0.102241, +0.021735},
                Vector<3,double>{+0.104527, +0.972786, -0.206777},
                Vector<3,double>{+0.000000, +0.207910, +0.978150},
                Vector<3,double>{-0.309159, +1.188752, -1.297609}
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
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::value, cgm_test::axis);
        auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.89129, -0.36310, -0.27159},
            Vector<3,double>{+0.32844, +0.92993, -0.16542},
            Vector<3,double>{+0.31262, +0.05823, +0.94809},
            Vector<3,double>{+0.29500, +1.12563, -1.10991}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::value, cgm_test::axis);
        auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.885438, -0.398033, -0.239942},
            Vector<3,double>{+0.407476, +0.913146, -0.011128},
            Vector<3,double>{+0.223532, -0.087926, +0.970725},
            Vector<3,double>{+0.619179, +0.695352, -1.228228}
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
            auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XYZ);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.59279, -0.57579, -0.56308},
                Vector<3,double>{+0.53549, +0.80403, -0.25843},
                Vector<3,double>{+0.60153, -0.14833, +0.78495},
                Vector<3,double>{-0.06515, +1.63494, -0.54977}
            );
            CGM_PRINT(result)
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XZY);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.65154, -0.58985, -0.47705},
                Vector<3,double>{+0.47395, +0.80751, -0.35114},
                Vector<3,double>{+0.59234, +0.00268, +0.80568},
                Vector<3,double>{-0.20372, +1.47929, -0.79607}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YXZ);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.72243, -0.44010, -0.53329},
                Vector<3,double>{+0.45075, +0.88463, -0.11943},
                Vector<3,double>{+0.52433, -0.15410, +0.83746},
                Vector<3,double>{-0.22855, +1.63123, -0.43070}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YZX);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.69638, -0.38331, -0.60674},
                Vector<3,double>{+0.38226, +0.91363, -0.13845},
                Vector<3,double>{+0.60740, -0.13552, +0.78275},
                Vector<3,double>{-0.40209, +1.59831, -0.32496}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZXY);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.63052, -0.54367, -0.55396},
                Vector<3,double>{+0.39648, +0.83916, -0.37231},
                Vector<3,double>{+0.66727, +0.01512, +0.74466},
                Vector<3,double>{-0.38619, +1.46773, -0.68292}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_WORLD>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZYX);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.74840, -0.39623, -0.53188},
                Vector<3,double>{+0.31507, +0.91807, -0.24059},
                Vector<3,double>{+0.58363, +0.01248, +0.81192},
                Vector<3,double>{-0.52578, +1.44649, -0.58436}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }

    {
        {
            auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XYZ);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.89129, -0.36310, -0.27159},
                Vector<3,double>{+0.32844, +0.92993, -0.16542},
                Vector<3,double>{+0.31262, +0.05823, +0.94809},
                Vector<3,double>{+0.29500, +1.12563, -1.10991}
            );
            CGM_PRINT(result)
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::XZY);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.89129, -0.36310, -0.27159},
                Vector<3,double>{+0.32844, +0.92993, -0.16542},
                Vector<3,double>{+0.31262, +0.05823, +0.94809},
                Vector<3,double>{+0.29500, +1.12563, -1.10991}
            );
            CGM_PRINT(result)
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YXZ);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.89129, -0.36310, -0.27159},
                Vector<3,double>{+0.32844, +0.92993, -0.16542},
                Vector<3,double>{+0.31262, +0.05823, +0.94809},
                Vector<3,double>{+0.29500, +1.12563, -1.10991}
            );
            CGM_PRINT(result)
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::YZX);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.89129, -0.36310, -0.27159},
                Vector<3,double>{+0.32844, +0.92993, -0.16542},
                Vector<3,double>{+0.31262, +0.05823, +0.94809},
                Vector<3,double>{+0.29500, +1.12563, -1.10991}
            );
            CGM_PRINT(result)
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZXY);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.89129, -0.36310, -0.27159},
                Vector<3,double>{+0.32844, +0.92993, -0.16542},
                Vector<3,double>{+0.31262, +0.05823, +0.94809},
                Vector<3,double>{+0.29500, +1.12563, -1.10991}
            );
            CGM_PRINT(result)
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(cgm_test::space, cgm_test::rotate::values, cgm_test::pivot, CGM_XFORM3D::ERotationOrder::ZYX);
            auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.89129, -0.36310, -0.27159},
                Vector<3,double>{+0.32844, +0.92993, -0.16542},
                Vector<3,double>{+0.31262, +0.05823, +0.94809},
                Vector<3,double>{+0.29500, +1.12563, -1.10991}
            );
            CGM_PRINT(result)
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}