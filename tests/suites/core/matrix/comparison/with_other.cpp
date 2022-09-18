

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/operators/matrix.hpp>


using namespace std;

TEST(Matrix_ComparisonWithOther, Equal_PositiveTest)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1,2
        };
        CGM::Matrix<1,2,int> b
        {
            1,2
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<1,3,int> a
        {
            1,2,3
        };
        CGM::Matrix<1,3,int> b
        {
            1,2,3
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<1,4,int> a
        {
            1,2,3,4
        };
        CGM::Matrix<1,4,int> b
        {
            1,2,3,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<1,5,int> a
        {
            1,2,3,4,5
        };
        CGM::Matrix<1,5,int> b
        {
            1,2,3,4,5
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b
        {
            1,
            2
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<2,2,int> a
        {
            1,2,
            6,7
        };
        CGM::Matrix<2,2,int> b
        {
            1,2,
            6,7
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<2,3,int> a
        {
            1,2,3,
            6,7,8
        };
        CGM::Matrix<2,3,int> b
        {
            1,2,3,
            6,7,8
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<2,4,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<2,4,int> b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<2,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        CGM::Matrix<2,5,int> b
        {
            1,2,3,4,5,
            6,7,8,9,8
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b
        {
            1,
            2,
            3
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<3,2,int> a
        {
            1,2,
            6,7,
            7,6
        };
        CGM::Matrix<3,2,int> b
        {
            1,2,
            6,7,
            7,6
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<3,3,int> a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        CGM::Matrix<3,3,int> b
        {
            1,2,3,
            6,7,8,
            7,6,5
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<3,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<3,4,int> b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<3,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        CGM::Matrix<3,5,int> b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<4,1,int> a
        {
            1,
            2,
            3,
            4
        };
        CGM::Matrix<4,1,int> b
        {
            1,
            2,
            3,
            4
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<4,2,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<4,2,int> b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<4,3,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<4,3,int> b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<4,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        CGM::Matrix<4,4,int> b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<4,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        CGM::Matrix<4,5,int> b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };

        ASSERT_TRUE(a==b);
    }

    {
        CGM::Matrix<5,1,int> a
        {
            1,
            2,
            3,
            4,
            5
        };
        CGM::Matrix<5,1,int> b
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
        CGM::Matrix<5,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        CGM::Matrix<5,5,int> b
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
        CGM::Matrix<1,2,int> a
        {
            1,2
        };
        CGM::Matrix<1,2,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<1,3,int> a
        {
            1,2,3
        };
        CGM::Matrix<1,3,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<1,4,int> a
        {
            1,2,3,4
        };
        CGM::Matrix<1,4,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<1,5,int> a
        {
            1,2,3,4,5
        };
        CGM::Matrix<1,5,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<2,2,int> a
        {
            1,2,
            6,7
        };
        CGM::Matrix<2,2,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<2,3,int> a
        {
            1,2,3,
            6,7,8
        };
        CGM::Matrix<2,3,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<2,4,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<2,4,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<2,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        CGM::Matrix<2,5,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<3,2,int> a
        {
            1,2,
            6,7,
            7,6
        };
        CGM::Matrix<3,2,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<3,3,int> a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        CGM::Matrix<3,3,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<3,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<3,4,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<3,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        CGM::Matrix<3,5,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<4,1,int> a
        {
            1,
            2,
            3,
            4
        };
        CGM::Matrix<4,1,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<4,2,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<4,2,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<4,3,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<4,3,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<4,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        CGM::Matrix<4,4,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<4,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        CGM::Matrix<4,5,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<5,1,int> a
        {
            1,
            2,
            3,
            4,
            5
        };
        CGM::Matrix<5,1,int> b(1);

        ASSERT_FALSE(a==b);
    }

    {
        CGM::Matrix<5,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        CGM::Matrix<5,5,int> b(1);

        ASSERT_FALSE(a==b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, NotEqual_PositiveTest)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1,2
        };
        CGM::Matrix<1,2,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<1,3,int> a
        {
            1,2,3
        };
        CGM::Matrix<1,3,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<1,4,int> a
        {
            1,2,3,4
        };
        CGM::Matrix<1,4,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<1,5,int> a
        {
            1,2,3,4,5
        };
        CGM::Matrix<1,5,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<2,2,int> a
        {
            1,2,
            6,7
        };
        CGM::Matrix<2,2,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<2,3,int> a
        {
            1,2,3,
            6,7,8
        };
        CGM::Matrix<2,3,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<2,4,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<2,4,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<2,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        CGM::Matrix<2,5,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<3,2,int> a
        {
            1,2,
            6,7,
            7,6
        };
        CGM::Matrix<3,2,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<3,3,int> a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        CGM::Matrix<3,3,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<3,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<3,4,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<3,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        CGM::Matrix<3,5,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<4,1,int> a
        {
            1,
            2,
            3,
            4
        };
        CGM::Matrix<4,1,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<4,2,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<4,2,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<4,3,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<4,3,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<4,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        CGM::Matrix<4,4,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<4,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        CGM::Matrix<4,5,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<5,1,int> a
        {
            1,
            2,
            3,
            4,
            5
        };
        CGM::Matrix<5,1,int> b(1);

        ASSERT_TRUE(a!=b);
    }

    {
        CGM::Matrix<5,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        CGM::Matrix<5,5,int> b(1);

        ASSERT_TRUE(a!=b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, NotEqual_NegativeTest)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1,2
        };
        CGM::Matrix<1,2,int> b
        {
            1,2
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<1,3,int> a
        {
            1,2,3
        };
        CGM::Matrix<1,3,int> b
        {
            1,2,3
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<1,4,int> a
        {
            1,2,3,4
        };
        CGM::Matrix<1,4,int> b
        {
            1,2,3,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<1,5,int> a
        {
            1,2,3,4,5
        };
        CGM::Matrix<1,5,int> b
        {
            1,2,3,4,5
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b
        {
            1,
            2
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<2,2,int> a
        {
            1,2,
            6,7
        };
        CGM::Matrix<2,2,int> b
        {
            1,2,
            6,7
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<2,3,int> a
        {
            1,2,3,
            6,7,8
        };
        CGM::Matrix<2,3,int> b
        {
            1,2,3,
            6,7,8
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<2,4,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<2,4,int> b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<2,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8
        };
        CGM::Matrix<2,5,int> b
        {
            1,2,3,4,5,
            6,7,8,9,8
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b
        {
            1,
            2,
            3
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<3,2,int> a
        {
            1,2,
            6,7,
            7,6
        };
        CGM::Matrix<3,2,int> b
        {
            1,2,
            6,7,
            7,6
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<3,3,int> a
        {
            1,2,3,
            6,7,8,
            7,6,5
        };
        CGM::Matrix<3,3,int> b
        {
            1,2,3,
            6,7,8,
            7,6,5
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<3,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<3,4,int> b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<3,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };
        CGM::Matrix<3,5,int> b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<4,1,int> a
        {
            1,
            2,
            3,
            4
        };
        CGM::Matrix<4,1,int> b
        {
            1,
            2,
            3,
            4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<4,2,int> a
        {
            1,2,3,4,
            6,7,8,9
        };
        CGM::Matrix<4,2,int> b
        {
            1,2,3,4,
            6,7,8,9
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<4,3,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };
        CGM::Matrix<4,3,int> b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<4,4,int> a
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };
        CGM::Matrix<4,4,int> b
        {
            1,2,3,4,
            6,7,8,9,
            7,6,5,4,
            2,1,2,3
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<4,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };
        CGM::Matrix<4,5,int> b
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4
        };

        ASSERT_FALSE(a!=b);
    }

    {
        CGM::Matrix<5,1,int> a
        {
            1,
            2,
            3,
            4,
            5
        };
        CGM::Matrix<5,1,int> b
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
        CGM::Matrix<5,5,int> a
        {
            1,2,3,4,5,
            6,7,8,9,8,
            7,6,5,4,3,
            2,1,2,3,4,
            5,6,7,8,9
        };
        CGM::Matrix<5,5,int> b
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