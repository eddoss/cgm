

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Translate.hpp>


using namespace std;
using namespace CGM;


TEST(Transformations_Translation, Matrix4)
{
    {
        auto mat = identity<4,float>();
        auto offset = Vector<3,float>(2,4,5);
        CGM_XFORM3D::translate<CGM_WORLD>(mat, offset);

        auto expect = identity<4,float>();
        CGM_XYZ::setPosition(expect, offset);

        ASSERT_TRUE(CGM::eq(mat, expect, 0.00001f));
    }

    {
        auto x = Vector<3,float> { 0.947768f,  0.000000f, 0.318959f};
        auto y = Vector<3,float> {-0.118451f,  0.928486f, 0.351971f};
        auto z = Vector<3,float> {-0.296149f, -0.371368f, 0.879990f};
        auto p = Vector<3,float> { 1.000000f,  0.000000f, 0.000000f};
        auto mat = CGM_XFORM3D::spaceMatrix(x,y,z,p);

        auto offset = Vector<3,float>(0.2f, 0.1f, 0.3f);
        CGM_XFORM3D::translate<CGM_LOCAL>(mat, offset);

        auto expect = mat;
        CGM_XYZ::setPosition(expect, {1.08886, -0.0185618, 0.362986});

        ASSERT_TRUE(CGM::eq(mat, expect, 0.00001f));
    }
}