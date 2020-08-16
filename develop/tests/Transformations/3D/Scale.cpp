

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Scale.hpp>
#include <CGM/Modules/Core/Functions/IO.hpp>

using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations_Scale, Vector_AlongXYZ)
{
    auto vec = Vector<3,float> {2.0f, 3.0f, 1.0f};
    auto scl = Vector<3,float> {3.0f, 1.0f, 0.0f};
    auto exp = Vector<3,float> {6.0f, 3.0f, 0.0f};

    CGM_XFORM3D::scale(vec, scl);

    ASSERT_TRUE(CGM::eq(vec, exp, 0.00001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Vector_RelatedToPivot)
{
    auto vec = Vector<3,float> {0.3f, 0.1f, 0.2f};
    auto scl = Vector<3,float> {2.0f, 1.7f, 0.6f};
    auto piv = CGM_XFORM3D::Pivot<float>
    {
        {0.910463f, 0.396517f, 0.117603f},
        {-0.358856f, 0.89873f, -0.252005f},
        {-0.205618f, 0.187238f, 0.960554f},
        {0.11f, 0.3f, 0.4f}
    };
    auto exp = Vector<3,float> {0.391407f, 0.0236731f, 0.346308f};

    CGM_XFORM3D::scale(vec, scl, piv);

    ASSERT_TRUE(CGM::eq(vec, exp, 0.00001f));
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

TEST(Transformations_Scale, Matrix3_AlongXYZ)
{
    auto scl = Vector<3,float> {1.3f, 0.6f, 1.7f};

    {
        auto mat = CGM_XYZ::orientationMatrix
        (
            Vector<3,float>{0.955793f, 0.000000f, -0.294040f},
            Vector<3,float>{-0.030736f, 0.994522f, -0.099908f},
            Vector<3,float>{0.292430f, 0.104528f, 0.950557f}
        );

        auto exp = CGM_XYZ::orientationMatrix
        (
            Vector<3,float>{1.24253f, 0.0f, -0.499869f},
            Vector<3,float>{-0.0399563f, 0.596713f, -0.169843f},
            Vector<3,float>{0.380158f, 0.0627171f, 1.61595f}
        );

        CGM_XFORM3D::scale<CGM_WORLD>(mat, scl);

        ASSERT_TRUE(CGM::eq(mat, exp, 0.00001f));
    }

    {
        auto mat = CGM_XYZ::orientationMatrix
        (
            Vector<3,float>{0.955793f, 0.000000f, -0.294040f},
            Vector<3,float>{-0.030736f, 0.994522f, -0.099908f},
            Vector<3,float>{0.292430f, 0.104528f, 0.950557f}
        );

        auto exp = CGM_XYZ::orientationMatrix
        (
            Vector<3,float>{1.24253f, 0.0f, -0.382252f},
            Vector<3,float>{-0.01844f, 0.596713f, -0.0599446f},
            Vector<3,float>{0.49713f, 0.177698f, 1.61595f}
        );

        CGM_XFORM3D::scale<CGM_LOCAL>(mat, scl);

        ASSERT_TRUE(CGM::eq(mat, exp, 0.00001f));
    }
}