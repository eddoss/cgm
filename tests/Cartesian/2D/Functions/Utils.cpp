

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Common.hpp>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Cartesian/2D/Functions/Utils.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_Utils, GetX)
{
    Matrix<2,2,int> mat2
    {
        2, 4,
        3, 6
    };

    Matrix<3,3,int> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    auto value2 = CGM_XY::x(mat2);
    auto value3 = CGM_XY::x(mat3);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Vector<2,int> expec {2,3};
#else
    Vector<2,int> expec {2,4};
#endif

    ASSERT_TRUE(value2 == expec);
    ASSERT_TRUE(value3 == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, GetY)
{
    Matrix<2,2,int> mat2
    {
        2, 4,
        3, 6
    };

    Matrix<3,3,int> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    auto value2 = CGM_XY::y(mat2);
    auto value3 = CGM_XY::y(mat3);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Vector<2,int> expec {4,6};
#else
    Vector<2,int> expec {3,6};
#endif

    ASSERT_TRUE(value2 == expec);
    ASSERT_TRUE(value3 == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, SetXYZ)
{
    Vector<2,int> x {2,4};
    Vector<2,int> y {3,6};

#ifdef CGM_CFG_MATRIX_POSTMULT
    Matrix<2,2,int> expec2
    {
        2, 3,
        4, 6,
    };

    Matrix<3,3,int> expec3
    {
        2, 3, 0,
        4, 6, 0,
        0, 0, 0
    };
#else
    Matrix<2,2,int> expec2
    {
        2, 4,
        3, 6,
    };

    Matrix<3,3,int> expec3
    {
        2, 4, 0,
        3, 6, 0,
        0, 0, 0
    };
#endif

    Matrix<2,2,int> mat2(0);
    CGM_XY::setX(mat2, x);
    CGM_XY::setY(mat2, y);

    Matrix<3,3,int> mat3(0);
    CGM_XY::setX(mat3, x);
    CGM_XY::setY(mat3, y);

    ASSERT_TRUE(mat2 == expec2);
    ASSERT_TRUE(mat3 == expec3);
}

/* ####################################################################################### */
/* Position */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_Utils, GetPosition)
{
    Matrix<3,3,int> mat
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 1
    };

    auto value = CGM_XY::position(mat);
#ifdef CGM_CFG_MATRIX_POSTMULT
    auto expec = Vector<2,int>{5,7};
#else
    auto expec = Vector<2,int>{0,9};
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, SetPosition)
{
    Matrix<3,3,int> mat
    {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };

    CGM_XY::setPosition(mat, {2,3});

#ifdef CGM_CFG_MATRIX_POSTMULT
    Matrix<3,3,int> expec
    {
        1, 0, 2,
        0, 1, 3,
        0, 0, 1
    };
#else
    Matrix<3,3,int> expec
    {
        1, 0, 0,
        0, 1, 0,
        2, 3, 1
    };
#endif

    ASSERT_TRUE(mat == expec);
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_Utils, SetOrientation)
{
    {
        Matrix<3,3,int> mat
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };

        Vector<2,int> x {1,2};
        Vector<2,int> y {4,5};

        CGM_XY::setOrientation(mat, x, y);

        Matrix<3,3,int> expec
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };

        CGM_XY::setX(expec, x);
        CGM_XY::setY(expec, y);

        ASSERT_TRUE(mat == expec);
    }

    {
        Matrix<3,3,int> mat
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        Matrix<2,2,int> orient
        {
            2, 4,
            3, 6
        };

        Matrix<3,3,int> expec
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        CGM_XY::setOrientation(mat, orient);

        ASSERT_TRUE(mat == expec);
    }

    {
        Matrix<3,3,int> mat
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        Matrix<3,3,int> basis
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        Matrix<3,3,int> expec
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        CGM_XY::setOrientation(mat, basis);

        ASSERT_TRUE(mat == expec);
    }
}

/* ####################################################################################### */
/* Space matrix */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_Utils, SpaceMatrix_FromAxes)
{
    Vector<2,int> X {2,1};
    Vector<2,int> Y {4,3};
    Vector<2,int> P {1,2};

    auto basis = CGM_XY::spaceMatrix(X,Y,P);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Matrix<3,3,int> expec
    {
        2,4,1,
        1,3,2,
        0,0,1
    };
#else
    Matrix<3,3,int> expec
    {
        2,1,0,
        4,3,0,
        1,2,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, SpaceMatrix_FromMatrixAndPosition)
{
    Vector<2,int> position {5,1};
    Matrix<2,2,int> orientation
    {
        2,1,
        4,3
    };

    auto basis = CGM_XY::spaceMatrix(orientation, position);

#ifdef CGM_CFG_MATRIX_POSTMULT
    Matrix<3,3,int> expec
    {
        2,1,5,
        4,3,1,
        0,0,1
    };
#else
    Matrix<3,3,int> expec
    {
        2,1,0,
        4,3,0,
        5,1,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_Utils, MultiplyVector2Matrix3)
{
    Vector<2,int> vec {2,3};
    Matrix<3,3,int> mat
    {
        1,4,0,
        3,5,0,
        4,3,1
    };

    {
        auto res = CGM_XY::multiply<CGM_POINT>(vec, mat);
        auto exp = Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = CGM_XY::multiply<CGM_DIRECTION>(vec, mat);
        auto exp = Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, MultiplyMatrix3Vector2)
{
    Vector<2,int> vec {2,3};
    Matrix<3,3,int> mat
    {
        1,3,4,
        4,5,3,
        0,0,1,
    };

    {
        auto res = CGM_XY::multiply<CGM_POINT>(mat, vec);
        auto exp = Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = CGM_XY::multiply<CGM_DIRECTION>(mat, vec);
        auto exp = Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, MultiplyMatrix22Matrix3)
{
    {
        Matrix<2,2,int> expect
        {
            28,  12,
            57,  27
        };

        Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        Matrix<3,3,int> mat3
        {
            3,1,5,
            8,4,2,
            6,5,3
        };

        auto result = CGM_XY::multiply<2>(mat2, mat3);
        ASSERT_TRUE(result == expect);
    }
    {
        Matrix<3,3,int> expect
        {
            28,  12,  24,
            57,  27,  27,
             6,   5,   3
        };

        Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        Matrix<3,3,int> mat3
        {
            3,1,5,
            8,4,2,
            6,5,3
        };

        auto result = CGM_XY::multiply<3>(mat2, mat3);
        ASSERT_TRUE(result == expect);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, MultiplyMatrix3Matrix2)
{
    {
        Matrix<2,2,int> expect
        {
            15,  12,
            44,  40
        };

        Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        Matrix<3,3,int> mat3
        {
            3,1,5,
            8,4,2,
            6,5,3
        };

        auto result = CGM_XY::multiply<2>(mat3, mat2);
        ASSERT_TRUE(result == expect);
    }
    {
        Matrix<3,3,int> expect
        {
            15,  12,  5,
            44,  40,  2,
            39,  42,  3
        };

        Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        Matrix<3,3,int> mat3
        {
            3,1,5,
            8,4,2,
            6,5,3
        };

        auto result = CGM_XY::multiply<3>(mat3, mat2);
        ASSERT_TRUE(result == expect);
    }
}