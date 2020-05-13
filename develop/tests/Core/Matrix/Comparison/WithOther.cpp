

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>


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

TEST(Matrix_ComparisonWithOther, Equal_PositiveTest)
{
    {
        Mat12 a
        {
            1,2
        };
        Mat12 b
        {
            1,2
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat13 a
        {
            1,2,3
        };
        Mat13 b
        {
            1,2,3
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat14 a
        {
            1,2,3,4
        };
        Mat14 b
        {
            1,2,3,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat15 a
        {
            1,2,3,4,5
        };
        Mat15 b
        {
            1,2,3,4,5
        };

        ASSERT_TRUE(a==b);
    }

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

        ASSERT_TRUE(a==b);
    }

    {
        Mat22 a
        {
            1,2,
            6,7
        };
        Mat22 b
        {
            1,2,
            6,7
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat23 a
        {
            1,2,3,
            6,7,8
        };
        Mat23 b
        {
            1,2,3,
            6,7,8
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat24 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat24 b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat25 a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        Mat25 b
        {
            1,2,3,4,5,
            6,7,8,9,8
        };

        ASSERT_TRUE(a==b);
    }

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
            3
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat32 a
        {
            1,2,
            6,7,
            7,6
        };
        Mat32 b
        {
            1,2,
            6,7,
            7,6
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat33 a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        Mat33 b
        {
            1,2,3,
            6,7,8,
            7,6,5
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat34 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat34 b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat35 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        Mat35 b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };

        ASSERT_TRUE(a==b);
    }

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
            3,
            4
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat42 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat42 b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat43 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat43 b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat44 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        Mat44 b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat45 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        Mat45 b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat51 a
        {
            1,
            2,
            3,
            4,
            5
        };
        Mat51 b
        {
            1,
            2,
            3,
            4,
            5
        };

        ASSERT_TRUE(a==b);
    }

    {
        Mat55 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        Mat55 b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };

        ASSERT_TRUE(a==b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, Equal_NegativeTest)
{
    {
        Mat12 a
        {
            1,2
        };
        Mat12 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat13 a
        {
            1,2,3
        };
        Mat13 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat14 a
        {
            1,2,3,4
        };
        Mat14 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat15 a
        {
            1,2,3,4,5
        };
        Mat15 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat21 a
        {
            1,
            2
        };
        Mat21 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat22 a
        {
            1,2,
            6,7
        };
        Mat22 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat23 a
        {
            1,2,3,
            6,7,8
        };
        Mat23 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat24 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat24 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat25 a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        Mat25 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat31 a
        {
            1,
            2,
            3
        };
        Mat31 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat32 a
        {
            1,2,
            6,7,
            7,6
        };
        Mat32 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat33 a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        Mat33 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat34 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat34 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat35 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        Mat35 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat41 a
        {
            1,
            2,
            3,
            4
        };
        Mat41 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat42 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat42 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat43 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat43 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat44 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        Mat44 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat45 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        Mat45 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat51 a
        {
            1,
            2,
            3,
            4,
            5
        };
        Mat51 b(1);

        ASSERT_FALSE(a==b);
    }

    {
        Mat55 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        Mat55 b(1);

        ASSERT_FALSE(a==b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, NotEqual_PositiveTest)
{
    {
        Mat12 a
        {
            1,2
        };
        Mat12 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat13 a
        {
            1,2,3
        };
        Mat13 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat14 a
        {
            1,2,3,4
        };
        Mat14 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat15 a
        {
            1,2,3,4,5
        };
        Mat15 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat21 a
        {
            1,
            2
        };
        Mat21 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat22 a
        {
            1,2,
            6,7
        };
        Mat22 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat23 a
        {
            1,2,3,
            6,7,8
        };
        Mat23 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat24 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat24 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat25 a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        Mat25 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat31 a
        {
            1,
            2,
            3
        };
        Mat31 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat32 a
        {
            1,2,
            6,7,
            7,6
        };
        Mat32 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat33 a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        Mat33 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat34 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat34 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat35 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        Mat35 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat41 a
        {
            1,
            2,
            3,
            4
        };
        Mat41 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat42 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat42 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat43 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat43 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat44 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        Mat44 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat45 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        Mat45 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat51 a
        {
            1,
            2,
            3,
            4,
            5
        };
        Mat51 b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        Mat55 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        Mat55 b(1);

        ASSERT_TRUE(a!=b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, NotEqual_NegativeTest)
{
    {
        Mat12 a
        {
            1,2
        };
        Mat12 b
        {
            1,2
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat13 a
        {
            1,2,3
        };
        Mat13 b
        {
            1,2,3
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat14 a
        {
            1,2,3,4
        };
        Mat14 b
        {
            1,2,3,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat15 a
        {
            1,2,3,4,5
        };
        Mat15 b
        {
            1,2,3,4,5
        };

        ASSERT_FALSE(a!=b);
    }

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

        ASSERT_FALSE(a!=b);
    }

    {
        Mat22 a
        {
            1,2,
            6,7
        };
        Mat22 b
        {
            1,2,
            6,7
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat23 a
        {
            1,2,3,
            6,7,8
        };
        Mat23 b
        {
            1,2,3,
            6,7,8
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat24 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat24 b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat25 a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        Mat25 b
        {
            1,2,3,4,5,
            6,7,8,9,8
        };

        ASSERT_FALSE(a!=b);
    }

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
            3
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat32 a
        {
            1,2,
            6,7,
            7,6
        };
        Mat32 b
        {
            1,2,
            6,7,
            7,6
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat33 a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        Mat33 b
        {
            1,2,3,
            6,7,8,
            7,6,5
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat34 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat34 b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat35 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        Mat35 b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };

        ASSERT_FALSE(a!=b);
    }

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
            3,
            4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat42 a
        {
            1,2,3,4,
            6,7,8,9
        };
        Mat42 b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat43 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        Mat43 b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat44 a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        Mat44 b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat45 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        Mat45 b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat51 a
        {
            1,
            2,
            3,
            4,
            5
        };
        Mat51 b
        {
            1,
            2,
            3,
            4,
            5
        };

        ASSERT_FALSE(a!=b);
    }

    {
        Mat55 a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        Mat55 b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };

        ASSERT_FALSE(a!=b);
    }
}