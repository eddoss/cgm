

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
        auto mat = identity<4,double>();
        auto offset = Vector<3,double>(2,4,5);
        CGM_XFORM3D::translate<CGM_WORLD>(mat, offset);

        auto expect = identity<4,double>();
        CGM_XYZ::setPosition(expect, offset);

        ASSERT_TRUE(CGM::eq(mat, expect, 0.00001));
    }

    {
        auto x = Vector<3,double> { 0.947768,  0.000000, 0.318959};
        auto y = Vector<3,double> {-0.118451,  0.928486, 0.351971};
        auto z = Vector<3,double> {-0.296149, -0.371368, 0.879990};
        auto p = Vector<3,double> { 1.000000,  0.000000, 0.000000};
        auto mat = CGM_XFORM3D::spaceMatrix(x,y,z,p);

        auto offset = Vector<3,double>(0.2, 0.1, 0.3);
        CGM_XFORM3D::translate<CGM_LOCAL>(mat, offset);

        auto expect = mat;
        CGM_XYZ::setPosition(expect, {1.08886, -0.0185618, 0.362986});

        ASSERT_TRUE(CGM::eq(mat, expect, 0.00001));
    }
}