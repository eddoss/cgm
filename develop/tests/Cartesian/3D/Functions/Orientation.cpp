

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Functions/Orientation.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_3D_Functions_Orientation, Axes_Matrix3)
{
    Vector<3,double> in_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> in_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> in_z {0.333334, -0.244017, 0.910683};

    Matrix<3,3,double> mat {};

    MATH3D_XYZ_NAMESPACE::setX(mat, in_x);
    MATH3D_XYZ_NAMESPACE::setY(mat, in_y);
    MATH3D_XYZ_NAMESPACE::setZ(mat, in_z);

    auto [x, y, z] = MATH3D_XYZ_NAMESPACE::orientationAxes(mat);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(in_x, x, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(in_y, y, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(in_z, z, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Orientation, Axes_Matrix4)
{
    Vector<3,double> in_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> in_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> in_z {0.333334, -0.244017, 0.910683};

    Matrix<4,4,double> mat {};

    MATH3D_XYZ_NAMESPACE::setX(mat, in_x);
    MATH3D_XYZ_NAMESPACE::setY(mat, in_y);
    MATH3D_XYZ_NAMESPACE::setZ(mat, in_z);

    auto [x, y, z] = MATH3D_XYZ_NAMESPACE::orientationAxes(mat);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(in_x, x, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(in_y, y, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(in_z, z, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Orientation, Axes_Quaternion)
{
    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> in_orientation {0.965926, 0.149429, 0.149429, 0.149429};

    Vector<3,double> expec_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> expec_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> expec_z {0.333334, -0.244017, 0.910683};

    auto [x, y, z] = MATH3D_XYZ_NAMESPACE::orientationAxes(in_orientation);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec_x, x, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec_y, y, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec_z, z, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Orientation, Matrix_Quaternion)
{
    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> in_orientation {0.965926, 0.149429, 0.149429, 0.149429};

    Vector<3,double> expec_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> expec_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> expec_z {0.333334, -0.244017, 0.910683};

    Matrix<3,3,double> expec {};

    MATH3D_XYZ_NAMESPACE::setX(expec, expec_x);
    MATH3D_XYZ_NAMESPACE::setY(expec, expec_y);
    MATH3D_XYZ_NAMESPACE::setZ(expec, expec_z);

    auto res = MATH3D_XYZ_NAMESPACE::orientationMatrix(in_orientation);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(res, expec, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Orientation, Matrix_XYZ)
{
    Vector<3,double> in_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> in_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> in_z {0.333334, -0.244017, 0.910683};

    Matrix<3,3,double> expec {};

    MATH3D_XYZ_NAMESPACE::setX(expec, in_x);
    MATH3D_XYZ_NAMESPACE::setY(expec, in_y);
    MATH3D_XYZ_NAMESPACE::setZ(expec, in_z);

    auto res = MATH3D_XYZ_NAMESPACE::orientationMatrix(in_x, in_y, in_z);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(res, expec, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Orientation, Quaternion_Matrix3)
{
    Vector<3,double> in_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> in_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> in_z {0.333334, -0.244017, 0.910683};

    Matrix<3,3,double> in_orientation {};

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> expec {0.965926, 0.149429, 0.149429, 0.149429};

    MATH3D_XYZ_NAMESPACE::setX(in_orientation, in_x);
    MATH3D_XYZ_NAMESPACE::setY(in_orientation, in_y);
    MATH3D_XYZ_NAMESPACE::setZ(in_orientation, in_z);

    auto res = MATH3D_XYZ_NAMESPACE::orientationQuaternion(in_orientation);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(res, expec, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Orientation, Quaternion_Matrix4)
{
    Vector<3,double> in_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> in_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> in_z {0.333334, -0.244017, 0.910683};

    Matrix<4,4,double> in_space {};

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> expec {0.965926, 0.149429, 0.149429, 0.149429};

    MATH3D_XYZ_NAMESPACE::setX(in_space, in_x);
    MATH3D_XYZ_NAMESPACE::setY(in_space, in_y);
    MATH3D_XYZ_NAMESPACE::setZ(in_space, in_z);

    auto res = MATH3D_XYZ_NAMESPACE::orientationQuaternion(in_space);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(res, expec, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Orientation, Quaternion_XYZ)
{
    Vector<3,double> in_x {0.910683, 0.333334, -0.244017};
    Vector<3,double> in_y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> in_z {0.333334, -0.244017, 0.910683};

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> expec {0.965926, 0.149429, 0.149429, 0.149429};


    auto res = MATH3D_XYZ_NAMESPACE::orientationQuaternion(in_x, in_y, in_z);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(res, expec, 0.00001));
}