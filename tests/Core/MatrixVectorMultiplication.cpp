

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>


/* ####################################################################################### */
/* Vector to matrix: 2D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat21)
{
    CGM::Vector<2,int> vec = {2,5};
    CGM::Matrix<2,1,int> mat
    {
        3,
        4
    };

    auto trs = transposed(mat);
    auto exp = 26;

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat22)
{
    CGM::Vector<2,int> vec = {2,5};
    CGM::Matrix<2,2,int> mat
    {
        3,2,
        4,6
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<2,int>(26,34);

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat23)
{
    CGM::Vector<2,int> vec = {2,5};
    CGM::Matrix<2,3,int> mat
    {
        3,2,1,
        4,6,3
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<3,int>(26,34,17);

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat24)
{
    CGM::Vector<2,int> vec = {2,5};
    CGM::Matrix<2,4,int> mat
    {
        3,2,1,5,
        4,6,3,4
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<4,int>(26,34,17,30);

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat25)
{
    CGM::Vector<2,int> vec = {2,5};
    CGM::Matrix<2,5,int> mat
    {
        3,2,1,5,1,
        4,6,3,4,1
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<5,int> {26,34,17,30,7};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* ####################################################################################### */
/* Vector to matrix: 3D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat31)
{
    CGM::Vector<3,int> vec = {2,5,4};
    CGM::Matrix<3,1,int> mat
    {
        3,
        4,
        2
    };

    auto trs = transposed(mat);
    auto exp = 34;

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat32)
{
    CGM::Vector<3,int> vec = {2,5,4};
    CGM::Matrix<3,2,int> mat
    {
        3,2,
        4,6,
        2,1
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<2,int> {34,38};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat33)
{
    CGM::Vector<3,int> vec = {2,5,4};
    CGM::Matrix<3,3,int> mat
    {
        3,2,1,
        4,6,3,
        2,1,4
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<3,int> {34,38,33};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat34)
{
    CGM::Vector<3,int> vec = {2,5,4};
    CGM::Matrix<3,4,int> mat
    {
        3,2,1,5,
        4,6,3,4,
        2,1,4,4
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<4,int> {34,38,33,46};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat35)
{
    CGM::Vector<3,int> vec = {2,5,4};
    CGM::Matrix<3,5,int> mat
    {
        3,2,1,5,1,
        4,6,3,4,1,
        2,1,4,4,3
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<5,int> {34,38,33,46,19};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* ####################################################################################### */
/* Vector to matrix: 4D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat41)
{
    CGM::Vector<4,int> vec = {2,5,4,3};
    CGM::Matrix<4,1,int> mat
    {
        3,
        4,
        2,
        3
    };

    auto trs = transposed(mat);
    auto exp = 43;

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat42)
{
    CGM::Vector<4,int> vec = {2,5,4,3};
    CGM::Matrix<4,2,int> mat
    {
        3,2,
        4,6,
        2,1,
        3,6
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<2,int> {43,56};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat43)
{
    CGM::Vector<4,int> vec = {2,5,4,3};
    CGM::Matrix<4,3,int> mat
    {
        3,2,1,
        4,6,3,
        2,1,4,
        3,6,1
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<3,int> {43,56,36};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat44)
{
    CGM::Vector<4,int> vec = {2,5,4,3};
    CGM::Matrix<4,4,int> mat
    {
        3,2,1,5,
        4,6,3,4,
        2,1,4,4,
        3,6,1,2
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<4,int> {43,56,36,52};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat45)
{
    CGM::Vector<4,int> vec = {2,5,4,3};
    CGM::Matrix<4,5,int> mat
    {
        3,2,1,5,1,
        4,6,3,4,1,
        2,1,4,4,3,
        3,6,1,2,3
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<5,int> {43,56,36,52,28};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* ####################################################################################### */
/* Vector to matrix: 4+D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat51)
{
    CGM::Vector<5,int> vec = {2,5,4,3,1};
    CGM::Matrix<5,1,int> mat
    {
        3,
        4,
        2,
        3,
        1
    };

    auto trs = transposed(mat);
    auto exp = 44;

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat52)
{
    CGM::Vector<5,int> vec = {2,5,4,3,1};
    CGM::Matrix<5,2,int> mat
    {
        3,2,
        4,6,
        2,1,
        3,6,
        1,1
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<2,int> {44,57};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat53)
{
    CGM::Vector<5,int> vec = {2,5,4,3,1};
    CGM::Matrix<5,3,int> mat
    {
        3,2,1,
        4,6,3,
        2,1,4,
        3,6,1,
        1,1,1
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<3,int> {44,57,37};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat54)
{
    CGM::Vector<5,int> vec = {2,5,4,3,1};
    CGM::Matrix<5,4,int> mat
    {
        3,2,1,5,
        4,6,3,4,
        2,1,4,4,
        3,6,1,2,
        1,1,1,1
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<4,int> {44,57,37,53};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat55)
{
    CGM::Vector<5,int> vec = {2,5,4,3,1};
    CGM::Matrix<5,5,int> mat
    {
        3,2,1,5,1,
        4,6,3,4,1,
        2,1,4,4,3,
        3,6,1,2,3,
        1,1,1,1,1
    };

    auto trs = transposed(mat);
    auto exp = CGM::Vector<5,int> {44,57,37,53,29};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}