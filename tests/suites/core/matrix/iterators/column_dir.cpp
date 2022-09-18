

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/matrix.hpp>


using namespace std;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_ColumnDirIterator, Plus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.beginColumnDir() + 1;
    auto it1 = input.beginColumnDir() + 2;
    auto it2 = input.beginColumnDir() + 3;

    ASSERT_TRUE(*it0 == 4);
    ASSERT_TRUE(*it1 == 7);
    ASSERT_TRUE(*it2 == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Minus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.endColumnDir() - 1;
    auto it1 = input.endColumnDir() - 2;
    auto it2 = input.endColumnDir() - 3;

    ASSERT_TRUE(*it0 == 9);
    ASSERT_TRUE(*it1 == 6);
    ASSERT_TRUE(*it2 == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PreIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginColumnDir();

    ASSERT_TRUE(*(++it) == 4);
    ASSERT_TRUE(*(++it) == 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PostIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginColumnDir();
    it++;

    ASSERT_TRUE(*(it++) == 4);
    ASSERT_TRUE(*(it++) == 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PreDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endColumnDir();

    ASSERT_TRUE(*(--it) == 9);
    ASSERT_TRUE(*(--it) == 6);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PostDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endColumnDir();
    it--;

    ASSERT_TRUE(*(it--) == 9);
    ASSERT_TRUE(*(it--) == 6);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, RowsColumns_FirstComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginColumnDir()};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, RowsColumns_MidComponent)
{
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.beginColumnDir() + 5};

    ASSERT_TRUE(*it == 7);
    ASSERT_TRUE(it.row() == 1);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, RowsColumns_LastComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginColumnDir() + CGM::Matrix<3,3,int>::count - 1};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Difference)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto a {input.beginColumnDir()};
    auto b {input.beginColumnDir() + 3};

    ASSERT_TRUE(b-a == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_Equal)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto same_a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(a == same_a);
    ASSERT_FALSE(a == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_NotEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto same_a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(a != b);
    ASSERT_FALSE(a != same_a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_Less)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(a < b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_LessOrEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir();

    ASSERT_TRUE(a <= b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_Greater)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(b > a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_GreaterOrEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir();

    ASSERT_TRUE(b >= a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Reverse)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginColumnDir();
    auto b = input.rbeginColumnDir() + 1;
    auto c = input.rbeginColumnDir() + 2;
    auto d = input.rbeginColumnDir() + 3;

    ASSERT_TRUE(*a == 5);
    ASSERT_TRUE(*b == 2);
    ASSERT_TRUE(*c == 4);
    ASSERT_TRUE(*d == 1);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_ColumnDirIterator, Exception_Dereference)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PreIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endColumnDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PostIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir()++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PlusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Plus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PreDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginColumnDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PostDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumnDir()--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_MinusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumnDir();
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Minus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumnDir();
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Row)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Column)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get column from matrix iterator (out of range).");
    }
}

#endif