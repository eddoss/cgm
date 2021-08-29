

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


using namespace std;

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, GetX)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::x(mat3);
    auto value4 = CGM::x(mat4);
    auto valueQ = CGM::x(quat);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Vector<3,double> expec3 {2,3,0};
    CGM::Vector<3,double> expec4 {2,3,0};

#else
    CGM::Vector<3,double> expec3 {2,4,5};
    CGM::Vector<3,double> expec4 {2,4,5};
#endif

    CGM::Vector<3,double> expecQ {0.559270,0.302442,-0.771846};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetY)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::y(mat3);
    auto value4 = CGM::y(mat4);
    auto valueQ = CGM::y(quat);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Vector<3,double> expec3 {4,6,9};
    CGM::Vector<3,double> expec4 {4,6,9};
#else
    CGM::Vector<3,double> expec3 {3,6,7};
    CGM::Vector<3,double> expec4 {3,6,7};
#endif

    CGM::Vector<3,double> expecQ {-0.313298,0.939132,0.140980};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetZ)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::z(mat3);
    auto value4 = CGM::z(mat4);
    auto valueQ = CGM::z(quat);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Vector<3,double> expec3 {5,7,8};
    CGM::Vector<3,double> expec4 {5,7,8};
#else
    CGM::Vector<3,double> expec3 {0,9,8};
    CGM::Vector<3,double> expec4 {0,9,8};
#endif

    CGM::Vector<3,double> expecQ {0.767503,0.162971,0.619983};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetXYZ)
{
    CGM::Vector<3,int> x {2,4,5};
    CGM::Vector<3,int> y {3,6,7};
    CGM::Vector<3,int> z {0,9,8};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> expec3
    {
        2, 3, 0,
        4, 6, 9,
        5, 7, 8
    };

    CGM::Matrix<4,4,int> expec4
    {
        2, 3, 0, 0,
        4, 6, 9, 0,
        5, 7, 8, 0,
        0, 0, 0, 0
    };
#else
    CGM::Matrix<3,3,int> expec3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,int> expec4
    {
        2, 4, 5, 0,
        3, 6, 7, 0,
        0, 9, 8, 0,
        0, 0, 0, 0
    };
#endif

    CGM::Matrix<3,3,int> mat3(0);
    CGM::setX(mat3, x);
    CGM::setY(mat3, y);
    CGM::setZ(mat3, z);

    CGM::Matrix<4,4,int> mat4(0);
    CGM::setX(mat4, x);
    CGM::setY(mat4, y);
    CGM::setZ(mat4, z);

    ASSERT_TRUE(mat3 == expec3);
    ASSERT_TRUE(mat4 == expec4);
}

/* ####################################################################################### */
/* Up, Right, Forward axes */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, GetUp)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::up(mat3);
    auto value4 = CGM::up(mat4);
    auto valueQ = CGM::up(quat);

#ifdef CGM_CFG_UP_IS_X
    auto expec3 = CGM::x(mat3);
    auto expec4 = CGM::x(mat4);
    auto expecQ = CGM::x(quat);
#endif
#ifdef CGM_CFG_UP_IS_Y
    auto expec3 = CGM::y(mat3);
    auto expec4 = CGM::y(mat4);
    auto expecQ = CGM::y(quat);
#endif
#ifdef CGM_CFG_UP_IS_Z
    auto expec3 = CGM::z(mat3);
    auto expec4 = CGM::z(mat4);
    auto expecQ = CGM::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetRight)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::right(mat3);
    auto value4 = CGM::right(mat4);
    auto valueQ = CGM::right(quat);

#ifdef CGM_CFG_RIGHT_IS_X
    auto expec3 = CGM::x(mat3);
    auto expec4 = CGM::x(mat4);
    auto expecQ = CGM::x(quat);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    auto expec3 = CGM::y(mat3);
    auto expec4 = CGM::y(mat4);
    auto expecQ = CGM::y(quat);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    auto expec3 = CGM::z(mat3);
    auto expec4 = CGM::z(mat4);
    auto expecQ = CGM::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetForward)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::forward(mat3);
    auto value4 = CGM::forward(mat4);
    auto valueQ = CGM::forward(quat);

