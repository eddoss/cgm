

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Matrix.hpp>


using namespace std;

TEST(Matrix_ColumnIterator, Plus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    CGM::Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.beginColumn(column);
    auto it_12 = input.beginColumn(column) + 1;
    auto it_22 = input.beginColumn(column) + 2;

    ASSERT_TRUE(*it_02 == 3);
    ASSERT_TRUE(*it_12 == 6);
    ASSERT_TRUE(*it_22 == 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Minus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    CGM::Matrix<3,3,int>::size_type column = 2;
    auto it_22 = input.endColumn(column) - 1;
    auto it_12 = input.endColumn(column) - 2;
    auto it_02 = input.endColumn(column) - 3;

    ASSERT_TRUE(*it_02 == 3);
    ASSERT_TRUE(*it_12 == 6);
    ASSERT_TRUE(*it_22 == 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PreIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    CGM::Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.beginColumn(column);

    ASSERT_TRUE(*it_02 == 3);
    ASSERT_TRUE(*(++it_02) == 6);
    ASSERT_TRUE(*(++it_02) == 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PostIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    CGM::Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.beginColumn(column);

    ASSERT_TRUE(*(it_02++) == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PreDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    CGM::Matrix<3,3,int>::size_type column = 2;
    auto it_22 = input.endColumn(column);

    ASSERT_TRUE(*(--it_22) == 9);
    ASSERT_TRUE(*(--it_22) == 6);
    ASSERT_TRUE(*(--it_22) == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PostDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    ASSERT_TRUE((input.endColumn(1))-- == input.endColumn(1));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Difference)
{
    CGM::Matrix<3,4,int> input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto a = input.beginColumn(0) + 0;     // (0,0)
    auto b = input.beginColumn(0) + 2;     // (2,0)
    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);

    a = input.beginColumn(0) + 0;          // (0,0)
    b = input.beginColumn(1) + 2;          // (2,1)
    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);

    a = input.beginColumn(0) + 1;          // (1,0)
    b = input.beginColumn(2) + 2;          // (2,2)
    ASSERT_TRUE(a - b == -1);
    ASSERT_TRUE(b - a == 1);
}



/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse)
{
    CGM::Matrix<3,4,int> input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto a = input.rbeginColumn(1) + 0;
    auto b = input.rbeginColumn(1) + 1;
    auto c = input.rbeginColumn(1) + 2;

    ASSERT_TRUE(*a == 8);
    ASSERT_TRUE(*b == 5);
    ASSERT_TRUE(*c == 2);
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_Differece)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginColumn(1);
    auto b = input.rbeginColumn(1) + 1;

    ASSERT_TRUE(a - b == -1);
    ASSERT_TRUE(b - a == 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_RowsColumns_FirstComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginColumn(0) + 2};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_RowsColumns_MidComponent)
{
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbeginColumn(2) + 1};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_RowsColumns_LastComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginColumn(2)};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_ColumnIterator, Exception_Dereference)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PreIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endColumn(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PostIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1)++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PlusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Plus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PreDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginColumn(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PostDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumn(1)--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_MinusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumn(1);
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Minus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumn(1);
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Row)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Column)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get column from matrix iterator (out of range).");
    }
}

#endif