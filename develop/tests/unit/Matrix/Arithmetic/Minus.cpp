

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Matrix/Operators.hpp>


using namespace MATH3D_NAMESPACE;

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

TEST(Matrix_Arithmetic, MinusScalar)
{
    {
        Mat12 a
        {
            1, 2
        };
        Mat12 b
        {
            3, 4,
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat13 a
        {
            1, 2, 3
        };
        Mat13 b
        {
            3, 4, 5
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat14 a
        {
            1, 2, 3, 4
        };
        Mat14 b
        {
            3, 4, 5, 6
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat15 a
        {
            1, 2, 3, 4, 5
        };
        Mat15 b
        {
            3, 4, 5, 6, 7
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat21 a
        {
            1,
            2
        };
        Mat21 b
        {
            3,
            4
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat22 a
        {
            1, 2,
            3, 4
        };
        Mat22 b
        {
            3, 4,
            5, 6
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat23 a
        {
            1, 2, 3,
            4, 5, 6
        };
        Mat23 b
        {
            3, 4, 5,
            6, 7, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat24 a
        {
            1, 2, 3, 4,
            5, 6, 7, 6
        };
        Mat24 b
        {
            3, 4, 5, 6,
            7, 8, 9, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat25 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4
        };
        Mat25 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat31 a
        {
            1,
            2,
            3
        };
        Mat31 b
        {
            3,
            4,
            5
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat32 a
        {
            1, 2,
            3, 4,
            5, 6
        };
        Mat32 b
        {
            3, 4,
            5, 6,
            7, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5
        };
        Mat33 b
        {
            3, 4, 5,
            6, 7, 8,
            9, 8, 7
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat34 a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2
        };
        Mat34 b
        {
            3, 4, 5, 6,
            7, 8, 9, 8,
            7, 6, 5, 4
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat35 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3
        };
        Mat35 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat41 a
        {
            1,
            2,
            3,
            4
        };
        Mat41 b
        {
            3,
            4,
            5,
            6
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat42 a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 6
        };
        Mat42 b
        {
            3, 4,
            5, 6,
            7, 8,
            9, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat43 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5,
            4, 3, 2
        };
        Mat43 b
        {
            3, 4, 5,
            6, 7, 8,
            9, 8, 7,
            6, 5, 4
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat44 a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2,
            1, 2, 3, 4
        };
        Mat44 b
        {
            3, 4, 5, 6,
            7, 8, 9, 8,
            7, 6, 5, 4,
            3, 4, 5, 6
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat45 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6
        };
        Mat45 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5,
            6, 7, 8, 9, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        Mat55 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6,
            5, 4, 3, 2, 1
        };
        Mat55 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5,
            6, 7, 8, 9, 8,
            7, 6, 5, 4, 3
        };

        ASSERT_TRUE((b-2) == a);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, MinusOther)
{
    {
        Mat12 a
        {
            1, 2
        };
        Mat12 b
        {
            2, 3,
        };
        Mat12 c
        {
            3, 5,
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat13 a
        {
            1, 2, 3
        };
        Mat13 b
        {
            2, 3, 4
        };
        Mat13 c
        {
            3, 5, 7
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat14 a
        {
            1, 2, 3, 4
        };
        Mat14 b
        {
            1, 2, 1, 2
        };
        Mat14 c
        {
            2, 4, 4, 6
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat15 a
        {
            1, 2, 3, 4, 5
        };
        Mat15 b
        {
            1, 2, 1, 2, 1
        };
        Mat15 c
        {
            2, 4, 4, 6, 6
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat21 a
        {
            1,
            2
        };
        Mat21 b
        {
            1,
            2
        };
        Mat21 c
        {
            2,
            4
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat22 a
        {
            1, 2,
            3, 4
        };
        Mat22 b
        {
            1, 2,
            1, 2
        };
        Mat22 c
        {
            2, 4,
            4, 6
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat23 a
        {
            1, 2, 3,
            4, 5, 6
        };
        Mat23 b
        {
            1, 2, 1,
            2, 1, 2
        };
        Mat23 c
        {
            2, 4, 4,
            6, 6, 8
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat24 a
        {
            1, 2, 3, 4,
            5, 6, 7, 8
        };
        Mat24 b
        {
            1, 2, 1, 2,
            1, 2, 1, 1
        };
        Mat24 c
        {
            2, 4, 4, 6,
            6, 8, 8, 9
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat25 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6
        };
        Mat25 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1
        };
        Mat25 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat31 a
        {
            1,
            2,
            3
        };
        Mat31 b
        {
            1,
            2,
            1
        };
        Mat31 c
        {
            2,
            4,
            4
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat32 a
        {
            1, 2,
            3, 4,
            5, 6
        };
        Mat32 b
        {
            1, 2,
            1, 2,
            1, 2
        };
        Mat32 c
        {
            2, 4,
            4, 6,
            6, 8
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7
        };
        Mat33 b
        {
            1, 2, 1,
            2, 1, 2,
            1, 1, 1
        };
        Mat33 c
        {
            2, 4, 4,
            6, 6, 8,
            8, 9, 8
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat34 a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4
        };
        Mat34 b
        {
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2
        };
        Mat34 c
        {
            2, 4, 4, 6,
            7, 7, 9, 9,
            8, 8, 6, 6
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat35 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1
        };
        Mat35 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 1, 2,
            1, 2, 1, 2, 1
        };
        Mat35 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 8, 8,
            6, 6, 4, 4, 2
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat41 a
        {
            1,
            2,
            3,
            4
        };
        Mat41 b
        {
            1,
            2,
            1,
            2
        };
        Mat41 c
        {
            2,
            4,
            4,
            6
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat42 a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        Mat42 b
        {
            1, 2,
            2, 1,
            1, 2,
            2, 1
        };
        Mat42 c
        {
            2, 4,
            5, 5,
            6, 8,
            9, 9
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat43 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        Mat43 b
        {
            1, 2, 1,
            2, 1, 2,
            1, 1, 2,
            1, 2, 1
        };
        Mat43 c
        {
            2, 4, 4,
            6, 6, 8,
            8, 9, 9,
            7, 7, 5
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat44 a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        Mat44 b
        {
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2,
            2, 1, 2, 1
        };
        Mat44 c
        {
            2, 4, 4, 6,
            7, 7, 9, 9,
            8, 8, 6, 6,
            5, 3, 3, 3
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat45 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        Mat45 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2
        };
        Mat45 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7,
            6, 6, 5, 3, 2,
            3, 5, 5, 7, 8
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        Mat55 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            6, 7, 8, 7, 6
        };
        Mat55 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2,
            2, 1, 1, 2, 1
        };
        Mat55 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7,
            6, 6, 5, 3, 2,
            3, 5, 5, 7, 8,
            8, 8, 9, 9, 7
        };

        ASSERT_TRUE((c-b) == a);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, InplaceMinusScalar)
{
    {
        Mat12 a
        {
            1, 2
        };
        Mat12 b
        {
            3, 4,
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat13 a
        {
            1, 2, 3
        };
        Mat13 b
        {
            3, 4, 5
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat14 a
        {
            1, 2, 3, 4
        };
        Mat14 b
        {
            3, 4, 5, 6
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat15 a
        {
            1, 2, 3, 4, 5
        };
        Mat15 b
        {
            3, 4, 5, 6, 7
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat21 a
        {
            1,
            2
        };
        Mat21 b
        {
            3,
            4
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat22 a
        {
            1, 2,
            3, 4
        };
        Mat22 b
        {
            3, 4,
            5, 6
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat23 a
        {
            1, 2, 3,
            4, 5, 6
        };
        Mat23 b
        {
            3, 4, 5,
            6, 7, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat24 a
        {
            1, 2, 3, 4,
            5, 6, 7, 6
        };
        Mat24 b
        {
            3, 4, 5, 6,
            7, 8, 9, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat25 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4
        };
        Mat25 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat31 a
        {
            1,
            2,
            3
        };
        Mat31 b
        {
            3,
            4,
            5
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat32 a
        {
            1, 2,
            3, 4,
            5, 6
        };
        Mat32 b
        {
            3, 4,
            5, 6,
            7, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5
        };
        Mat33 b
        {
            3, 4, 5,
            6, 7, 8,
            9, 8, 7
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat34 a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2
        };
        Mat34 b
        {
            3, 4, 5, 6,
            7, 8, 9, 8,
            7, 6, 5, 4
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat35 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3
        };
        Mat35 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat41 a
        {
            1,
            2,
            3,
            4
        };
        Mat41 b
        {
            3,
            4,
            5,
            6
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat42 a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 6
        };
        Mat42 b
        {
            3, 4,
            5, 6,
            7, 8,
            9, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat43 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5,
            4, 3, 2
        };
        Mat43 b
        {
            3, 4, 5,
            6, 7, 8,
            9, 8, 7,
            6, 5, 4
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat44 a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2,
            1, 2, 3, 4
        };
        Mat44 b
        {
            3, 4, 5, 6,
            7, 8, 9, 8,
            7, 6, 5, 4,
            3, 4, 5, 6
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat45 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6
        };
        Mat45 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5,
            6, 7, 8, 9, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        Mat55 a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6,
            5, 4, 3, 2, 1
        };
        Mat55 b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5,
            6, 7, 8, 9, 8,
            7, 6, 5, 4, 3
        };

        ASSERT_TRUE((b-=2) == a);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, InplaceMinusOther)
{
    {
        Mat12 a
        {
            1, 2
        };
        Mat12 b
        {
            2, 3,
        };
        Mat12 c
        {
            3, 5,
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat13 a
        {
            1, 2, 3
        };
        Mat13 b
        {
            2, 3, 4
        };
        Mat13 c
        {
            3, 5, 7
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat14 a
        {
            1, 2, 3, 4
        };
        Mat14 b
        {
            1, 2, 1, 2
        };
        Mat14 c
        {
            2, 4, 4, 6
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat15 a
        {
            1, 2, 3, 4, 5
        };
        Mat15 b
        {
            1, 2, 1, 2, 1
        };
        Mat15 c
        {
            2, 4, 4, 6, 6
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat21 a
        {
            1,
            2
        };
        Mat21 b
        {
            1,
            2
        };
        Mat21 c
        {
            2,
            4
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat22 a
        {
            1, 2,
            3, 4
        };
        Mat22 b
        {
            1, 2,
            1, 2
        };
        Mat22 c
        {
            2, 4,
            4, 6
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat23 a
        {
            1, 2, 3,
            4, 5, 6
        };
        Mat23 b
        {
            1, 2, 1,
            2, 1, 2
        };
        Mat23 c
        {
            2, 4, 4,
            6, 6, 8
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat24 a
        {
            1, 2, 3, 4,
            5, 6, 7, 8
        };
        Mat24 b
        {
            1, 2, 1, 2,
            1, 2, 1, 1
        };
        Mat24 c
        {
            2, 4, 4, 6,
            6, 8, 8, 9
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat25 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6
        };
        Mat25 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1
        };
        Mat25 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat31 a
        {
            1,
            2,
            3
        };
        Mat31 b
        {
            1,
            2,
            1
        };
        Mat31 c
        {
            2,
            4,
            4
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat32 a
        {
            1, 2,
            3, 4,
            5, 6
        };
        Mat32 b
        {
            1, 2,
            1, 2,
            1, 2
        };
        Mat32 c
        {
            2, 4,
            4, 6,
            6, 8
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7
        };
        Mat33 b
        {
            1, 2, 1,
            2, 1, 2,
            1, 1, 1
        };
        Mat33 c
        {
            2, 4, 4,
            6, 6, 8,
            8, 9, 8
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat34 a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4
        };
        Mat34 b
        {
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2
        };
        Mat34 c
        {
            2, 4, 4, 6,
            7, 7, 9, 9,
            8, 8, 6, 6
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat35 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1
        };
        Mat35 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 1, 2,
            1, 2, 1, 2, 1
        };
        Mat35 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 8, 8,
            6, 6, 4, 4, 2
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat41 a
        {
            1,
            2,
            3,
            4
        };
        Mat41 b
        {
            1,
            2,
            1,
            2
        };
        Mat41 c
        {
            2,
            4,
            4,
            6
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat42 a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        Mat42 b
        {
            1, 2,
            2, 1,
            1, 2,
            2, 1
        };
        Mat42 c
        {
            2, 4,
            5, 5,
            6, 8,
            9, 9
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat43 a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        Mat43 b
        {
            1, 2, 1,
            2, 1, 2,
            1, 1, 2,
            1, 2, 1
        };
        Mat43 c
        {
            2, 4, 4,
            6, 6, 8,
            8, 9, 9,
            7, 7, 5
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat44 a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        Mat44 b
        {
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2,
            2, 1, 2, 1
        };
        Mat44 c
        {
            2, 4, 4, 6,
            7, 7, 9, 9,
            8, 8, 6, 6,
            5, 3, 3, 3
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat45 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        Mat45 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2
        };
        Mat45 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7,
            6, 6, 5, 3, 2,
            3, 5, 5, 7, 8
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        Mat55 a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            6, 7, 8, 7, 6
        };
        Mat55 b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2,
            2, 1, 1, 2, 1
        };
        Mat55 c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7,
            6, 6, 5, 3, 2,
            3, 5, 5, 7, 8,
            8, 8, 9, 9, 7
        };

        ASSERT_TRUE((c-=b) == a);
    }
}