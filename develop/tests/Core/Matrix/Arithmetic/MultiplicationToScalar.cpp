

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Operators/Matrix.hpp>


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

TEST(Matrix_Arithmetic, MultipliOnScalar)
{
    {
        Mat12 a
        {
            1, 2
        };
        Mat12 b
        {
            2, 4,
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat13 a
        {
            1, 2, 3
        };
        Mat13 b
        {
            2, 4, 6
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat14 a
        {
            1, 2, 3, 4
        };
        Mat14 b
        {
            2, 4, 6, 8
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat15 a
        {
            1, 2, 3, 4, 3
        };
        Mat15 b
        {
            2, 4, 6, 8, 6
        };

        ASSERT_TRUE((a*2) == b);
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
            2,
            4
        };

        ASSERT_TRUE((a*2) == b);
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
            2, 4,
            6, 8
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat23 a
        {
            1, 2, 3,
            4, 3, 2
        };
        Mat23 b
        {
            2, 4, 6,
            8, 6, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat24 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };
        Mat24 b
        {
            2, 4, 6, 8,
            6, 4, 2, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat25 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };
        Mat25 b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8
        };

        ASSERT_TRUE((a*2) == b);
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
            2,
            4,
            6
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat32 a
        {
            1, 2,
            3, 4,
            3, 2
        };
        Mat32 b
        {
            2, 4,
            6, 8,
            6, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };
        Mat33 b
        {
            2, 4, 6,
            8, 6, 4,
            2, 4, 6
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat34 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };
        Mat34 b
        {
            2, 4, 6, 8,
            6, 4, 2, 4,
            6, 8, 6, 4
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat35 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };
        Mat35 b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6
        };

        ASSERT_TRUE((a*2) == b);
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
            2,
            4,
            6,
            8
        };

        ASSERT_TRUE((a*2) == b);
    }

    /* -------------- */

    {
        Mat42 a
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };
        Mat42 b
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
        Mat43 a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };
        Mat43 b
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
        Mat44 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };
        Mat44 b
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
        Mat45 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };
        Mat45 b
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
        Mat55 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };
        Mat55 b
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
        Mat12 a
        {
            1, 2
        };
        Mat12 b
        {
            2, 4,
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat13 a
        {
            1, 2, 3
        };
        Mat13 b
        {
            2, 4, 6
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat14 a
        {
            1, 2, 3, 4
        };
        Mat14 b
        {
            2, 4, 6, 8
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat15 a
        {
            1, 2, 3, 4, 3
        };
        Mat15 b
        {
            2, 4, 6, 8, 6
        };

        ASSERT_TRUE((a*=2) == b);
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
            2,
            4
        };

        ASSERT_TRUE((a*=2) == b);
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
            2, 4,
            6, 8
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat23 a
        {
            1, 2, 3,
            4, 3, 2
        };
        Mat23 b
        {
            2, 4, 6,
            8, 6, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat24 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };
        Mat24 b
        {
            2, 4, 6, 8,
            6, 4, 2, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat25 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };
        Mat25 b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8
        };

        ASSERT_TRUE((a*=2) == b);
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
            2,
            4,
            6
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat32 a
        {
            1, 2,
            3, 4,
            3, 2
        };
        Mat32 b
        {
            2, 4,
            6, 8,
            6, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };
        Mat33 b
        {
            2, 4, 6,
            8, 6, 4,
            2, 4, 6
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat34 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };
        Mat34 b
        {
            2, 4, 6, 8,
            6, 4, 2, 4,
            6, 8, 6, 4
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat35 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };
        Mat35 b
        {
            2, 4, 6, 8, 6,
            4, 2, 4, 6, 8,
            6, 4, 2, 4, 6
        };

        ASSERT_TRUE((a*=2) == b);
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
            2,
            4,
            6,
            8
        };

        ASSERT_TRUE((a*=2) == b);
    }

    /* -------------- */

    {
        Mat42 a
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };
        Mat42 b
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
        Mat43 a
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };
        Mat43 b
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
        Mat44 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };
        Mat44 b
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
        Mat45 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };
        Mat45 b
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
        Mat55 a
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };
        Mat55 b
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
