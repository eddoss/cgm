

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/matrix.hpp>


using namespace std;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_RowDirIterator, Plus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.beginRowDir() + 1;
    auto it1 = input.beginRowDir() + 2;
    auto it2 = input.beginRowDir() + 3;

    ASSERT_TRUE(*it0 == 2);
    ASSERT_TRUE(*it1 == 3);
    ASSERT_TRUE(*it2 == 4);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Minus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.endRowDir() - 1;
    auto it1 = input.endRowDir() - 2;
    auto it2 = input.endRowDir() - 3;

    ASSERT_TRUE(*it0 == 9);
    ASSERT_TRUE(*it1 == 8);
    ASSERT_TRUE(*it2 == 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PreIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRowDir();

    ASSERT_TRUE(*(++it) == 2);
    ASSERT_TRUE(*(++it) == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PostIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRowDir();
    it++;

    ASSERT_TRUE(*(it++) == 2);
    ASSERT_TRUE(*(it++) == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PreDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endRowDir();

    ASSERT_TRUE(*(--it) == 9);
    ASSERT_TRUE(*(--it) == 8);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PostDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endRowDir();
    it--;

    ASSERT_TRUE(*(it--) == 9);
    ASSERT_TRUE(*(it--) == 8);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, RowsColumns_FirstComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginRowDir()};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, RowsColumns_MidComponent)
{
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.beginRowDir() + 5};

    ASSERT_TRUE(*it == 6);
    ASSERT_TRUE(it.row() == 1);
    ASSERT_TRUE(it.column() == 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, RowsColumns_LastComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginRowDir() + CGM::Matrix<3,3,int>::count - 1};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Difference)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto a {input.beginRowDir()};
    auto b {input.beginRowDir() + 3};

    ASSERT_TRUE(a-b == -3);
    ASSERT_TRUE(b-a == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_Equal)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto same_a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(a == same_a);
    ASSERT_FALSE(a == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_NotEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto same_a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(a != b);
    ASSERT_FALSE(a != same_a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_Less)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(a < b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_LessOrEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir();

    ASSERT_TRUE(a <= b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_Greater)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(b > a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_GreaterOrEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir();

    ASSERT_TRUE(b >= a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Reverse)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginRowDir();
    auto b = input.rbeginRowDir() + 1;
    auto c = input.rbeginRowDir() + 2;
    auto d = input.rbeginRowDir() + 3;

    ASSERT_TRUE(*a == 5);
    ASSERT_TRUE(*b == 4);
    ASSERT_TRUE(*c == 2);
    ASSERT_TRUE(*d == 1);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_RowDirIterator, Exception_Dereference)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PreIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endRowDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PostIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir()++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PlusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Plus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PreDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginRowDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PostDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRowDir()--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_MinusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRowDir();
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Minus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRowDir();
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Row)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Column)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get column from matrix iterator (out of range).");
    }
}

#endif