

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Common.hpp>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Cartesian/3D/Functions/Quaternion.hpp>
#include <CGM/Cartesian/3D/Functions/Utils.hpp>


using namespace std;
using namespace CGM;

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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::x(mat3);
    auto value4 = CGM_XYZ::x(mat4);
    auto valueQ = CGM_XYZ::x(quat);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Vector<3,double> expec3 {2,3,0};
    Vector<3,double> expec4 {2,3,0};

#else
    Vector<3,double> expec3 {2,4,5};
    Vector<3,double> expec4 {2,4,5};
#endif

    Vector<3,double> expecQ {0.559270,0.302442,-0.771846};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::y(mat3);
    auto value4 = CGM_XYZ::y(mat4);
    auto valueQ = CGM_XYZ::y(quat);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Vector<3,double> expec3 {4,6,9};
    Vector<3,double> expec4 {4,6,9};
#else
    Vector<3,double> expec3 {3,6,7};
    Vector<3,double> expec4 {3,6,7};
#endif

    Vector<3,double> expecQ {-0.313298,0.939132,0.140980};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::z(mat3);
    auto value4 = CGM_XYZ::z(mat4);
    auto valueQ = CGM_XYZ::z(quat);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Vector<3,double> expec3 {5,7,8};
    Vector<3,double> expec4 {5,7,8};
#else
    Vector<3,double> expec3 {0,9,8};
    Vector<3,double> expec4 {0,9,8};
