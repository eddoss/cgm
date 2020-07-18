

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>
#include <Math3D/Cartesian/3D/Functions/Orientation.hpp>

using namespace std;
using namespace MATH3D_NAMESPACE;

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationAxes, FromXYZ)
{
    Vector<3,int> x {1, 2, 3};
    Vector<3,int> y {4, 5, 6};
    Vector<3,int> z {7, 8, 9};

    auto axes = MATH3D_XYZ_NAMESPACE::orientationAxes(x, y, z);

    ASSERT_TRUE(MATH3D_XYZ_NAMESPACE::x(axes) == x);
    ASSERT_TRUE(MATH3D_XYZ_NAMESPACE::y(axes) == y);
    ASSERT_TRUE(MATH3D_XYZ_NAMESPACE::z(axes) == z);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromMatrix3x3)
{
    Vector<3,int> in_x {1, 2, 3};
    Vector<3,int> in_y {4, 5, 6};
    Vector<3,int> in_z {7, 8, 9};

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto [x, y, z] = MATH3D_XYZ_NAMESPACE::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
    ASSERT_TRUE(in_z == z);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromQuaternion)
{
#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> expec_x {0.915889, 0.370336, 0.154913};
    Vector<3,double> expec_y {0.310963, -0.898559, 0.309628};
    Vector<3,double> expec_z {0.253867, -0.235412, -0.938141};
#else
    Vector<3,double> expec_x {0.915889, 0.310963, 0.253867};
    Vector<3,double> expec_y {0.370336, -0.898559, -0.235412};
    Vector<3,double> expec_z {0.154913, 0.309628, -0.938141};
#endif

    Quaternion<double> quat {-0.14068, 0.96858, 0.17585, 0.10551};
    auto [x, y, z] = MATH3D_XYZ_NAMESPACE::orientationAxes(quat);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec_x, x, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec_y, y, 0.00001));
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec_z, z, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationAxes, FromMatrix4x4)
{
    Vector<3,int> in_x {1, 2, 3};
    Vector<3,int> in_y {4, 5, 6};
    Vector<3,int> in_z {7, 8, 9};

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto [x, y, z] = MATH3D_XYZ_NAMESPACE::orientationAxes(mat);

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

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto result = MATH3D_XYZ_NAMESPACE::orientationMatrix(x, y, z);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromAxesTuple)
{
    Vector<3,int> x {1, 2, 3};
    Vector<3,int> y {4, 5, 6};
    Vector<3,int> z {7, 8, 9};

    auto axes = MATH3D_XYZ_NAMESPACE::orientationAxes(x,y,z);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto result = MATH3D_XYZ_NAMESPACE::orientationMatrix(axes);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationMatrix, FromQuaternion)
{
#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> x {0.915889, 0.370336, 0.154913};
    Vector<3,double> y {0.310963, -0.898559, 0.309628};
    Vector<3,double> z {0.253867, -0.235412, -0.938141};
#else
    Vector<3,double> x {0.915889, 0.310963, 0.253867};
    Vector<3,double> y {0.370336, -0.898559, -0.235412};
    Vector<3,double> z {0.154913, 0.309628, -0.938141};
#endif

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    Quaternion<double> quat {-0.14068, 0.96858, 0.17585, 0.10551};

    auto result = MATH3D_XYZ_NAMESPACE::orientationMatrix(quat);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.00001));
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

    auto result = MATH3D_XYZ_NAMESPACE::orientationMatrix(mat);

    ASSERT_TRUE(result == expect);
}

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromXYZ)
{
#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> x {0.915889, 0.370336, 0.154913};
    Vector<3,double> y {0.310963, -0.898559, 0.309628};
    Vector<3,double> z {0.253867, -0.235412, -0.938141};
#else
    Vector<3,double> x {0.915889, 0.310963, 0.253867};
    Vector<3,double> y {0.370336, -0.898559, -0.235412};
    Vector<3,double> z {0.154913, 0.309628, -0.938141};
#endif

    auto expect = Quaternion<double>{-0.14068, 0.96858, 0.17585, 0.10551};
    auto result = MATH3D_XYZ_NAMESPACE::orientationQuaternion(x,y,z);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromAxes)
{
#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    MATH3D_XYZ_NAMESPACE::AxesTuple<double> axes
    {
        Vector<3,double> {0.915889, 0.370336, 0.154913},
        Vector<3,double> {0.310963, -0.898559, 0.309628},
        Vector<3,double> {0.253867, -0.235412, -0.938141}
    };
#else
    MATH3D_XYZ_NAMESPACE::AxesTuple<double> axes
    {
        Vector<3,double> {0.915889, 0.310963, 0.253867},
        Vector<3,double> {0.370336, -0.898559, -0.235412},
        Vector<3,double> {0.154913, 0.309628, -0.938141}
    };
#endif

    auto result = MATH3D_XYZ_NAMESPACE::orientationQuaternion(axes);
    auto expect = Quaternion<double>{-0.14068, 0.96858, 0.17585, 0.10551};

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromMatrix3x3)
{
#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> x {0.915889, 0.370336, 0.154913};
    Vector<3,double> y {0.310963, -0.898559, 0.309628};
    Vector<3,double> z {0.253867, -0.235412, -0.938141};
#else
    Vector<3,double> x {0.915889, 0.310963, 0.253867};
    Vector<3,double> y {0.370336, -0.898559, -0.235412};
    Vector<3,double> z {0.154913, 0.309628, -0.938141};
#endif

    Matrix<3,3,double> matrix {};
    MATH3D_XYZ_NAMESPACE::setX(matrix, x);
    MATH3D_XYZ_NAMESPACE::setY(matrix, y);
    MATH3D_XYZ_NAMESPACE::setZ(matrix, z);

    auto result = MATH3D_XYZ_NAMESPACE::orientationQuaternion(matrix);
    auto expect = Quaternion<double>{-0.14068, 0.96858, 0.17585, 0.10551};

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_OrientationQuaternion, FromMatrix4x4)
{
#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> x {0.915889, 0.370336, 0.154913};
    Vector<3,double> y {0.310963, -0.898559, 0.309628};
    Vector<3,double> z {0.253867, -0.235412, -0.938141};
#else
    Vector<3,double> x {0.915889, 0.310963, 0.253867};
    Vector<3,double> y {0.370336, -0.898559, -0.235412};
    Vector<3,double> z {0.154913, 0.309628, -0.938141};
#endif

    Matrix<4,4,double> matrix {};
    MATH3D_XYZ_NAMESPACE::setX(matrix, x);
    MATH3D_XYZ_NAMESPACE::setY(matrix, y);
    MATH3D_XYZ_NAMESPACE::setZ(matrix, z);

    auto result = MATH3D_XYZ_NAMESPACE::orientationQuaternion(matrix);
    auto expect = Quaternion<double>{-0.14068, 0.96858, 0.17585, 0.10551};

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.00001));
}