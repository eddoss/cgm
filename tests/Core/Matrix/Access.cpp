

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Core/Types/Matrix.hpp>
#include <CGM/detail/Core/Operators/Vector.hpp>


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

TEST(Matrix_Access, Row)
{
    {
        Mat12 mat
        {
            1, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{1,2};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat13 mat
        {
            1, 2, 3
        };

        auto exp = Vector<decltype(mat)::columns,int>{1, 2, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat14 mat
        {
            1, 2, 3, 4
        };

        auto exp = Vector<decltype(mat)::columns,int>{1, 2, 3, 4};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat15 mat
        {
            1, 2, 3, 4, 3
        };

        auto exp = Vector<decltype(mat)::columns,int>{1, 2, 3, 4, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat21 mat
        {
            1,
            2
        };

        auto exp = 1;
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat22 mat
        {
            1, 2,
            3, 4
        };

        auto exp = Vector<decltype(mat)::columns,int>{1,2};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat23 mat
        {
            1, 2, 3,
            4, 3, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{4, 3, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        Mat24 mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{3, 2, 1, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        Mat25 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };

        auto exp = Vector<decltype(mat)::columns,int>{2, 1, 2, 3, 4};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        Mat31 mat
        {
            1,
            2,
            3
        };

        auto exp = 1;
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat32 mat
        {
            1, 2,
            3, 4,
            3, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{1,2};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat33 mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };

        auto exp = Vector<decltype(mat)::columns,int>{1, 2, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat34 mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{1, 2, 3, 4};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat35 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };

        auto exp = Vector<decltype(mat)::columns,int>{1, 2, 3, 4, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        Mat41 mat
        {
            1,
            2,
            3,
            4
        };

        auto exp = 4;
        ASSERT_TRUE(mat.row(3) == exp);
    }

    /* -------------- */

    {
        Mat42 mat
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{3, 2};
        ASSERT_TRUE(mat.row(2) == exp);
    }

    /* -------------- */

    {
        Mat43 mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{4, 3, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        Mat44 mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };

        auto exp = Vector<decltype(mat)::columns,int>{3, 2, 1, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        Mat45 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };

        auto exp = Vector<decltype(mat)::columns,int>{2, 1, 2, 3, 4};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        Mat55 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };

        auto exp = Vector<decltype(mat)::columns,int>{2, 1, 2, 3, 4};
        ASSERT_TRUE(mat.row(1) == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Access, Column)
{
    {
        Mat12 mat
        {
            1, 2
        };

        auto exp = 1;
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat13 mat
        {
            1, 2, 3
        };

        auto exp = 2;
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        Mat14 mat
        {
            1, 2, 3, 4
        };

        auto exp = 3;
        ASSERT_TRUE(mat.column(2) == exp);
    }

    /* -------------- */

    {
        Mat15 mat
        {
            1, 2, 3, 4, 3
        };

        auto exp = 4;
        ASSERT_TRUE(mat.column(3) == exp);
    }

    /* -------------- */

    {
        Mat21 mat
        {
            1,
            2
        };

        auto exp = Vector<decltype(mat)::rows,int>{1,2};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat22 mat
        {
            1, 2,
            3, 4
        };

        auto exp = Vector<decltype(mat)::rows,int>{1,3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat23 mat
        {
            1, 2, 3,
            4, 3, 2
        };

        auto exp = Vector<decltype(mat)::rows,int>{2,3};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        Mat24 mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };

        auto exp = Vector<decltype(mat)::rows,int>{2,2};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        Mat25 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };

        auto exp = Vector<decltype(mat)::rows,int>{2,1};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        Mat31 mat
        {
            1,
            2,
            3
        };

        auto exp = Vector<decltype(mat)::rows,int>{1,2,3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat32 mat
        {
            1, 2,
            3, 4,
            3, 2
        };

        auto exp = Vector<decltype(mat)::rows,int>{1,3,3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat33 mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };

        auto exp = Vector<decltype(mat)::rows,int>{1, 4, 1};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat34 mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };

        auto exp = Vector<decltype(mat)::rows,int>{1, 3, 3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat35 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };

        auto exp = Vector<decltype(mat)::rows,int>{1, 2, 3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat41 mat
        {
            1,
            2,
            3,
            4
        };

        auto exp = Vector<decltype(mat)::rows,int>{1, 2, 3, 4};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat42 mat
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };

        auto exp = Vector<decltype(mat)::rows,int>{1,3,3,1};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat43 mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };

        auto exp = Vector<decltype(mat)::rows,int>{1,4,1,4};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        Mat44 mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };

        auto exp = Vector<decltype(mat)::rows,int>{2,2,4,2};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        Mat45 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };

        auto exp = Vector<decltype(mat)::rows,int>{2, 1, 2, 3};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        Mat55 mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };

        auto exp = Vector<decltype(mat)::rows,int>{3, 4, 3, 2, 1};
        ASSERT_TRUE(mat.column(4) == exp);
    }
}