

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Operators/Vector.hpp>


using namespace std;


TEST(Matrix_Access, Row)
{
    {
        CGM::Matrix<1,2,int> mat
        {
            1, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1,2};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> mat
        {
            1, 2, 3
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1, 2, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> mat
        {
            1, 2, 3, 4
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1, 2, 3, 4};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> mat
        {
            1, 2, 3, 4, 3
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1, 2, 3, 4, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,1,int> mat
        {
            1,
            2
        };

        auto exp = 1;
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,2,int> mat
        {
            1, 2,
            3, 4
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1,2};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> mat
        {
            1, 2, 3,
            4, 3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{4, 3, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{3, 2, 1, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{2, 1, 2, 3, 4};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,1,int> mat
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
        CGM::Matrix<3,2,int> mat
        {
            1, 2,
            3, 4,
            3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1,2};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1, 2, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1, 2, 3, 4};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{1, 2, 3, 4, 3};
        ASSERT_TRUE(mat.row(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,1,int> mat
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
        CGM::Matrix<4,2,int> mat
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{3, 2};
        ASSERT_TRUE(mat.row(2) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{4, 3, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{3, 2, 1, 2};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{2, 1, 2, 3, 4};
        ASSERT_TRUE(mat.row(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };

        auto exp = CGM::Vector<decltype(mat)::columns,int>{2, 1, 2, 3, 4};
        ASSERT_TRUE(mat.row(1) == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Access, Column)
{
    {
        CGM::Matrix<1,2,int> mat
        {
            1, 2
        };

        auto exp = 1;
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> mat
        {
            1, 2, 3
        };

        auto exp = 2;
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> mat
        {
            1, 2, 3, 4
        };

        auto exp = 3;
        ASSERT_TRUE(mat.column(2) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<1,5,int> mat
        {
            1, 2, 3, 4, 3
        };

        auto exp = 4;
        ASSERT_TRUE(mat.column(3) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,1,int> mat
        {
            1,
            2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1,2};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,2,int> mat
        {
            1, 2,
            3, 4
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1,3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> mat
        {
            1, 2, 3,
            4, 3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{2,3};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{2,2};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<2,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{2,1};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,1,int> mat
        {
            1,
            2,
            3
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1,2,3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> mat
        {
            1, 2,
            3, 4,
            3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1,3,3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1, 4, 1};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1, 3, 3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<3,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1, 2, 3};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,1,int> mat
        {
            1,
            2,
            3,
            4
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1, 2, 3, 4};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> mat
        {
            1, 2,
            3, 4,
            3, 2,
            1, 2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1,3,3,1};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> mat
        {
            1, 2, 3,
            4, 3, 2,
            1, 2, 3,
            4, 3, 2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{1,4,1,4};
        ASSERT_TRUE(mat.column(0) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{2,2,4,2};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<4,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{2, 1, 2, 3};
        ASSERT_TRUE(mat.column(1) == exp);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> mat
        {
            1, 2, 3, 4, 3,
            2, 1, 2, 3, 4,
            3, 2, 1, 2, 3,
            4, 3, 2, 1, 2,
            3, 4, 3, 2, 1
        };

        auto exp = CGM::Vector<decltype(mat)::rows,int>{3, 4, 3, 2, 1};
        ASSERT_TRUE(mat.column(4) == exp);
    }
}