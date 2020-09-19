

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Core/Types/Matrix.hpp>
#include <CGM/detail/Core/Operators/Matrix.hpp>


using namespace CGM;

using namespace std;
using Mat12 = Matrix<1,2,int>;
using Mat13 = Matrix<1,3,int>;
using Mat14 = Matrix<1,4,int>;
using Mat15 = Matrix<1,5,int>;
using Mat21 = Matrix<2,1,int>;
using Mat22 = Matrix<2,2,int>;
using Mat23 = Matrix<2,3,int>;
using Mat24 = Matrix<2,4,int>;
using Mat25 = Matrix<2,5,int>;
using Mat31 = Matrix<3,1,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat35 = Matrix<3,5,int>;
using Mat41 = Matrix<4,1,int>;
using Mat42 = Matrix<4,2,int>;
using Mat43 = Matrix<4,3,int>;
using Mat44 = Matrix<4,4,int>;
using Mat45 = Matrix<4,5,int>;
using Mat51 = Matrix<5,1,int>;
using Mat55 = Matrix<5,5,int>;

TEST(Matrix_MatrixMultiplication, Mat22__x__Mat22__Res22)
{
    Mat22 a
    {
        6,6,
        4,8
    };
    Mat22 b
    {
        2,9,
        4,4
    };
    Mat22 c
    {
        36,78,
        40,68
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat22__x__Mat23__Res23)
{
    Mat22 a
    {
        9,3,
        9,5
    };
    Mat23 b
    {
        5,4,2,
        9,3,3
    };
    Mat23 c
    {
        72,45,27,
        90,51,33
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat22__x__Mat24__Res24)
{
    Mat22 a
    {
        4,4,
        8,1
    };
    Mat24 b
    {
        6,6,5,3,
        2,9,4,4
    };
    Mat24 c
    {
        32,60,36,28,
        50,57,44,28
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat23__x__Mat32__Res22)
{
    Mat23 a
    {
        7,9,3,
        7,4,5
    };
    Mat32 b
    {
        1,6,
        8,1,
        7,1
    };
    Mat22 c
    {
        100,54,
        74,51
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat23__x__Mat33__Res23)
{
    Mat23 a
    {
        9,6,2,
        2,5,8
    };
    Mat33 b
    {
        7,2,8,
        3,3,8,
        1,8,8
    };
    Mat23 c
    {
        83,52,136,
        37,83,120
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat23__x__Mat34__Res24)
{
    Mat23 a
    {
        8,7,9,
        2,1,8
    };
    Mat34 b
    {
        1,8,2,4,
        7,9,8,8,
        3,4,3,5
    };
    Mat24 c
    {
        84,163,99,133,
        33,57,36,56
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat24__x__Mat42__Res22)
{
    Mat24 a
    {
        1,9,8,2,
        1,1,2,5
    };
    Mat42 b
    {
        2,5,
        4,4,
        2,6,
        9,1
    };
    Mat22 c
    {
        72,91,
        55,26
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat24__x__Mat43__Res23)
{
    Mat24 a
    {
        6,3,3,3,
        7,5,6,6
    };
    Mat43 b
    {
        1,2,4,
        9,5,6,
        4,1,6,
        2,4,1
    };
    Mat23 c
    {
        51,42,63,
        88,69,100
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat24__x__Mat44__Res24)
{
    Mat24 a
    {
        3,8,9,6,
        6,8,2,3
    };
    Mat44 b
    {
        4,9,9,4,
        9,4,7,5,
        3,2,9,9,
        1,9,6,4
    };
    Mat24 c
    {
        117,131,200,157,
        105,117,146,94
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat32__x__Mat22__Res32)
{
    Mat32 a
    {
        5,8,
        3,6,
        5,1
    };
    Mat22 b
    {
        7,9,
        9,3
    };
    Mat32 c
    {
        107,69,
        75,45,
        44,48
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat32__x__Mat23__Res33)
{
    Mat32 a
    {
        6,6,
        5,5,
        4,6
    };
    Mat23 b
    {
        7,3,1,
        5,5,5
    };
    Mat33 c
    {
        72,48,36,
        60,40,30,
        58,42,34
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat32__x__Mat24__Res34)
{
    Mat32 a
    {
        1,5,
        8,5,
        4,7
    };
    Mat24 b
    {
        2,7,2,2,
        3,2,4,1
    };
    Mat34 c
    {
        17,17,22,7,
        31,66,36,21,
        29,42,36,15
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat33__x__Mat32__Res32)
{
    Mat33 a
    {
        3,1,1,
        9,6,2,
        4,8,7
    };
    Mat32 b
    {
        3,5,
        5,3,
        4,4
    };
    Mat32 c
    {
        18,22,
        65,71,
        80,72
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat33__x__Mat33__Res33)
{
    Mat33 a
    {
        8,7,1,
        6,9,5,
        2,5,3
    };
    Mat33 b
    {
        4,1,8,
        8,4,6,
        3,3,6
    };
    Mat33 c
    {
        91,39,112,
        111,57,132,
        57,31,64
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat33__x__Mat34__Res34)
{
    Mat33 a
    {
        9,4,4,
        3,9,3,
        8,5,2
    };
    Mat34 b
    {
        9,6,3,1,
        8,7,8,3,
        2,6,4,4
    };
    Mat34 c
    {
        121,106,75,37,
        105,99,93,42,
        116,95,72,31
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat34__x__Mat42__Res32)
{
    Mat34 a
    {
        6,6,1,7,
        4,6,4,1,
        7,5,9,8
    };
    Mat42 b
    {
        8,1,
        5,5,
        7,3,
        3,7
    };
    Mat32 c
    {
        106,88,
        93,53,
        168,115
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat34__x__Mat43__Res33)
{
    Mat34 a
    {
        4,6,4,7,
        5,7,6,9,
        5,6,4,9
    };
    Mat43 b
    {
        6,1,1,
        1,3,8,
        8,9,5,
        5,9,7
    };
    Mat33 c
    {
        97,121,121,
        130,161,154,
        113,140,136
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat34__x__Mat44__Res34)
{
    Mat34 a
    {
        2,4,9,6,
        6,2,5,2,
        1,4,3,4
    };
    Mat44 b
    {
        7,7,1,2,
        3,6,6,5,
        8,2,4,8,
        5,5,1,2
    };
    Mat34 c
    {
        128,86,68,108,
        98,74,40,66,
        63,57,41,54
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat42__x__Mat22__Res42)
{
    Mat42 a
    {
        2,9,
        8,1,
        5,8,
        3,2
    };
    Mat22 b
    {
        1,7,
        6,1
    };
    Mat42 c
    {
        56,23,
        14,57,
        53,43,
        15,23
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat42__x__Mat23__Res43)
{
    Mat42 a
    {
        7,5,
        2,8,
        8,1,
        1,9
    };
    Mat23 b
    {
        2,7,9,
        3,8,9
    };
    Mat43 c
    {
        29,89,108,
        28,78,90,
        19,64,81,
        29,79,90
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat42__x__Mat24__Res44)
{
    Mat42 a
    {
        3,9,
        4,9,
        4,1,
        2,1
    };
    Mat24 b
    {
        3,6,1,9,
        5,3,3,2
    };
    Mat44 c
    {
        54,45,30,45,
        57,51,31,54,
        17,27,7,38,
        11,15,5,20
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat43__x__Mat32__Res42)
{
    Mat43 a
    {
        4,3,2,
        1,8,8,
        8,6,6,
        2,5,5
    };
    Mat32 b
    {
        8,8,
        1,6,
        8,4
    };
    Mat42 c
    {
        51,58,
        80,88,
        118,124,
        61,66
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat43__x__Mat33__Res43)
{
    Mat43 a
    {
        7,9,2,
        3,1,1,
        4,7,5,
        1,5,6
    };
    Mat33 b
    {
        8,8,6,
        8,4,5,
        4,9,2
    };
    Mat43 c
    {
        136,110,91,
        36,37,25,
        108,105,69,
        72,82,43
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat43__x__Mat34__Res44)
{
    Mat43 a
    {
        7,1,4,
        4,2,7,
        4,7,8,
        8,5,3
    };
    Mat34 b
    {
        2,4,9,4,
        6,3,8,3,
        9,7,3,7
    };
    Mat44 c
    {
        56,59,83,59,
        83,71,73,71,
        122,93,116,93,
        73,68,121,68
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat44__x__Mat42__Res42)
{
    Mat44 a
    {
        6,5,6,3,
        2,3,3,4,
        4,2,5,3,
        1,3,1,5
    };
    Mat42 b
    {
        9,2,
        3,8,
        4,2,
        2,5
    };
    Mat42 c
    {
        99,79,
        47,54,
        68,49,
        32,53
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat44__x__Mat43__Res43)
{
    Mat44 a
    {
        7,2,4,8,
        5,9,6,4,
        9,8,2,2,
        9,8,4,8
    };
    Mat43 b
    {
        7,8,3,
        3,6,1,
        6,4,4,
        9,1,9
    };
    Mat43 c
    {
        151,92,111,
        134,122,84,
        117,130,61,
        183,144,123
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat44__x__Mat44__Res44)
{
    Mat44 a
    {
        1,1,7,8,
        7,3,1,3,
        5,9,5,1,
        1,1,1,9
    };
    Mat44 b
    {
        6,5,8,7,
        2,7,1,4,
        2,4,2,1,
        9,4,9,4
    };
    Mat44 c
    {
        94,72,95,50,
        77,72,88,74,
        67,112,68,80,
        91,52,92,48
    };

    ASSERT_TRUE((a * b) == c);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, Mat55__x__Mat55__Res55)
{
    Mat55 a
    {
        9,1,6,9,8,
        2,6,7,9,4,
        9,8,6,6,9,
        1,6,1,5,7,
        7,5,4,6,6
    };
    Mat55 b
    {
        1,1,5,9,1,
        9,3,4,1,3,
        8,7,3,2,4,
        6,9,5,4,3,
        6,5,2,6,5
    };
    Mat55 c
    {
        168,175,128,178,103,
        190,170,108,98,95,
        219,174,143,179,120,
        135,106,71,79,73,
        156,134,109,136,86
    };

    ASSERT_TRUE((a * b) == c);
}