#ifdef CGM_CFG_FORWARD_IS_X
    auto expec3 = CGM::x(mat3);
    auto expec4 = CGM::x(mat4);
    auto expecQ = CGM::x(quat);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    auto expec3 = CGM::y(mat3);
    auto expec4 = CGM::y(mat4);
    auto expecQ = CGM::y(quat);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    auto expec3 = CGM::z(mat3);
    auto expec4 = CGM::z(mat4);
    auto expecQ = CGM::z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetDown)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::down(mat3);
    auto value4 = CGM::down(mat4);
    auto valueQ = CGM::down(quat);

    auto expec3 = -CGM::up(mat3);
    auto expec4 = -CGM::up(mat4);
    auto expecQ = -CGM::up(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetLeft)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::left(mat3);
    auto value4 = CGM::left(mat4);
    auto valueQ = CGM::left(quat);

    auto expec3 = -CGM::right(mat3);
    auto expec4 = -CGM::right(mat4);
    auto expecQ = -CGM::right(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, GetBackward)
{
    CGM::Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    CGM::Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalizedSafe(1,1,1), angle = 30 (deg)
    CGM::Quaternion<double> quat {-0.006227,0.435855,0.174342,0.882948};

    auto value3 = CGM::backward(mat3);
    auto value4 = CGM::backward(mat4);
    auto valueQ = CGM::backward(quat);

    auto expec3 = -CGM::forward(mat3);
    auto expec4 = -CGM::forward(mat4);
    auto expecQ = -CGM::forward(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(CGM::eq(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetUpRightForward)
{
    CGM::Vector<3,int> u {4,6,9};
    CGM::Vector<3,int> r {2,3,0};
    CGM::Vector<3,int> f {5,7,8};

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

    CGM::Matrix<3,3,int> mat3 {};
    CGM::setUp(mat3, u);
    CGM::setRight(mat3, r);
    CGM::setForward(mat3, f);

    CGM::Matrix<4,4,int> mat4 {};
    CGM::setUp(mat4, u);
    CGM::setRight(mat4, r);
    CGM::setForward(mat4, f);

    CGM::Vector<3,int> X3 = CGM::x(mat3);
    CGM::Vector<3,int> Y3 = CGM::y(mat3);
    CGM::Vector<3,int> Z3 = CGM::z(mat3);

    CGM::Vector<3,int> X4 = CGM::x(mat4);
    CGM::Vector<3,int> Y4 = CGM::y(mat4);
    CGM::Vector<3,int> Z4 = CGM::z(mat4);

    ASSERT_TRUE(X3 == x && X4 == x);
    ASSERT_TRUE(Y3 == y && Y4 == y);
    ASSERT_TRUE(Z3 == z && Z4 == z);
}

/* ####################################################################################### */
/* Position */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, GetPosition)
{
    CGM::Matrix<4,4,int> mat
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    auto value = CGM::position(mat);
#ifdef CGM_CFG_MATRIX_POSTMULT
    auto expec = CGM::Vector<3,int>{1,3,2};
#else
    auto expec = CGM::Vector<3,int>{4,7,1};
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, SetPosition)
{
    CGM::Matrix<4,4,int> mat
    {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    CGM::setPosition(mat, {2,3,4});

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<4,4,int> expec
    {
        1, 0, 0, 2,
        0, 1, 0, 3,
        0, 0, 1, 4,
        0, 0, 0, 1
    };
#else
    CGM::Matrix<4,4,int> expec
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
        CGM::Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        CGM::Matrix<3,3,int> orient
        {
            2, 4, 5,
            3, 6, 7,
            0, 9, 8
        };

        CGM::Matrix<4,4,int> expec
        {
            2, 4, 5, 0,
            3, 6, 7, 0,
            0, 9, 8, 0,
            0, 0, 0, 1
        };

        CGM::setOrientation(mat, orient);

        ASSERT_TRUE(mat == expec);
    }

    {
        CGM::Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        CGM::Vector<3,int> x {1,2,3};
        CGM::Vector<3,int> y {4,5,6};
        CGM::Vector<3,int> z {7,8,9};

        CGM::setOrientation(mat, x, y, z);

        CGM::Matrix<4,4,int> expec
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        CGM::setX(expec, x);
        CGM::setY(expec, y);
        CGM::setZ(expec, z);

        ASSERT_TRUE(mat == expec);
    }

    {
        CGM::Matrix<4,4,double> mat
        {
            1.0, 0, 0, 0,
            0, 1.0, 0, 0,
            0, 0, 1.0, 0,
            0, 0, 0, 1.0
        };

        CGM::Vector<3,double> expec_x {0.559270,0.302442,-0.771846};
        CGM::Vector<3,double> expec_y {-0.313298,0.939132,0.140980};
        CGM::Vector<3,double> expec_z {0.767503,0.162971,0.619983};

        CGM::Quaternion<double> orientation {-0.006227,0.435855,0.174342,0.882948};

        CGM::setOrientation(mat, orientation);

        ASSERT_TRUE(CGM::eq(CGM::x(mat), expec_x, 0.0001));
        ASSERT_TRUE(CGM::eq(CGM::y(mat), expec_y, 0.0001));
        ASSERT_TRUE(CGM::eq(CGM::z(mat), expec_z, 0.0001));
    }

    {
        CGM::Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        CGM::Matrix<4,4,int> orient
        {
            2, 4, 5, 0,
            3, 6, 7, 0,
            0, 9, 8, 0,
            0, 0, 0, 1
        };

        CGM::Matrix<4,4,int> expec
        {
            2, 4, 5, 0,
            3, 6, 7, 0,
            0, 9, 8, 0,
            0, 0, 0, 1
        };

        CGM::setOrientation(mat, orient);

        ASSERT_TRUE(mat == expec);
    }
}

/* ####################################################################################### */
/* Space matrix */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Utils, FromXYZP)
{
    CGM::Vector<3,int> X {2,1,3};
    CGM::Vector<3,int> Y {4,3,6};
    CGM::Vector<3,int> Z {7,9,2};
    CGM::Vector<3,int> P {1,2,3};

    auto basis = CGM::spaceMatrix(X,Y,Z,P);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<4,4,int> expec
    {
        2,4,7,1,
        1,3,9,2,
        3,6,2,3,
        0,0,0,1
    };
#else
    CGM::Matrix<4,4,int> expec
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
    CGM::Vector<3,int> position {5,1,8};
    CGM::Matrix<3,3,int> orientation
    {
        2,1,3,
        4,3,6,
        7,9,2
    };

    auto basis = CGM::spaceMatrix(orientation, position);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<4,4,int> expec
    {
        2,1,3,5,
        4,3,6,1,
        7,9,2,8,
        0,0,0,1
    };
#else
    CGM::Matrix<4,4,int> expec
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
    const auto q = CGM::Quaternion<double>{-0.006227,0.435855,0.174342,0.882948};
    const auto p = CGM::Vector<3,double> {0.7, 1.3, 4.0};

    auto result = CGM::spaceMatrix(q,p);

    CGM::Vector<3,double> ex {0.559270,0.302442,-0.771846};
    CGM::Vector<3,double> ey {-0.313298,0.939132,0.140980};
    CGM::Vector<3,double> ez {0.767503,0.162971,0.619983};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<4,4,double> expec
    {
        ex.x, ey.x, ez.x, p.x,
        ex.y, ey.y, ez.y, p.y,
        ex.z, ey.z, ez.z, p.z,
         0.0,  0.0,  0.0, 1.0
    };
#else
    CGM::Matrix<4,4,double> expec
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
        CGM::Vector<3,int> vec {2,3,4};
        CGM::Matrix<4,4,int> mat
        {
            3,2,4,1,
            2,1,3,2,
            5,1,1,3,
            0,0,0,1
        };

        auto res = CGM::multiply<CGM::EVectorRepresentation::Point>(mat, vec);
        CGM::Vector<3,int> exp {29,21,20};
        ASSERT_TRUE(res == exp);
    }

    {
        CGM::Vector<3,int> vec {2,3,4};
        CGM::Matrix<4,4,int> mat
        {
            3,2,4,1,
            2,1,3,2,
            5,1,1,3,
            0,0,0,1
        };

        auto res = CGM::multiply<CGM::EVectorRepresentation::Direction>(mat, vec);
        CGM::Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }

}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, MultiplyVector3Matrix4)
{
    {
        CGM::Vector<3,int> vec {2,3,4};
        CGM::Matrix<4,4,int> mat
        {
            3,2,5,0,
            2,1,1,0,
            4,3,1,0,
            1,2,3,1
        };

        auto res = CGM::multiply<CGM::EVectorRepresentation::Point>(vec, mat);
        CGM::Vector<3,int> exp {29,21,20};
        ASSERT_TRUE(res == exp);
    }

    {
        CGM::Vector<3,int> vec {2,3,4};
        CGM::Matrix<4,4,int> mat
        {
            3,2,5,0,
            2,1,1,0,
            4,3,1,0,
            1,2,3,1
        };

        auto res = CGM::multiply<CGM::EVectorRepresentation::Direction>(vec, mat);
        CGM::Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, MultiplyMatrix3Matrix4)
{
    {
        CGM::Matrix<3,3,int> expect
        {
             58,  37,   39,
             99,  62,   48,
            121,  66,   76
        };

        CGM::Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        CGM::Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM::multiply<3>(mat3, mat4);

        ASSERT_TRUE(result == expect);
    }
    {
        CGM::Matrix<4,4,int> expect
        {
             58,  37,   39,   78,
             99,  62,   48,  125,
            121,  66,   76,  157,
              2,   4,    7,    3
        };

        CGM::Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        CGM::Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM::multiply<4>(mat3, mat4);

        ASSERT_TRUE(result == expect);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Utils, MultiplyVector4Matrix3)
{
    {
        CGM::Matrix<3,3,int> expect
        {
            60,  52,  47,
            62,  56,  78,
            66,  66,  80
        };

        CGM::Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        CGM::Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM::multiply<3>(mat4, mat3);

        ASSERT_TRUE(result == expect);
    }
    {
        CGM::Matrix<4,4,int> expect
        {
            60,  52,  47,  5,
            62,  56,  78,  9,
            66,  66,  80,  8,
            83,  84,  73,  3
        };

        CGM::Matrix<3,3,int> mat3
        {
            4,2,5,
            3,6,7,
            9,8,5
        };

        CGM::Matrix<4,4,int> mat4
        {
            3,1,5,5,
            8,4,2,9,
            6,5,3,8,
            2,4,7,3
        };

        auto result = CGM::multiply<4>(mat4, mat3);

        ASSERT_TRUE(result == expect);
    }
}
