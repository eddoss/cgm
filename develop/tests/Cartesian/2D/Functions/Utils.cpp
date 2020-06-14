

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

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

    auto value2 = MATH3D_XY_NAMESPACE::getX(mat2);
    auto value3 = MATH3D_XY_NAMESPACE::getX(mat3);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto value2 = MATH3D_XY_NAMESPACE::getY(mat2);
    auto value3 = MATH3D_XY_NAMESPACE::getY(mat3);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
    MATH3D_XY_NAMESPACE::setX(mat2, x);
    MATH3D_XY_NAMESPACE::setY(mat2, y);

    Matrix<3,3,int> mat3(0);
    MATH3D_XY_NAMESPACE::setX(mat3, x);
    MATH3D_XY_NAMESPACE::setY(mat3, y);

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

    auto value = MATH3D_XY_NAMESPACE::getPosition(mat);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    MATH3D_XY_NAMESPACE::setPosition(mat, {2,3});

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto res = MATH3D_XY_NAMESPACE::getOrientation(mat);

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

        MATH3D_XY_NAMESPACE::setOrientation(mat, x, y);

        Matrix<3,3,int> expec
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };

        MATH3D_XY_NAMESPACE::setX(expec, x);
        MATH3D_XY_NAMESPACE::setY(expec, y);

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

        MATH3D_XY_NAMESPACE::setOrientation(mat, orient);

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

        MATH3D_XY_NAMESPACE::setOrientation(mat, basis);

        ASSERT_TRUE(mat == expec);
    }
}

/* ####################################################################################### */
/* Space */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_Utils, UnpackSpace)
{
    Matrix<3,3,int> basis
    {
        2,1,3,
        4,3,6,
        0,0,1
    };

    auto [x,y,p] = MATH3D_XY_NAMESPACE::unpackSpace(basis);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<2,int> expec_x {2,1};
    Vector<2,int> expec_y {4,3};
    Vector<2,int> expec_p {3,6};
#else
    Vector<2,int> expec_x {2,4};
    Vector<2,int> expec_y {1,3};
    Vector<2,int> expec_p {0,0};
#endif

    ASSERT_TRUE(x == expec_x);
    ASSERT_TRUE(y == expec_y);
    ASSERT_TRUE(p == expec_p);
}