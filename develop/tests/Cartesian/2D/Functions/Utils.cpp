

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Common.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>


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

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<2,int> expec {2,4};
#else
    Vector<2,int> expec {2,3};
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

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<2,int> expec {3,6};
#else
    Vector<2,int> expec {4,6};
#endif

    ASSERT_TRUE(value2 == expec);
    ASSERT_TRUE(value3 == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Utils, SetXYZ)
{
    Vector<2,int> x {2,4};
    Vector<2,int> y {3,6};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
#else
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
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

TEST(Cartesian_2D_Functions_Utils, GetOrientation)
{
    Matrix<3,3,int> mat
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<2,2,int> expec
    {
        2, 4,
        3, 6
    };

    auto res = CGM_XY::orientation(mat);

    ASSERT_TRUE(res == expec);
}

/* --------------------------------------------------------------------------------------- */

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