#endif

    Vector<3,double> expecQ {0.767503,0.162971,0.619983};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetXYZ)
{
    Vector<3,int> x {2,4,5};
    Vector<3,int> y {3,6,7};
    Vector<3,int> z {0,9,8};

#ifdef CGM_CFG_MATRIX_POSTMULT
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
#else
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
#endif

    Matrix<3,3,int> mat3(0);
    CGM_XYZ::setX(mat3, x);
    CGM_XYZ::setY(mat3, y);
    CGM_XYZ::setZ(mat3, z);

    Matrix<4,4,int> mat4(0);
    CGM_XYZ::setX(mat4, x);
    CGM_XYZ::setY(mat4, y);
    CGM_XYZ::setZ(mat4, z);

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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::up(mat3);
    auto value4 = CGM_XYZ::up(mat4);
    auto valueQ = CGM_XYZ::up(quat);

#ifdef CGM_CFG_UP_IS_X
    auto expec3 = CGM_XYZ::x(mat3);
    auto expec4 = CGM_XYZ::x(mat4);
    auto expecQ = CGM_XYZ::x(quat);
#endif
#ifdef CGM_CFG_UP_IS_Y
    auto expec3 = CGM_XYZ::y(mat3);
    auto expec4 = CGM_XYZ::y(mat4);
    auto expecQ = CGM_XYZ::y(quat);
#endif
#ifdef CGM_CFG_UP_IS_Z
    auto expec3 = CGM_XYZ::z(mat3);
    auto expec4 = CGM_XYZ::z(mat4);
    auto expecQ = CGM_XYZ::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::right(mat3);
    auto value4 = CGM_XYZ::right(mat4);
    auto valueQ = CGM_XYZ::right(quat);

#ifdef CGM_CFG_RIGHT_IS_X
    auto expec3 = CGM_XYZ::x(mat3);
    auto expec4 = CGM_XYZ::x(mat4);
    auto expecQ = CGM_XYZ::x(quat);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    auto expec3 = CGM_XYZ::y(mat3);
    auto expec4 = CGM_XYZ::y(mat4);
    auto expecQ = CGM_XYZ::y(quat);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    auto expec3 = CGM_XYZ::z(mat3);
    auto expec4 = CGM_XYZ::z(mat4);
    auto expecQ = CGM_XYZ::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::forward(mat3);
    auto value4 = CGM_XYZ::forward(mat4);
    auto valueQ = CGM_XYZ::forward(quat);

#ifdef CGM_CFG_FORWARD_IS_X
    auto expec3 = CGM_XYZ::x(mat3);
    auto expec4 = CGM_XYZ::x(mat4);
    auto expecQ = CGM_XYZ::x(quat);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    auto expec3 = CGM_XYZ::y(mat3);
    auto expec4 = CGM_XYZ::y(mat4);
    auto expecQ = CGM_XYZ::y(quat);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    auto expec3 = CGM_XYZ::z(mat3);
    auto expec4 = CGM_XYZ::z(mat4);
    auto expecQ = CGM_XYZ::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::down(mat3);
    auto value4 = CGM_XYZ::down(mat4);
    auto valueQ = CGM_XYZ::down(quat);

    auto expec3 = -CGM_XYZ::up(mat3);
    auto expec4 = -CGM_XYZ::up(mat4);
    auto expecQ = -CGM_XYZ::up(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::left(mat3);
    auto value4 = CGM_XYZ::left(mat4);
    auto valueQ = CGM_XYZ::left(quat);

    auto expec3 = -CGM_XYZ::right(mat3);
    auto expec4 = -CGM_XYZ::right(mat4);
    auto expecQ = -CGM_XYZ::right(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
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
    CGM_XYZ::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM_XYZ::backward(mat3);
    auto value4 = CGM_XYZ::backward(mat4);
    auto valueQ = CGM_XYZ::backward(quat);

    auto expec3 = -CGM_XYZ::forward(mat3);
    auto expec4 = -CGM_XYZ::forward(mat4);
    auto expecQ = -CGM_XYZ::forward(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetUpRightForward)
{
    Vector<3,int> u {4,6,9};
    Vector<3,int> r {2,3,0};
    Vector<3,int> f {5,7,8};

#ifdef CGM_CFG_UP_IS_X
    auto x = u;
#endif
#ifdef CGM_CFG_UP_IS_Y
    auto y = u;
#endif
#ifdef CGM_CFG_UP_IS_Z
    auto z = u;
#endif

// ------------------------------

#ifdef CGM_CFG_RIGHT_IS_X
    auto x = r;
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    auto y = r;
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    auto z = r;
#endif

// ------------------------------

#ifdef CGM_CFG_FORWARD_IS_X
    auto x = f;
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    auto y = f;
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    auto z = f;
#endif

    Matrix<3,3,int> mat3 {};
    CGM_XYZ::setUp(mat3, u);
    CGM_XYZ::setRight(mat3, r);
    CGM_XYZ::setForward(mat3, f);

    Matrix<4,4,int> mat4 {};
    CGM_XYZ::setUp(mat4, u);
    CGM_XYZ::setRight(mat4, r);
    CGM_XYZ::setForward(mat4, f);

    Vector<3,int> X3 = CGM_XYZ::x(mat3);
    Vector<3,int> Y3 = CGM_XYZ::y(mat3);
    Vector<3,int> Z3 = CGM_XYZ::z(mat3);

    Vector<3,int> X4 = CGM_XYZ::x(mat4);
    Vector<3,int> Y4 = CGM_XYZ::y(mat4);
    Vector<3,int> Z4 = CGM_XYZ::z(mat4);

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

    auto value = CGM_XYZ::position(mat);
#ifdef CGM_CFG_MATRIX_POSTMULT
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

    CGM_XYZ::setPosition(mat, {2,3,4});

#ifdef CGM_CFG_MATRIX_POSTMULT
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

        CGM_XYZ::setOrientation(mat, orient);

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

        CGM_XYZ::setOrientation(mat, x, y, z);

        Matrix<4,4,int> expec
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        CGM_XYZ::setX(expec, x);
        CGM_XYZ::setY(expec, y);
        CGM_XYZ::setZ(expec, z);

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

        Vector<3,double> expec_x {0.559270,0.302442,-0.771846};
        Vector<3,double> expec_y {-0.313298,0.939132,0.140980};
        Vector<3,double> expec_z {0.767503,0.162971,0.619983};

        CGM_XYZ::Quaternion<double> orientation {-0.006227,0.435855,0.174342,0.882948};

        CGM_XYZ::setOrientation(mat, orientation);

        ASSERT_TRUE(CGM::eq(CGM_XYZ::x(mat), expec_x, 0.0001));
        ASSERT_TRUE(CGM::eq(CGM_XYZ::y(mat), expec_y, 0.0001));
        ASSERT_TRUE(CGM::eq(CGM_XYZ::z(mat), expec_z, 0.0001));
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

        CGM_XYZ::setOrientation(mat, orient);

        ASSERT_TRUE(mat == expec);
    }
}

/* ####################################################################################### */
/* Space matrix */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, FromXYZP)
{
    Vector<3,int> X {2,1,3};
    Vector<3,int> Y {4,3,6};
    Vector<3,int> Z {7,9,2};
    Vector<3,int> P {1,2,3};

    auto basis = CGM_XYZ::spaceMatrix(X,Y,Z,P);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Matrix<4,4,int> expec
    {
        2,4,7,1,
        1,3,9,2,
        3,6,2,3,
        0,0,0,1
    };
#else
    Matrix<4,4,int> expec
    {
        2,1,3,0,
        4,3,6,0,
        7,9,2,0,
        1,2,3,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, FromMatrix3AndPosition)
{
    Vector<3,int> position {5,1,8};
    Matrix<3,3,int> orientation
    {
        2,1,3,
        4,3,6,
        7,9,2
    };

    auto basis = CGM_XYZ::spaceMatrix(orientation, position);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Matrix<4,4,int> expec
    {
        2,1,3,5,
        4,3,6,1,
        7,9,2,8,
        0,0,0,1
    };
#else
    Matrix<4,4,int> expec
    {
        2,1,3,0,
        4,3,6,0,
        7,9,2,0,
        5,1,8,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, FromQuaternionAndPosition)
{
    const auto q = CGM_XYZ::Quaternion<double>{-0.006227,0.435855,0.174342,0.882948};
    const auto p = Vector<3,double> {0.7, 1.3, 4.0};

    auto result = CGM_XYZ::spaceMatrix(q,p);

    Vector<3,double> ex {0.559270,0.302442,-0.771846};
    Vector<3,double> ey {-0.313298,0.939132,0.140980};
    Vector<3,double> ez {0.767503,0.162971,0.619983};

#ifdef CGM_CFG_MATRIX_POSTMULT
    Matrix<4,4,double> expec
    {
        ex.x, ey.x, ez.x, p.x,
        ex.y, ey.y, ez.y, p.y,
        ex.z, ey.z, ez.z, p.z,
         0.0,  0.0,  0.0, 1.0
    };
#else
    Matrix<4,4,double> expec
    {
        ex.x, ex.y, ex.z, 0.0,
        ey.x, ey.y, ey.z, 0.0,
        ez.x, ez.y, ez.z, 0.0,
         p.x,  p.y,  p.z, 1.0
    };
#endif

    ASSERT_TRUE(CGM::eq(result, expec, 0.0001));
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, MultiplyMatrix4Vector3)
{
    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,4,1,
            2,1,3,2,
            5,1,1,3,
            0,0,0,1
        };

        auto res = CGM_XYZ::multiply<EVectorRepresentation::Point>(mat, vec);
        Vector<3,int> exp {29,21,20};
        ASSERT_TRUE(res == exp);
    }

    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,4,1,
            2,1,3,2,
            5,1,1,3,
            0,0,0,1
        };

        auto res = CGM_XYZ::multiply<EVectorRepresentation::Direction>(mat, vec);
        Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }

}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, MultiplyVector3Matrix4)
{
    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,5,0,
            2,1,1,0,
            4,3,1,0,
            1,2,3,1
        };

        auto res = CGM_XYZ::multiply<EVectorRepresentation::Point>(vec, mat);
        Vector<3,int> exp {29,21,20};
        ASSERT_TRUE(res == exp);
    }

    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,5,0,
            2,1,1,0,
            4,3,1,0,
            1,2,3,1
        };

        auto res = CGM_XYZ::multiply<EVectorRepresentation::Direction>(vec, mat);
        Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, MultiplyMatrix3Matrix4)
{
    {
        Matrix<3,3,int> expect
        {
             58,  37,   39,
             99,  62,   48,
            121,  66,   76
        };

        Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM_XYZ::multiply<3>(mat3, mat4);

        ASSERT_TRUE(result == expect);
    }
    {
        Matrix<4,4,int> expect
        {
             58,  37,   39,   78,
             99,  62,   48,  125,
            121,  66,   76,  157,
              2,   4,    7,    3
        };

        Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM_XYZ::multiply<4>(mat3, mat4);

        ASSERT_TRUE(result == expect);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, MultiplyVector4Matrix3)
{
    {
        Matrix<3,3,int> expect
        {
            60,  52,  47,
            62,  56,  78,
            66,  66,  80
        };

        Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM_XYZ::multiply<3>(mat4, mat3);

        ASSERT_TRUE(result == expect);
    }
    {
        Matrix<4,4,int> expect
        {
            60,  52,  47,  5,
            62,  56,  78,  9,
            66,  66,  80,  8,
            83,  84,  73,  3
        };

        Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM_XYZ::multiply<4>(mat4, mat3);

        ASSERT_TRUE(result == expect);
    }
}
