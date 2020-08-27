

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Scale.hpp>


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
    const auto vec = Vector<3,float> {0.3f, 0.1f, 0.2f};
    const auto scl = Vector<3,float> {2.0f, 1.7f, 0.6f};
    const auto piv = CGM_XFORM3D::Pivot<float>
    {
        {0.910463f, 0.396517f, 0.117603f},
        {-0.358856f, 0.89873f, -0.252005f},
        {-0.205618f, 0.187238f, 0.960554f},
        {0.11f, 0.3f, 0.4f}
    };

    {
        auto pnt = vec;
        auto exp = Vector<3,float> {0.391407f, 0.0236731f, 0.346308f};
        CGM_XFORM3D::scale<CGM_POINT>(pnt, scl, piv);
        ASSERT_TRUE(CGM::eq(pnt, exp, 0.00001f));
    }
    {
        auto dir = vec;
        auto exp = Vector<3,float> {0.635594f, 0.1792867f, 0.194272f};
        CGM_XFORM3D::scale<CGM_DIRECTION>(dir, scl, piv);
        ASSERT_TRUE(CGM::eq(dir, exp, 0.00001f));
    }
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

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix3_RelatedPivot)
{
    const auto scales = Vector<3,float> {1.3f, 0.6f, 1.7f};
    const auto pivot = CGM_XYZ::Pivot<float>
    (
        Vector<3,float>{+0.94943f, +0.15037f, -0.27564f},
        Vector<3,float>{-0.01031f, +0.89232f, +0.45129f},
        Vector<3,float>{+0.31382f, -0.42562f, +0.84874f},
        Vector<3,float>{+0.40000f, -0.30000f, +0.20000f}
    );

    const auto space = CGM_XYZ::orientationMatrix
    (
        Vector<3,float>{+0.88295f, +0.46947f, +0.00000f},
        Vector<3,float>{-0.45921f, +0.86365f, +0.20791f},
        Vector<3,float>{+0.09761f, -0.18358f, +0.97815f}
    );

    {
        auto exp = CGM_XYZ::orientationMatrix
        (
            Vector<3,float>{+1.160494f, +0.341175f, -0.103227f},
            Vector<3,float>{-0.632783f, +0.636887f, -0.118114f},
            Vector<3,float>{+0.246755f, -0.571286f, +1.502986f}
        );

        auto mat = space;

        CGM_XFORM3D::scale<CGM_WORLD>(mat, scales, pivot);
        ASSERT_TRUE(CGM::eq(mat, exp, 0.0001f));
    }

    {
        auto exp = CGM_XYZ::orientationMatrix
        (
            Vector<3,float>{+1.147835f, +0.610311f, +0.000000f},
            Vector<3,float>{-0.275526f, +0.518190f, +0.124746f},
            Vector<3,float>{+0.165937f, -0.312086f, +1.662855f}
        );

        auto mat = space;

        CGM_XFORM3D::scale<CGM_LOCAL>(mat, scales);
        ASSERT_TRUE(CGM::eq(mat, exp, 0.0001f));
    }
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

TEST(Transformations_Scale, Matrix4_AlongXYZ)
{
    const auto scl = Vector<3,float> {1.3f, 0.6f, 1.7f};
    const auto space = CGM_XYZ::spaceMatrix
    (
        Vector<3,float>{0.95630f, 0.00000f, -0.29237f},
        Vector<3,float>{0.00000f, 1.00000f, 0.00000f},
        Vector<3,float>{0.29237f, 0.00000f, 0.95630f},
        Vector<3,float>{0.20000f, 0.10000f, -0.25000f}
    );

    {
        const auto exp = CGM_XYZ::spaceMatrix
        (
            Vector<3,float> {1.24320f, 0.00000f, -0.49703f},
            Vector<3,float> {0.00000f, 0.60000f, 0.00000f},
            Vector<3,float> {0.38008f, 0.00000f, 1.62572f},
            Vector<3,float> {0.26000f, 0.06000f, -0.42500f}
        );

        auto mat = space;
        CGM_XFORM3D::scale<CGM_WORLD>(mat, scl);

        ASSERT_TRUE(CGM::eq(mat, exp, 0.0001f));
    }

    {
        const auto exp = CGM_XYZ::spaceMatrix
        (
             Vector<3,float>{1.24320f, 0.00000f, -0.38008f},
             Vector<3,float>{0.00000f, 0.60000f, 0.00000f},
             Vector<3,float>{0.49703f, 0.00000f, 1.62572f},
             Vector<3,float>{0.20000f, 0.10000f, -0.25000f}
        );

        auto mat = space;
        CGM_XFORM3D::scale<CGM_LOCAL>(mat, scl);

        ASSERT_TRUE(CGM::eq(mat, exp, 0.0001f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Scale, Matrix4_RelatedPivot)
{
    const auto scales = Vector<3,float> {1.3f, 0.6f, 1.7f};
    const auto pivot = CGM_XYZ::Pivot<float>
    (
        Vector<3,float>{+0.94943f, +0.15037f, -0.27564f},
        Vector<3,float>{-0.01031f, +0.89232f, +0.45129f},
        Vector<3,float>{+0.31382f, -0.42562f, +0.84874f},
        Vector<3,float>{+0.40000f, -0.30000f, +0.20000f}
    );

    const auto space = CGM_XYZ::spaceMatrix
    (
        Vector<3,float>{+0.88295f, +0.46947f, +0.00000f},
        Vector<3,float>{-0.45921f, +0.86365f, +0.20791f},
        Vector<3,float>{+0.09761f, -0.18358f, +0.97815f},
        Vector<3,float>{+0.20000f, +0.00000f, +0.40000f}
    );

    {
        auto exp = CGM_XYZ::spaceMatrix
        (
            Vector<3,float>{+1.160494f, +0.341175f, -0.103227f},
            Vector<3,float>{-0.632783f, +0.636887f, -0.118114f},
            Vector<3,float>{+0.246755f, -0.571286f, +1.502986f},
            Vector<3,float>{+0.139999f, -0.131350f, +0.339242f}
        );

        auto mat = space;

        CGM_XFORM3D::scale<CGM_WORLD>(mat, scales, pivot);
        ASSERT_TRUE(CGM::eq(mat, exp, 0.0001f));
    }

    {
        auto exp = CGM_XYZ::spaceMatrix
        (
            Vector<3,float>{+1.147835f, +0.610311f, +0.000000f},
            Vector<3,float>{-0.275526f, +0.518190f, +0.124746f},
            Vector<3,float>{+0.165937f, -0.312086f, +1.662855f},
            Vector<3,float>{+0.200000f, +0.000000f, +0.400000f}
        );

        auto mat = space;

        CGM_XFORM3D::scale<CGM_LOCAL>(mat, scales);
        ASSERT_TRUE(CGM::eq(mat, exp, 0.0001f));
    }
}