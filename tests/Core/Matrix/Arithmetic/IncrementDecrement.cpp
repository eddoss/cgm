

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>


using namespace std;

/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

TEST(Matrix_Arithmetic, PreIncrement)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 3,
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            2, 3, 4
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */


    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            2, 3, 4, 5
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            2, 3, 4, 5, 6
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b
        {
            2,
            3
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,2,int> a
        {
            1, 2,
            3, 4
        };
        CGM::Matrix<2,2,int> b
        {
            2, 3,
            4, 5
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> a
        {
            1, 2, 3,
            4, 5, 6
        };
        CGM::Matrix<2,3,int> b
        {
            2, 3, 4,
            5, 6, 7
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8
        };
        CGM::Matrix<2,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6
        };
        CGM::Matrix<2,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b
        {
            2,
            3,
            4
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> a
        {
            1, 2,
            3, 4,
            5, 6
        };
        CGM::Matrix<3,2,int> b
        {
            2, 3,
            4, 5,
            6, 7
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7
        };
        CGM::Matrix<3,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4
        };
        CGM::Matrix<3,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1
        };
        CGM::Matrix<3,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

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
            2,
            3,
            4,
            5
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        CGM::Matrix<4,2,int> b
        {
            2, 3,
            4, 5,
            6, 7,
            8, 9
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        CGM::Matrix<4,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8,
            7, 6, 5
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<4,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5,
            4, 3, 2, 3
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        CGM::Matrix<4,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7
        };

        ASSERT_TRUE((++a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            7, 8, 7, 6, 5
        };
        CGM::Matrix<5,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        ASSERT_TRUE((++a) == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, PreDecrement)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 3,
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            2, 3, 4
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */


    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            2, 3, 4, 5
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            2, 3, 4, 5, 6
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b
        {
            2,
            3
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,2,int> a
        {
            1, 2,
            3, 4
        };
        CGM::Matrix<2,2,int> b
        {
            2, 3,
            4, 5
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> a
        {
            1, 2, 3,
            4, 5, 6
        };
        CGM::Matrix<2,3,int> b
        {
            2, 3, 4,
            5, 6, 7
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8
        };
        CGM::Matrix<2,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6
        };
        CGM::Matrix<2,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b
        {
            2,
            3,
            4
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> a
        {
            1, 2,
            3, 4,
            5, 6
        };
        CGM::Matrix<3,2,int> b
        {
            2, 3,
            4, 5,
            6, 7
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7
        };
        CGM::Matrix<3,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4
        };
        CGM::Matrix<3,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1
        };
        CGM::Matrix<3,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

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
            2,
            3,
            4,
            5
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        CGM::Matrix<4,2,int> b
        {
            2, 3,
            4, 5,
            6, 7,
            8, 9
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        CGM::Matrix<4,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8,
            7, 6, 5
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<4,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5,
            4, 3, 2, 3
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        CGM::Matrix<4,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7
        };

        ASSERT_TRUE((--b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            7, 8, 7, 6, 5
        };
        CGM::Matrix<5,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        ASSERT_TRUE((--b) == a);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, PostIncrement)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 3,
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            2, 3, 4
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */


    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            2, 3, 4, 5
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            2, 3, 4, 5, 6
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b
        {
            2,
            3
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,2,int> a
        {
            1, 2,
            3, 4
        };
        CGM::Matrix<2,2,int> b
        {
            2, 3,
            4, 5
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> a
        {
            1, 2, 3,
            4, 5, 6
        };
        CGM::Matrix<2,3,int> b
        {
            2, 3, 4,
            5, 6, 7
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8
        };
        CGM::Matrix<2,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6
        };
        CGM::Matrix<2,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b
        {
            2,
            3,
            4
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> a
        {
            1, 2,
            3, 4,
            5, 6
        };
        CGM::Matrix<3,2,int> b
        {
            2, 3,
            4, 5,
            6, 7
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7
        };
        CGM::Matrix<3,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4
        };
        CGM::Matrix<3,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1
        };
        CGM::Matrix<3,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

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
            2,
            3,
            4,
            5
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        CGM::Matrix<4,2,int> b
        {
            2, 3,
            4, 5,
            6, 7,
            8, 9
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        CGM::Matrix<4,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8,
            7, 6, 5
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<4,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5,
            4, 3, 2, 3
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        CGM::Matrix<4,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7
        };

        a++;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            7, 8, 7, 6, 5
        };
        CGM::Matrix<5,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        a++;
        ASSERT_TRUE(a == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, PostDecrement)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 3,
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            2, 3, 4
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */


    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            2, 3, 4, 5
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            2, 3, 4, 5, 6
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<2,1,int> b
        {
            2,
            3
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,2,int> a
        {
            1, 2,
            3, 4
        };
        CGM::Matrix<2,2,int> b
        {
            2, 3,
            4, 5
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> a
        {
            1, 2, 3,
            4, 5, 6
        };
        CGM::Matrix<2,3,int> b
        {
            2, 3, 4,
            5, 6, 7
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8
        };
        CGM::Matrix<2,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6
        };
        CGM::Matrix<2,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<3,1,int> b
        {
            2,
            3,
            4
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> a
        {
            1, 2,
            3, 4,
            5, 6
        };
        CGM::Matrix<3,2,int> b
        {
            2, 3,
            4, 5,
            6, 7
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7
        };
        CGM::Matrix<3,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4
        };
        CGM::Matrix<3,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1
        };
        CGM::Matrix<3,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

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
            2,
            3,
            4,
            5
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        CGM::Matrix<4,2,int> b
        {
            2, 3,
            4, 5,
            6, 7,
            8, 9
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        CGM::Matrix<4,3,int> b
        {
            2, 3, 4,
            5, 6, 7,
            8, 9, 8,
            7, 6, 5
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<4,4,int> b
        {
            2, 3, 4, 5,
            6, 7, 8, 9,
            8, 7, 6, 5,
            4, 3, 2, 3
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        CGM::Matrix<4,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7
        };

        b--;
        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            7, 8, 7, 6, 5
        };
        CGM::Matrix<5,5,int> b
        {
            2, 3, 4, 5, 6,
            7, 8, 9, 8, 7,
            6, 5, 4, 3, 2,
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        b--;
        ASSERT_TRUE(a == b);
    }
}
