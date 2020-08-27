

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Rotate.hpp>
#include <CGM/Modules/Core/Functions/IO.hpp>


/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations_Rotate, Vector_DefaultAxis)
{
    namespace in = cgm_xyz_xform_tests_data::rotate;

    {
        auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X>(in::vec, in::angle);
        auto expect = Vector<3,double>{0.25, 1.59961, -0.755811};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y>(in::vec, in::angle);
        auto expect = Vector<3,double>{-0.255193, 1.2, -1.29899};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z>(in::vec, in::angle);
        auto expect = Vector<3,double>{-0.217732, 1.20627, -1.3};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Vector_ArbitraryAxis)
{
    namespace in = cgm_xyz_xform_tests_data::rotate;

    {
        auto result = CGM_XFORM3D::rotated(in::vec, in::angle, in::axis.direction);
        auto expect = Vector<3,double>{-0.321438, 1.35528, -1.11911};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XFORM3D::rotated(in::vec, in::angle, in::axis);
        auto expect = Vector<3,double>{-0.00609612, 1.11703, -0.781169};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Vector_PivotPoint)
{
    namespace in =  cgm_xyz_xform_tests_data::rotate;

    auto result = CGM_XFORM3D::rotated(in::vec, in::angles, in::pivot);
    auto expect = Vector<3,double>{-0.065153, 1.63494, -0.549767};
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations_Rotate, Matrix3_DefaultAxis)
{
    namespace in = cgm_xyz_xform_tests_data::rotate;

    {
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_WORLD>(in::orient, in::angle);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.88295, -0.46234, -0.08152},
                Vector<3,double>{+0.46947, +0.86953, +0.15332},
                Vector<3,double>{+0.00000, -0.17365, +0.98481}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_WORLD>(in::orient, in::angle);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.85522, -0.45921, -0.24026},
                Vector<3,double>{+0.36652, +0.86365, -0.34608},
                Vector<3,double>{+0.36642, +0.20791, +0.90692}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_WORLD>(in::orient, in::angle);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.99068, -0.09502, +0.09761},
                Vector<3,double>{+0.11176, +0.97663, -0.18358},
                Vector<3,double>{-0.07789, +0.19277, +0.97815}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_LOCAL>(in::orient, in::angle);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.882950, -0.459210, +0.097610},
                Vector<3,double>{+0.435286, +0.878649, +0.196207},
                Vector<3,double>{-0.175866, -0.130761, +0.975693}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_LOCAL>(in::orient, in::angle);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.818657, -0.503659, -0.275917},
                Vector<3,double>{+0.469470, +0.863650, -0.183580},
                Vector<3,double>{+0.330757, +0.020747, +0.943490}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_LOCAL>(in::orient, in::angle);
            auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.994523, -0.102241, +0.021735},
                Vector<3,double>{+0.104527, +0.972786, -0.206777},
                Vector<3,double>{+0.000000, +0.207910, +0.978150}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Rotate, Matrix3_ArbitraryAxis)
{
    namespace in = cgm_xyz_xform_tests_data::rotate;

    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(in::orient, in::angle, in::axis.direction);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.90246, -0.34085, -0.26344},
            Vector<3,double>{+0.29554, +0.93479, -0.19703},
            Vector<3,double>{+0.31341, +0.09995, +0.94434}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(in::orient, in::angle, in::axis.direction);
        auto expect = CGM_XYZ::orientationMatrix
        (
            Vector<3,double>{+0.890806, -0.378111, -0.251991},
            Vector<3,double>{+0.379252, +0.924147, -0.046005},
            Vector<3,double>{+0.250273, -0.054595, +0.966637}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations_Rotate, Matrix4_DefaultAxis)
{
    namespace in = cgm_xyz_xform_tests_data::rotate;

    {
        {
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_WORLD>(in::space, in::angle);
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_WORLD>(in::space, in::angle);
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_WORLD>(in::space, in::angle);
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_X, CGM_LOCAL>(in::space, in::angle);
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Y, CGM_LOCAL>(in::space, in::angle);
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
            auto result = CGM_XFORM3D::rotated<CGM_3D_AXIS_Z, CGM_LOCAL>(in::space, in::angle);
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
    namespace in = cgm_xyz_xform_tests_data::rotate;

    {
        auto result = CGM_XFORM3D::rotated<CGM_WORLD>(in::space, in::angle, in::axis);
        auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.90246, -0.34085, -0.26344},
            Vector<3,double>{+0.29554, +0.93479, -0.19703},
            Vector<3,double>{+0.31341, +0.09995, +0.94434},
            Vector<3,double>{-0.00610, +1.11703, -0.78117}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XFORM3D::rotated<CGM_LOCAL>(in::space, in::angle, in::axis);
        auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+0.890806, -0.378111, -0.251991},
            Vector<3,double>{+0.379252, +0.924147, -0.046005},
            Vector<3,double>{+0.250273, -0.054595, +0.966637},
            Vector<3,double>{+0.416582, +0.919695, -0.894930}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}