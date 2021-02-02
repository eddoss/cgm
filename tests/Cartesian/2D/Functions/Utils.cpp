

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Functions/Comparison.hpp>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Cartesian/2D/Functions/Utils.hpp>


using namespace std;

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_Utils, GetX)
{
    CGM::Matrix<2,2,int> mat2
    {
        2, 4,
        3, 6
    };

    CGM::Matrix<3,3,int> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    auto value2 = CGM_XY::x(mat2);
    auto value3 = CGM_XY::x(mat3);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Vector<2,int> expec {2,3};
#else
    CGM::Vector<2,int> expec {2,4};
#endif

    ASSERT_TRUE(value2 == expec);
    ASSERT_TRUE(value3 == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, GetY)
{
    CGM::Matrix<2,2,int> mat2
    {
        2, 4,
        3, 6
    };

    CGM::Matrix<3,3,int> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    auto value2 = CGM_XY::y(mat2);
    auto value3 = CGM_XY::y(mat3);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Vector<2,int> expec {4,6};
#else
    CGM::Vector<2,int> expec {3,6};
#endif

    ASSERT_TRUE(value2 == expec);
    ASSERT_TRUE(value3 == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, SetXYZ)
{
    CGM::Vector<2,int> x {2,4};
    CGM::Vector<2,int> y {3,6};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<2,2,int> expec2
    {
        2, 3,
        4, 6,
    };

    CGM::Matrix<3,3,int> expec3
    {
        2, 3, 0,
        4, 6, 0,
        0, 0, 0
    };
#else
    CGM::Matrix<2,2,int> expec2
    {
        2, 4,
        3, 6,
    };

    CGM::Matrix<3,3,int> expec3
    {
        2, 4, 0,
        3, 6, 0,
        0, 0, 0
    };
#endif

    CGM::Matrix<2,2,int> mat2(0);
    CGM_XY::setX(mat2, x);
    CGM_XY::setY(mat2, y);

    CGM::Matrix<3,3,int> mat3(0);
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
    CGM::Matrix<3,3,int> mat
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 1
    };

    auto value = CGM_XY::position(mat);
#ifdef CGM_CFG_MATRIX_POSTMULT
    auto expec = CGM::Vector<2,int>{5,7};
#else
    auto expec = CGM::Vector<2,int>{0,9};
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, SetPosition)
{
    CGM::Matrix<3,3,int> mat
    {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };

    CGM_XY::setPosition(mat, {2,3});

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> expec
    {
        1, 0, 2,
        0, 1, 3,
        0, 0, 1
    };
#else
    CGM::Matrix<3,3,int> expec
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
        CGM::Matrix<3,3,int> mat
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };

        CGM::Vector<2,int> x {1,2};
        CGM::Vector<2,int> y {4,5};

        CGM_XY::setOrientation(mat, x, y);

        CGM::Matrix<3,3,int> expec
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
        CGM::Matrix<3,3,int> mat
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        CGM::Matrix<2,2,int> orient
        {
            2, 4,
            3, 6
        };

        CGM::Matrix<3,3,int> expec
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        CGM_XY::setOrientation(mat, orient);

        ASSERT_TRUE(mat == expec);
    }

    {
        CGM::Matrix<3,3,int> mat
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        CGM::Matrix<3,3,int> basis
        {
            2, 4, 0,
            3, 6, 0,
            0, 0, 1
        };

        CGM::Matrix<3,3,int> expec
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
    CGM::Vector<2,int> X {2,1};
    CGM::Vector<2,int> Y {4,3};
    CGM::Vector<2,int> P {1,2};

    auto basis = CGM_XY::spaceMatrix(X,Y,P);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> expec
    {
        2,4,1,
        1,3,2,
        0,0,1
    };
#else
    CGM::Matrix<3,3,int> expec
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
    CGM::Vector<2,int> position {5,1};
    CGM::Matrix<2,2,int> orientation
    {
        2,1,
        4,3
    };

    auto basis = CGM_XY::spaceMatrix(orientation, position);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> expec
    {
        2,1,5,
        4,3,1,
        0,0,1
    };
#else
    CGM::Matrix<3,3,int> expec
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
    CGM::Vector<2,int> vec {2,3};
    CGM::Matrix<3,3,int> mat
    {
        1,4,0,
        3,5,0,
        4,3,1
    };

    {
        auto res = CGM_XY::multiply<CGM_POINT>(vec, mat);
        auto exp = CGM::Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = CGM_XY::multiply<CGM_DIRECTION>(vec, mat);
        auto exp = CGM::Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, MultiplyMatrix3Vector2)
{
    CGM::Vector<2,int> vec {2,3};
    CGM::Matrix<3,3,int> mat
    {
        1,3,4,
        4,5,3,
        0,0,1,
    };

    {
        auto res = CGM_XY::multiply<CGM_POINT>(mat, vec);
        auto exp = CGM::Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = CGM_XY::multiply<CGM_DIRECTION>(mat, vec);
        auto exp = CGM::Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, MultiplyMatrix22Matrix3)
{
    {
        CGM::Matrix<2,2,int> expect
        {
            28,  12,
            57,  27
        };

        CGM::Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        CGM::Matrix<3,3,int> mat3
        {
            3,1,5,
            8,4,2,
            6,5,3
        };

        auto result = CGM_XY::multiply<2>(mat2, mat3);
        ASSERT_TRUE(result == expect);
    }
    {
        CGM::Matrix<3,3,int> expect
        {
            28,  12,  24,
            57,  27,  27,
             6,   5,   3
        };

        CGM::Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        CGM::Matrix<3,3,int> mat3
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
        CGM::Matrix<2,2,int> expect
        {
            15,  12,
            44,  40
        };

        CGM::Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        CGM::Matrix<3,3,int> mat3
        {
            3,1,5,
            8,4,2,
            6,5,3
        };

        auto result = CGM_XY::multiply<2>(mat3, mat2);
        ASSERT_TRUE(result == expect);
    }
    {
        CGM::Matrix<3,3,int> expect
        {
            15,  12,  5,
            44,  40,  2,
            39,  42,  3
        };

        CGM::Matrix<2,2,int> mat2
        {
            4,2,
            3,6
        };

        CGM::Matrix<3,3,int> mat3
        {
            3,1,5,
            8,4,2,
            6,5,3
        };

        auto result = CGM_XY::multiply<3>(mat3, mat2);
        ASSERT_TRUE(result == expect);
    }
}