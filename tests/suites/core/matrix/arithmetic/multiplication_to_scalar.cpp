

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/operators/matrix.hpp>


using namespace std;

TEST(Matrix_Arithmetic, MultipliOnScalar)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 4,
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            2, 4, 6
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            2, 4, 6, 8
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 3
        };
        CGM::Matrix<1,5,int> b
        {
            2, 4, 6, 8, 6
        };

        ASSERT_TRUE((a*2) == b);
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
            4
        };

        ASSERT_TRUE((a*2) == b);
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
            2, 4,
            6, 8
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> a
        {
            1, 2, 3,
            4, 3, 2
        };
        CGM::Matrix<2,3,int> b
        {
            2, 4, 6,
            8, 6, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<2,4,int> b
        {
            2, 4, 6, 8,
            6, 4, 2, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };
        CGM::Matrix<2,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8
        };

        ASSERT_TRUE((a*2) == b);
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
            4,
            6
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> a
        {
            1, 2,
            3, 4,
            3, 2
        };
        CGM::Matrix<3,2,int> b
        {
            2, 4,
            6, 8,
            6, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };
        CGM::Matrix<3,3,int> b
        {
            2, 4, 6,
            8, 6, 4,
            2, 4, 6
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };
        CGM::Matrix<3,4,int> b
        {
            2, 4, 6, 8,
            6, 4, 2, 4,
            6, 8, 6, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };
        CGM::Matrix<3,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6
        };

        ASSERT_TRUE((a*2) == b);
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
            4,
            6,
            8
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };
        CGM::Matrix<4,2,int> b
        {
            2, 4,
            6, 8,
            6, 4,
            2, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };
        CGM::Matrix<4,3,int> b
        {
            2, 4, 6,
            8, 6, 4,
            2, 4, 6,
            8, 6, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };
        CGM::Matrix<4,4,int> b
        {
            2, 4, 6, 8,
            6, 4, 2, 4,
            6, 8, 6, 4,
            2, 4, 6, 8
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };
        CGM::Matrix<4,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6,
            8, 6, 4, 2, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };
        CGM::Matrix<5,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6,
            8, 6, 4, 2, 4,
            6, 8, 6, 4, 2
        };

        ASSERT_TRUE((a*2) == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, InplaceMultipliOnScalar)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<1,2,int> b
        {
            2, 4,
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<1,3,int> b
        {
            2, 4, 6
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<1,4,int> b
        {
            2, 4, 6, 8
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> a
        {
            1, 2, 3, 4, 3
        };
        CGM::Matrix<1,5,int> b
        {
            2, 4, 6, 8, 6
        };

        ASSERT_TRUE((a*=2) == b);
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
            4
        };

        ASSERT_TRUE((a*=2) == b);
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
            2, 4,
            6, 8
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> a
        {
            1, 2, 3,
            4, 3, 2
        };
        CGM::Matrix<2,3,int> b
        {
            2, 4, 6,
            8, 6, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };
        CGM::Matrix<2,4,int> b
        {
            2, 4, 6, 8,
            6, 4, 2, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };
        CGM::Matrix<2,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8
        };

        ASSERT_TRUE((a*=2) == b);
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
            4,
            6
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> a
        {
            1, 2,
            3, 4,
            3, 2
        };
        CGM::Matrix<3,2,int> b
        {
            2, 4,
            6, 8,
            6, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };
        CGM::Matrix<3,3,int> b
        {
            2, 4, 6,
            8, 6, 4,
            2, 4, 6
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };
        CGM::Matrix<3,4,int> b
        {
            2, 4, 6, 8,
            6, 4, 2, 4,
            6, 8, 6, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };
        CGM::Matrix<3,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6
        };

        ASSERT_TRUE((a*=2) == b);
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
            4,
            6,
            8
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };
        CGM::Matrix<4,2,int> b
        {
            2, 4,
            6, 8,
            6, 4,
            2, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };
        CGM::Matrix<4,3,int> b
        {
            2, 4, 6,
            8, 6, 4,
            2, 4, 6,
            8, 6, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };
        CGM::Matrix<4,4,int> b
        {
            2, 4, 6, 8,
            6, 4, 2, 4,
            6, 8, 6, 4,
            2, 4, 6, 8
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };
        CGM::Matrix<4,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6,
            8, 6, 4, 2, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };
        CGM::Matrix<5,5,int> b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6,
            8, 6, 4, 2, 4,
            6, 8, 6, 4, 2
        };

        ASSERT_TRUE((a*=2) == b);
    }
}
