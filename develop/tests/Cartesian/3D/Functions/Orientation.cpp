

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Common.hpp>
#include <CGM/detail/Core/Operators/Vector.hpp>
#include <CGM/detail/Core/Operators/Matrix.hpp>
#include <CGM/detail/Core/Functions/Vector.hpp>
#include <CGM/detail/Core/Functions/Matrix.hpp>
#include <CGM/detail/Cartesian/3D/Functions/Quaternion.hpp>
#include <CGM/detail/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/detail/Cartesian/3D/Functions/Orientation.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationAxes, FromXYZ)
{
    Vector<3,int> x {1, 2, 3};
    Vector<3,int> y {4, 5, 6};
    Vector<3,int> z {7, 8, 9};

    auto axes = CGM_XYZ::orientationAxes(x, y, z);

    ASSERT_TRUE(CGM_XYZ::x(axes) == x);
    ASSERT_TRUE(CGM_XYZ::y(axes) == y);
    ASSERT_TRUE(CGM_XYZ::z(axes) == z);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromMatrix3x3)
{
    Vector<3,int> in_x {1, 2, 3};
    Vector<3,int> in_y {4, 5, 6};
    Vector<3,int> in_z {7, 8, 9};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> mat
    {
        in_x.x, in_x.y, in_x.z,
        in_y.x, in_y.y, in_y.z,
        in_z.x, in_z.y, in_z.z,
    };
#else
    Matrix<3,3,int> mat
    {
        in_x.x, in_y.x, in_z.x,
        in_x.y, in_y.y, in_z.y,
        in_x.z, in_y.z, in_z.z
    };
#endif

    auto [x, y, z] = CGM_XYZ::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
    ASSERT_TRUE(in_z == z);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromQuaternion)
{
    Vector<3,double> expec_x {0.559270,0.302442,-0.771846};
    Vector<3,double> expec_y {-0.313298,0.939132,0.140980};
    Vector<3,double> expec_z {0.767503,0.162971,0.619983};

    Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};
    auto [x, y, z] = CGM_XYZ::orientationAxes(quat);

    ASSERT_TRUE(CGM::eq(expec_x, x, 0.00001));
    ASSERT_TRUE(CGM::eq(expec_y, y, 0.00001));
    ASSERT_TRUE(CGM::eq(expec_z, z, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromMatrix4x4)
{
    Vector<3,int> in_x {1, 2, 3};
    Vector<3,int> in_y {4, 5, 6};
    Vector<3,int> in_z {7, 8, 9};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<4,4,int> mat
    {
        in_x.x, in_x.y, in_x.z, 0,
        in_y.x, in_y.y, in_y.z, 0,
        in_z.x, in_z.y, in_z.z, 0,
        0, 0, 0, 1
    };
#else
    Matrix<4,4,int> mat
    {
        in_x.x, in_y.x, in_z.x, 0,
        in_x.y, in_y.y, in_z.y, 0,
        in_x.z, in_y.z, in_z.z, 0,
        0, 0, 0, 1
    };
#endif

    auto [x, y, z] = CGM_XYZ::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
    ASSERT_TRUE(in_z == z);
}

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromXYZ)
{
    Vector<3,int> x {1, 2, 3};
    Vector<3,int> y {4, 5, 6};
    Vector<3,int> z {7, 8, 9};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> expect
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z,
    };
#else
    Matrix<3,3,int> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#endif

    auto result = CGM_XYZ::orientationMatrix(x, y, z);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromAxesStruct)
{
    Vector<3,int> x {1, 2, 3};
    Vector<3,int> y {4, 5, 6};
    Vector<3,int> z {7, 8, 9};

    auto axes = CGM_XYZ::orientationAxes(x,y,z);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> expect
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z,
    };
#else
    Matrix<3,3,int> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#endif

    auto result = CGM_XYZ::orientationMatrix(axes);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromQuaternion)
{
    Vector<3,double> x {0.559270,0.302442,-0.771846};
    Vector<3,double> y {-0.313298,0.939132,0.140980};
    Vector<3,double> z {0.767503,0.162971,0.619983};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,double> expect
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z,
    };
#else
    Matrix<3,3,double> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#endif

    Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto result = CGM_XYZ::orientationMatrix(quat);

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromMatrix4x4)
{
    Vector<3,int> x {1, 2, 3};
    Vector<3,int> y {4, 5, 6};
    Vector<3,int> z {7, 8, 9};

    Matrix<4,4,int> mat
    {
        x.x, y.x, z.x, 0,
        x.y, y.y, z.y, 0,
        x.z, y.z, z.z, 0,
        0, 0, 0, 1
    };

    Matrix<3,3,int> expect
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };

    auto result = CGM_XYZ::orientationMatrix(mat);

    ASSERT_TRUE(result == expect);
}

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromXYZ)
{
    Vector<3,double> x {0.559270,0.302442,-0.771846};
    Vector<3,double> y {-0.313298,0.939132,0.140980};
    Vector<3,double> z {0.767503,0.162971,0.619983};

    auto expect = Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};
    auto result = CGM_XYZ::orientationQuaternion(x,y,z);

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromAxes)
{
    CGM_XYZ::Axes<double> axes
    {
        Vector<3,double> {0.559270,0.302442,-0.771846},
        Vector<3,double> {-0.313298,0.939132,0.140980},
        Vector<3,double> {0.767503,0.162971,0.619983}
    };

    auto result = CGM_XYZ::orientationQuaternion(axes);
    auto expect = Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromMatrix3x3)
{
    Vector<3,double> x {0.559270,0.302442,-0.771846};
    Vector<3,double> y {-0.313298,0.939132,0.140980};
    Vector<3,double> z {0.767503,0.162971,0.619983};

    Matrix<3,3,double> matrix {};
    CGM_XYZ::setX(matrix, x);
    CGM_XYZ::setY(matrix, y);
    CGM_XYZ::setZ(matrix, z);

    auto result = CGM_XYZ::orientationQuaternion(matrix);
    auto expect = Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromMatrix4x4)
{
    Vector<3,double> x {0.559270,0.302442,-0.771846};
    Vector<3,double> y {-0.313298,0.939132,0.140980};
    Vector<3,double> z {0.767503,0.162971,0.619983};

    Matrix<4,4,double> matrix {};
    CGM_XYZ::setX(matrix, x);
    CGM_XYZ::setY(matrix, y);
    CGM_XYZ::setZ(matrix, z);

    auto result = CGM_XYZ::orientationQuaternion(matrix);
    auto expect = Quaternion<double>{0.006227,-0.435855,-0.174342, 0.882948};

    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}