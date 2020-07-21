

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


using namespace std;
using namespace MATH3D_NAMESPACE;

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, GetX)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::x(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::x(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::x(quat);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec3 {2,4,5};
    Vector<3,double> expec4 {2,4,5};
#else
    Vector<3,double> expec3 {2,3,0};
    Vector<3,double> expec4 {2,3,0};
#endif

#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> expecQ {0.910683, -0.244016, 0.333334};
#else
    Vector<3,double> expecQ {0.910683, 0.333332, -0.244017};
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetY)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::y(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::y(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::y(quat);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec3 {3,6,7};
    Vector<3,double> expec4 {3,6,7};
#else
    Vector<3,double> expec3 {4,6,9};
    Vector<3,double> expec4 {4,6,9};
#endif

#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> expecQ {0.333332, 0.910683, -0.244016};
#else
    Vector<3,double> expecQ {-0.244017, 0.910683, 0.333334};
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetZ)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::z(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::z(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::z(quat);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec3 {0,9,8};
    Vector<3,double> expec4 {0,9,8};
#else
    Vector<3,double> expec3 {5,7,8};
    Vector<3,double> expec4 {5,7,8};
#endif

#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Vector<3,double> expecQ {-0.244017, 0.333332, 0.910683};
#else
    Vector<3,double> expecQ {0.333334, -0.244017, 0.910683};
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetXYZ)
{
    Vector<3,int> x {2,4,5};
    Vector<3,int> y {3,6,7};
    Vector<3,int> z {0,9,8};

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> expec3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,int> expec4
    {
        2, 4, 5, 0,
        3, 6, 7, 0,
        0, 9, 8, 0,
        0, 0, 0, 0
    };
#else
    Matrix<3,3,int> expec3
    {
        2, 3, 0,
        4, 6, 9,
        5, 7, 8
    };

    Matrix<4,4,int> expec4
    {
        2, 3, 0, 0,
        4, 6, 9, 0,
        5, 7, 8, 0,
        0, 0, 0, 0
    };
#endif

    Matrix<3,3,int> mat3(0);
    MATH3D_XYZ_NAMESPACE::setX(mat3, x);
    MATH3D_XYZ_NAMESPACE::setY(mat3, y);
    MATH3D_XYZ_NAMESPACE::setZ(mat3, z);

    Matrix<4,4,int> mat4(0);
    MATH3D_XYZ_NAMESPACE::setX(mat4, x);
    MATH3D_XYZ_NAMESPACE::setY(mat4, y);
    MATH3D_XYZ_NAMESPACE::setZ(mat4, z);

    ASSERT_TRUE(mat3 == expec3);
    ASSERT_TRUE(mat4 == expec4);
}

/* ####################################################################################### */
/* Up, Right, Forward axes */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, GetUp)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::up(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::up(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::up(quat);

#ifdef MATH3D_CARTESIAN_UP_X
    auto expec3 = MATH3D_XYZ_NAMESPACE::x(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::x(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::x(quat);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    auto expec3 = MATH3D_XYZ_NAMESPACE::y(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::y(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::y(quat);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    auto expec3 = MATH3D_XYZ_NAMESPACE::z(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::z(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetRight)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::right(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::right(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::right(quat);

#ifdef MATH3D_CARTESIAN_RIGHT_X
    auto expec3 = MATH3D_XYZ_NAMESPACE::x(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::x(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::x(quat);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    auto expec3 = MATH3D_XYZ_NAMESPACE::y(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::y(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::y(quat);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    auto expec3 = MATH3D_XYZ_NAMESPACE::z(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::z(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetForward)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::forward(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::forward(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::forward(quat);

#ifdef MATH3D_CARTESIAN_FORWARD_X
    auto expec3 = MATH3D_XYZ_NAMESPACE::x(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::x(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::x(quat);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    auto expec3 = MATH3D_XYZ_NAMESPACE::y(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::y(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::y(quat);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    auto expec3 = MATH3D_XYZ_NAMESPACE::z(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::z(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetDown)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::down(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::down(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::down(quat);

    auto expec3 = -MATH3D_XYZ_NAMESPACE::up(mat3);
    auto expec4 = -MATH3D_XYZ_NAMESPACE::up(mat4);
    auto expecQ = -MATH3D_XYZ_NAMESPACE::up(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetLeft)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::left(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::left(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::left(quat);

    auto expec3 = -MATH3D_XYZ_NAMESPACE::right(mat3);
    auto expec4 = -MATH3D_XYZ_NAMESPACE::right(mat4);
    auto expecQ = -MATH3D_XYZ_NAMESPACE::right(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetBackward)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.149429, 0.149429, 0.149429, 0.965926};

    auto value3 = MATH3D_XYZ_NAMESPACE::backward(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::backward(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::backward(quat);

    auto expec3 = -MATH3D_XYZ_NAMESPACE::forward(mat3);
    auto expec4 = -MATH3D_XYZ_NAMESPACE::forward(mat4);
    auto expecQ = -MATH3D_XYZ_NAMESPACE::forward(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetUpRightForward)
{
    Vector<3,int> u {4,6,9};
    Vector<3,int> r {2,3,0};
    Vector<3,int> f {5,7,8};

#ifdef MATH3D_CARTESIAN_UP_X
    auto x = u;
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    auto y = u;
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    auto z = u;
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_RIGHT_X
    auto x = r;
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    auto y = r;
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    auto z = r;
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_FORWARD_X
    auto x = f;
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    auto y = f;
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    auto z = f;
#endif

    Matrix<3,3,int> mat3 {};
    MATH3D_XYZ_NAMESPACE::setUp(mat3, u);
    MATH3D_XYZ_NAMESPACE::setRight(mat3, r);
    MATH3D_XYZ_NAMESPACE::setForward(mat3, f);

    Matrix<4,4,int> mat4 {};
    MATH3D_XYZ_NAMESPACE::setUp(mat4, u);
    MATH3D_XYZ_NAMESPACE::setRight(mat4, r);
    MATH3D_XYZ_NAMESPACE::setForward(mat4, f);

    Vector<3,int> X3 = MATH3D_XYZ_NAMESPACE::x(mat3);
    Vector<3,int> Y3 = MATH3D_XYZ_NAMESPACE::y(mat3);
    Vector<3,int> Z3 = MATH3D_XYZ_NAMESPACE::z(mat3);

    Vector<3,int> X4 = MATH3D_XYZ_NAMESPACE::x(mat4);
    Vector<3,int> Y4 = MATH3D_XYZ_NAMESPACE::y(mat4);
    Vector<3,int> Z4 = MATH3D_XYZ_NAMESPACE::z(mat4);

    ASSERT_TRUE(X3 == x && X4 == x);
    ASSERT_TRUE(Y3 == y && Y4 == y);
    ASSERT_TRUE(Z3 == z && Z4 == z);
}

/* ####################################################################################### */
/* Position */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, GetPosition)
{
    Matrix<4,4,int> mat
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    auto value = MATH3D_XYZ_NAMESPACE::position(mat);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    auto expec = Vector<3,int>{1,3,2};
#else
    auto expec = Vector<3,int>{4,7,1};
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetPosition)
{
    Matrix<4,4,int> mat
    {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    MATH3D_XYZ_NAMESPACE::setPosition(mat, {2,3,4});

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<4,4,int> expec
    {
        1, 0, 0, 2,
        0, 1, 0, 3,
        0, 0, 1, 4,
        0, 0, 0, 1
    };
#else
    Matrix<4,4,int> expec
    {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        2, 3, 4, 1
    };
#endif

    ASSERT_TRUE(mat == expec);
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, GetOrientation)
{
    Matrix<4,4,int> mat
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    Matrix<3,3,int> expec
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    auto res = MATH3D_XYZ_NAMESPACE::orientation(mat);

    ASSERT_TRUE(res == expec);
}

/* --------------------------------------------------------------------------------------- */
#include <Math3D/IO.hpp>
TEST(Cartesian_3D_Functions_Utils, SetOrientation)
{
    {
        Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        Matrix<3,3,int> orient
        {
            2, 4, 5,
            3, 6, 7,
            0, 9, 8
        };

        Matrix<4,4,int> expec
        {
            2, 4, 5, 0,
            3, 6, 7, 0,
            0, 9, 8, 0,
            0, 0, 0, 1
        };

        MATH3D_XYZ_NAMESPACE::setOrientation(mat, orient);

        ASSERT_TRUE(mat == expec);
    }

    {
        Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        Vector<3,int> x {1,2,3};
        Vector<3,int> y {4,5,6};
        Vector<3,int> z {7,8,9};

        MATH3D_XYZ_NAMESPACE::setOrientation(mat, x, y, z);

        Matrix<4,4,int> expec
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        MATH3D_XYZ_NAMESPACE::setX(expec, x);
        MATH3D_XYZ_NAMESPACE::setY(expec, y);
        MATH3D_XYZ_NAMESPACE::setZ(expec, z);

        ASSERT_TRUE(mat == expec);
    }

    {
        Matrix<4,4,double> mat
        {
            1.0, 0, 0, 0,
            0, 1.0, 0, 0,
            0, 0, 1.0, 0,
            0, 0, 0, 1.0
        };

    #ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
        Vector<3,double> expec_x {0.910683, -0.244016, 0.333334};
        Vector<3,double> expec_y {0.333332, 0.910683, -0.244016};
        Vector<3,double> expec_z {-0.244017, 0.333332, 0.910683};
    #else
        Vector<3,double> expec_x {0.910683, 0.333332, -0.244017};
        Vector<3,double> expec_y {-0.244017, 0.910683, 0.333334};
        Vector<3,double> expec_z {0.333334, -0.244017, 0.910683};
    #endif

        Quaternion<double> orientation {0.149429, 0.149429, 0.149429, 0.965926};

        MATH3D_XYZ_NAMESPACE::setOrientation(mat, orientation);

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::x(mat), expec_x, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::y(mat), expec_y, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::z(mat), expec_z, 0.0001));
    }

    {
        Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        Matrix<4,4,int> orient
        {
            2, 4, 5, 0,
            3, 6, 7, 0,
            0, 9, 8, 0,
            0, 0, 0, 1
        };

        Matrix<4,4,int> expec
        {
            2, 4, 5, 0,
            3, 6, 7, 0,
            0, 9, 8, 0,
            0, 0, 0, 1
        };

        MATH3D_XYZ_NAMESPACE::setOrientation(mat, orient);

        ASSERT_TRUE(mat == expec);
    }
}