

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/operators/matrix.hpp>


using namespace std;

TEST(Matrix_Arithmetic, MinusScalar)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            3, 4,
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            3, 4, 5
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            3, 4, 5, 6
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            3, 4, 5, 6, 7
        };

        ASSERT_TRUE((b-2) == a);
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
            3,
            4
        };

        ASSERT_TRUE((b-2) == a);
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
            3, 4,
            5, 6
        };

        ASSERT_TRUE((b-2) == a);
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
            3, 4, 5,
            6, 7, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 6
        };
        CGM::Matrix<2,4,int> b
        {
            3, 4, 5, 6,
            7, 8, 9, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4
        };
        CGM::Matrix<2,5,int> b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        ASSERT_TRUE((b-2) == a);
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
            3,
            4,
            5
        };

        ASSERT_TRUE((b-2) == a);
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
            3, 4,
            5, 6,
            7, 8
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5
        };
        CGM::Matrix<3,3,int> b
        {
            3, 4, 5,
            6, 7, 8,
            9, 8, 7
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2
        };
        CGM::Matrix<3,4,int> b
        {
            3, 4, 5, 6,
            7, 8, 9, 8,
            7, 6, 5, 4
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3
        };
        CGM::Matrix<3,5,int> b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5
        };

        ASSERT_TRUE((b-2) == a);
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
            3,
            4,
            5,
            6
        };

        ASSERT_TRUE((b-2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 6
        };
        CGM::Matrix<4,2,int> b
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
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5,
            4, 3, 2
        };
        CGM::Matrix<4,3,int> b
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
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2,
            1, 2, 3, 4
        };
        CGM::Matrix<4,4,int> b
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
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6
        };
        CGM::Matrix<4,5,int> b
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
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6,
            5, 4, 3, 2, 1
        };
        CGM::Matrix<5,5,int> b
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
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 3,
        };
        CGM::Matrix<1,2,int> c
        {
            3, 5,
        };

        ASSERT_TRUE((c-b) == a);
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
        CGM::Matrix<1,3,int> c
        {
            3, 5, 7
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            1, 2, 1, 2
        };
        CGM::Matrix<1,4,int> c
        {
            2, 4, 4, 6
        };

        ASSERT_TRUE((c-b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            1, 2, 1, 2, 1
        };
        CGM::Matrix<1,5,int> c
        {
            2, 4, 4, 6, 6
        };

        ASSERT_TRUE((c-b) == a);
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
            1,
            2
        };
        CGM::Matrix<2,1,int> c
        {
            2,
            4
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2,
            1, 2
        };
        CGM::Matrix<2,2,int> c
        {
            2, 4,
            4, 6
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2, 1,
            2, 1, 2
        };
        CGM::Matrix<2,3,int> c
        {
            2, 4, 4,
            6, 6, 8
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2, 1, 2,
            1, 2, 1, 1
        };
        CGM::Matrix<2,4,int> c
        {
            2, 4, 4, 6,
            6, 8, 8, 9
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1
        };
        CGM::Matrix<2,5,int> c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7
        };

        ASSERT_TRUE((c-b) == a);
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
            1,
            2,
            1
        };
        CGM::Matrix<3,1,int> c
        {
            2,
            4,
            4
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2,
            1, 2,
            1, 2
        };
        CGM::Matrix<3,2,int> c
        {
            2, 4,
            4, 6,
            6, 8
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2, 1,
            2, 1, 2,
            1, 1, 1
        };
        CGM::Matrix<3,3,int> c
        {
            2, 4, 4,
            6, 6, 8,
            8, 9, 8
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2
        };
        CGM::Matrix<3,4,int> c
        {
            2, 4, 4, 6,
            7, 7, 9, 9,
            8, 8, 6, 6
        };

        ASSERT_TRUE((c-b) == a);
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
            1, 2, 1, 2, 1,
            2, 1, 1, 1, 2,
            1, 2, 1, 2, 1
        };
        CGM::Matrix<3,5,int> c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 8, 8,
            6, 6, 4, 4, 2
        };

        ASSERT_TRUE((c-b) == a);
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
            1,
            2,
            1,
            2
        };
        CGM::Matrix<4,1,int> c
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
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        CGM::Matrix<4,2,int> b
        {
            1, 2,
            2, 1,
            1, 2,
            2, 1
        };
        CGM::Matrix<4,2,int> c
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
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        CGM::Matrix<4,3,int> b
        {
            1, 2, 1,
            2, 1, 2,
            1, 1, 2,
            1, 2, 1
        };
        CGM::Matrix<4,3,int> c
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
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<4,4,int> b
        {
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2,
            2, 1, 2, 1
        };
        CGM::Matrix<4,4,int> c
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
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        CGM::Matrix<4,5,int> b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2
        };
        CGM::Matrix<4,5,int> c
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
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            6, 7, 8, 7, 6
        };
        CGM::Matrix<5,5,int> b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2,
            2, 1, 1, 2, 1
        };
        CGM::Matrix<5,5,int> c
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
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            3, 4,
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            3, 4, 5
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            3, 4, 5, 6
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            3, 4, 5, 6, 7
        };

        ASSERT_TRUE((b-=2) == a);
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
            3,
            4
        };

        ASSERT_TRUE((b-=2) == a);
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
            3, 4,
            5, 6
        };

        ASSERT_TRUE((b-=2) == a);
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
            3, 4, 5,
            6, 7, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 6
        };
        CGM::Matrix<2,4,int> b
        {
            3, 4, 5, 6,
            7, 8, 9, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4
        };
        CGM::Matrix<2,5,int> b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6
        };

        ASSERT_TRUE((b-=2) == a);
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
            3,
            4,
            5
        };

        ASSERT_TRUE((b-=2) == a);
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
            3, 4,
            5, 6,
            7, 8
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5
        };
        CGM::Matrix<3,3,int> b
        {
            3, 4, 5,
            6, 7, 8,
            9, 8, 7
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2
        };
        CGM::Matrix<3,4,int> b
        {
            3, 4, 5, 6,
            7, 8, 9, 8,
            7, 6, 5, 4
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3
        };
        CGM::Matrix<3,5,int> b
        {
            3, 4, 5, 6, 7,
            8, 9, 8, 7, 6,
            5, 4, 3, 4, 5
        };

        ASSERT_TRUE((b-=2) == a);
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
            3,
            4,
            5,
            6
        };

        ASSERT_TRUE((b-=2) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 6
        };
        CGM::Matrix<4,2,int> b
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
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 6, 5,
            4, 3, 2
        };
        CGM::Matrix<4,3,int> b
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
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 6,
            5, 4, 3, 2,
            1, 2, 3, 4
        };
        CGM::Matrix<4,4,int> b
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
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6
        };
        CGM::Matrix<4,5,int> b
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
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 6, 5, 4,
            3, 2, 1, 2, 3,
            4, 5, 6, 7, 6,
            5, 4, 3, 2, 1
        };
        CGM::Matrix<5,5,int> b
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
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 3,
        };
        CGM::Matrix<1,2,int> c
        {
            3, 5,
        };

        ASSERT_TRUE((c-=b) == a);
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
        CGM::Matrix<1,3,int> c
        {
            3, 5, 7
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            1, 2, 1, 2
        };
        CGM::Matrix<1,4,int> c
        {
            2, 4, 4, 6
        };

        ASSERT_TRUE((c-=b) == a);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 5
        };
        CGM::Matrix<1,5,int> b
        {
            1, 2, 1, 2, 1
        };
        CGM::Matrix<1,5,int> c
        {
            2, 4, 4, 6, 6
        };

        ASSERT_TRUE((c-=b) == a);
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
            1,
            2
        };
        CGM::Matrix<2,1,int> c
        {
            2,
            4
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2,
            1, 2
        };
        CGM::Matrix<2,2,int> c
        {
            2, 4,
            4, 6
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2, 1,
            2, 1, 2
        };
        CGM::Matrix<2,3,int> c
        {
            2, 4, 4,
            6, 6, 8
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2, 1, 2,
            1, 2, 1, 1
        };
        CGM::Matrix<2,4,int> c
        {
            2, 4, 4, 6,
            6, 8, 8, 9
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1
        };
        CGM::Matrix<2,5,int> c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 9, 7
        };

        ASSERT_TRUE((c-=b) == a);
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
            1,
            2,
            1
        };
        CGM::Matrix<3,1,int> c
        {
            2,
            4,
            4
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2,
            1, 2,
            1, 2
        };
        CGM::Matrix<3,2,int> c
        {
            2, 4,
            4, 6,
            6, 8
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2, 1,
            2, 1, 2,
            1, 1, 1
        };
        CGM::Matrix<3,3,int> c
        {
            2, 4, 4,
            6, 6, 8,
            8, 9, 8
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2
        };
        CGM::Matrix<3,4,int> c
        {
            2, 4, 4, 6,
            7, 7, 9, 9,
            8, 8, 6, 6
        };

        ASSERT_TRUE((c-=b) == a);
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
            1, 2, 1, 2, 1,
            2, 1, 1, 1, 2,
            1, 2, 1, 2, 1
        };
        CGM::Matrix<3,5,int> c
        {
            2, 4, 4, 6, 6,
            8, 8, 9, 8, 8,
            6, 6, 4, 4, 2
        };

        ASSERT_TRUE((c-=b) == a);
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
            1,
            2,
            1,
            2
        };
        CGM::Matrix<4,1,int> c
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
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            5, 6,
            7, 8
        };
        CGM::Matrix<4,2,int> b
        {
            1, 2,
            2, 1,
            1, 2,
            2, 1
        };
        CGM::Matrix<4,2,int> c
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
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 5, 6,
            7, 8, 7,
            6, 5, 4
        };
        CGM::Matrix<4,3,int> b
        {
            1, 2, 1,
            2, 1, 2,
            1, 1, 2,
            1, 2, 1
        };
        CGM::Matrix<4,3,int> c
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
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            5, 6, 7, 8,
            7, 6, 5, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<4,4,int> b
        {
            1, 2, 1, 2,
            2, 1, 2, 1,
            1, 2, 1, 2,
            2, 1, 2, 1
        };
        CGM::Matrix<4,4,int> c
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
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6
        };
        CGM::Matrix<4,5,int> b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2
        };
        CGM::Matrix<4,5,int> c
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
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 7, 6,
            5, 4, 3, 2, 1,
            2, 3, 4, 5, 6,
            6, 7, 8, 7, 6
        };
        CGM::Matrix<5,5,int> b
        {
            1, 2, 1, 2, 1,
            2, 1, 1, 2, 1,
            1, 2, 2, 1, 1,
            1, 2, 1, 2, 2,
            2, 1, 1, 2, 1
        };
        CGM::Matrix<5,5,int> c
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