

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Primitives/Functions/Numbers.hpp>
#include <CGM/Modules/Primitives/Functions/Comparison.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>


using namespace std;

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationAxes, FromXYZ)
{
    CGM::Vector<3,int> x {1, 2, 3};
    CGM::Vector<3,int> y {4, 5, 6};
    CGM::Vector<3,int> z {7, 8, 9};

    auto axes = CGM::orientationAxes(x, y, z);

    ASSERT_TRUE(CGM::x(axes) == x);
    ASSERT_TRUE(CGM::y(axes) == y);
    ASSERT_TRUE(CGM::z(axes) == z);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromMatrix3x3)
{
    CGM::Vector<3,int> in_x {1, 2, 3};
    CGM::Vector<3,int> in_y {4, 5, 6};
    CGM::Vector<3,int> in_z {7, 8, 9};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> mat
    {
        in_x.x, in_y.x, in_z.x,
        in_x.y, in_y.y, in_z.y,
        in_x.z, in_y.z, in_z.z
    };
#else
    CGM::Matrix<3,3,int> mat
    {
        in_x.x, in_x.y, in_x.z,
        in_y.x, in_y.y, in_y.z,
        in_z.x, in_z.y, in_z.z,
    };
#endif

    auto [x, y, z] = CGM::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
    ASSERT_TRUE(in_z == z);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromQuaternion)
{
    CGM::Vector<3,double> expec_x {0.559270,0.302442,-0.771846};
    CGM::Vector<3,double> expec_y {-0.313298,0.939132,0.140980};
    CGM::Vector<3,double> expec_z {0.767503,0.162971,0.619983};

    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};
    auto [x, y, z] = CGM::orientationAxes(quat);

    ASSERT_TRUE(CGM::eq(expec_x, x, 0.00001));
    ASSERT_TRUE(CGM::eq(expec_y, y, 0.00001));
    ASSERT_TRUE(CGM::eq(expec_z, z, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromMatrix4x4)
{
    CGM::Vector<3,int> in_x {1, 2, 3};
    CGM::Vector<3,int> in_y {4, 5, 6};
    CGM::Vector<3,int> in_z {7, 8, 9};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<4,4,int> mat
    {
        in_x.x, in_y.x, in_z.x, 0,
        in_x.y, in_y.y, in_z.y, 0,
        in_x.z, in_y.z, in_z.z, 0,
        0, 0, 0, 1
    };
#else
    CGM::Matrix<4,4,int> mat
    {
        in_x.x, in_x.y, in_x.z, 0,
        in_y.x, in_y.y, in_y.z, 0,
        in_z.x, in_z.y, in_z.z, 0,
        0, 0, 0, 1
    };
#endif

    auto [x, y, z] = CGM::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
    ASSERT_TRUE(in_z == z);
}

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromXYZ)
{
    CGM::Vector<3,int> x {1, 2, 3};
    CGM::Vector<3,int> y {4, 5, 6};
    CGM::Vector<3,int> z {7, 8, 9};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#else
    CGM::Matrix<3,3,int> expect
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z,
    };
#endif

    auto result = CGM::orientationMatrix(x, y, z);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromAxesStruct)
{
    CGM::Vector<3,int> x {1, 2, 3};
    CGM::Vector<3,int> y {4, 5, 6};
    CGM::Vector<3,int> z {7, 8, 9};

    auto axes = CGM::orientationAxes(x,y,z);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#else
    CGM::Matrix<3,3,int> expect
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z,
    };
#endif

    auto result = CGM::orientationMatrix(axes);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromQuaternion)
{
    CGM::Vector<3,double> x {0.559270,0.302442,-0.771846};
    CGM::Vector<3,double> y {-0.313298,0.939132,0.140980};
    CGM::Vector<3,double> z {0.767503,0.162971,0.619983};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,double> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#else
    CGM::Matrix<3,3,double> expect
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z,
    };
#endif

    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto result = CGM::orientationMatrix(quat);

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromMatrix4x4)
{
    CGM::Vector<3,int> x {1, 2, 3};
    CGM::Vector<3,int> y {4, 5, 6};
    CGM::Vector<3,int> z {7, 8, 9};

    CGM::Matrix<4,4,int> mat
    {
        x.x, y.x, z.x, 0,
        x.y, y.y, z.y, 0,
        x.z, y.z, z.z, 0,
        0, 0, 0, 1
    };

    CGM::Matrix<3,3,int> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };

    auto result = CGM::orientationMatrix(mat);

    ASSERT_TRUE(result == expect);
}

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromXYZ)
{
    CGM::Vector<3,double> x {0.559270,0.302442,-0.771846};
    CGM::Vector<3,double> y {-0.313298,0.939132,0.140980};
    CGM::Vector<3,double> z {0.767503,0.162971,0.619983};

    auto expect = CGM::Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};
    auto result = CGM::orientationQuaternion(x,y,z);

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromAxes)
{
    CGM::Axes<double> axes
    {
        CGM::Vector<3,double> {0.559270,0.302442,-0.771846},
        CGM::Vector<3,double> {-0.313298,0.939132,0.140980},
        CGM::Vector<3,double> {0.767503,0.162971,0.619983}
    };

    auto result = CGM::orientationQuaternion(axes);
    auto expect = CGM::Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromMatrix3x3)
{
    CGM::Vector<3,double> x {0.559270,0.302442,-0.771846};
    CGM::Vector<3,double> y {-0.313298,0.939132,0.140980};
    CGM::Vector<3,double> z {0.767503,0.162971,0.619983};

    CGM::Matrix<3,3,double> matrix {};
    CGM::setX(matrix, x);
    CGM::setY(matrix, y);
    CGM::setZ(matrix, z);

    auto result = CGM::orientationQuaternion(matrix);
    auto expect = CGM::Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromMatrix4x4)
{
    CGM::Vector<3,double> x {0.559270,0.302442,-0.771846};
    CGM::Vector<3,double> y {-0.313298,0.939132,0.140980};
    CGM::Vector<3,double> z {0.767503,0.162971,0.619983};

    CGM::Matrix<4,4,double> matrix {};
    CGM::setX(matrix, x);
    CGM::setY(matrix, y);
    CGM::setZ(matrix, z);

    auto result = CGM::orientationQuaternion(matrix);
    auto expect = CGM::Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}