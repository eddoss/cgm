

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Matrix.hpp>


using namespace std;

TEST(Matrix_RowIterator, Plus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_02 = input.beginRow(0) + 2;
    auto it_12 = input.beginRow(1) + 2;
    auto it_22 = input.beginRow(2) + 2;

    ASSERT_TRUE(*it_02 == 3);
    ASSERT_TRUE(*it_12 == 6);
    ASSERT_TRUE(*it_22 == 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Minus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    auto it_01 = input.endRow(0) - 1;
    auto it_10 = input.endRow(1) - 2;
    auto it_20 = input.endRow(2) - 2;

    ASSERT_TRUE(*it_01 == 2);
    ASSERT_TRUE(*it_10 == 4);
    ASSERT_TRUE(*it_20 == 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PreIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRow(1);

    ASSERT_TRUE(*it == 4);
    ASSERT_TRUE(*(++it) == 5);
    ASSERT_TRUE(*(++it) == 6);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PostIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRow(0);

    ASSERT_TRUE(*(it++) == 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PreDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    auto it = input.endRow(2);

    ASSERT_TRUE(*(--it) == 8);
    ASSERT_TRUE(*(--it) == 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PostDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    ASSERT_TRUE((input.endRow(1))-- == input.endRow(1));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Difference)
{
    CGM::Matrix<3,4,int> input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto a = input.beginRow(0) + 0;     // (0,0)
    auto b = input.beginRow(0) + 2;     // (0,2)
    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);

    a = input.beginRow(0) + 0;          // (0,0)
    b = input.beginRow(1) + 3;          // (1,3)
    ASSERT_TRUE(a - b == -3);
    ASSERT_TRUE(b - a == 3);

    a = input.beginRow(0) + 1;          // (0,1)
    b = input.beginRow(2) + 3;          // (2,3)
    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse)
{
    CGM::Matrix<3,4,int> input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto it_00 = input.rbeginRow(1) + 3;
    auto it_01 = input.rbeginRow(1) + 2;
    auto it_02 = input.rbeginRow(1) + 1;
    auto it_03 = input.rbeginRow(1);

    ASSERT_TRUE(*it_00 == 4);
    ASSERT_TRUE(*it_01 == 5);
    ASSERT_TRUE(*it_02 == 6);
    ASSERT_TRUE(*it_03 == 8);
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_Differece)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginRow(1);
    auto b = input.rbeginRow(1) + 1;

    ASSERT_TRUE(a - b == -1);
    ASSERT_TRUE(b - a == 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_RowsColumns_FirstComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginRow(2) + 2};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_RowsColumns_MidComponent)
{
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbeginRow(1) + 2};

    ASSERT_TRUE(it.row() == 1);
    ASSERT_TRUE(it.column() == 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_RowsColumns_LastComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginRow(2)};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_RowIterator, Exception_Dereference)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PreIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endRow(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PostIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1)++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PlusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Plus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PreDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginRow(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PostDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRow(1)--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_MinusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRow(1);
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Minus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRow(1);
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Row)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Column)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get column from matrix iterator (out of range).");
    }
}

#endif