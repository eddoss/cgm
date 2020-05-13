

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Operators/Vector.hpp>


using namespace MATH3D_NAMESPACE;
using namespace std;

using Vec2 = Vector<2,int>;
using Vec3 = Vector<3,int>;
using Vec4 = Vector<4,int>;
using Vec5 = Vector<5,int>;

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
using Mat52 = Matrix<5,2,int>;
using Mat53 = Matrix<5,3,int>;
using Mat54 = Matrix<5,4,int>;
using Mat55 = Matrix<5,5,int>;

/* ####################################################################################### */
/* Vector to matrix: 2D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat21)
{
    Vec2 vec = {2,5};
    Mat21 mat
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
    Vec2 vec = {2,5};
    Mat22 mat
    {
        3,2,
        4,6
    };

    auto trs = transposed(mat);
    auto exp = Vec2(26,34);

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat23)
{
    Vec2 vec = {2,5};
    Mat23 mat
    {
        3,2,1,
        4,6,3
    };

    auto trs = transposed(mat);
    auto exp = Vec3(26,34,17);

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat24)
{
    Vec2 vec = {2,5};
    Mat24 mat
    {
        3,2,1,5,
        4,6,3,4
    };

    auto trs = transposed(mat);
    auto exp = Vec4(26,34,17,30);

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__Mat25)
{
    Vec2 vec = {2,5};
    Mat25 mat
    {
        3,2,1,5,1,
        4,6,3,4,1
    };

    auto trs = transposed(mat);
    auto exp = Vec5 {26,34,17,30,7};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* ####################################################################################### */
/* Vector to matrix: 3D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat31)
{
    Vec3 vec = {2,5,4};
    Mat31 mat
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
    Vec3 vec = {2,5,4};
    Mat32 mat
    {
        3,2,
        4,6,
        2,1
    };

    auto trs = transposed(mat);
    auto exp = Vec2 {34,38};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat33)
{
    Vec3 vec = {2,5,4};
    Mat33 mat
    {
        3,2,1,
        4,6,3,
        2,1,4
    };

    auto trs = transposed(mat);
    auto exp = Vec3 {34,38,33};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat34)
{
    Vec3 vec = {2,5,4};
    Mat34 mat
    {
        3,2,1,5,
        4,6,3,4,
        2,1,4,4
    };

    auto trs = transposed(mat);
    auto exp = Vec4 {34,38,33,46};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__Mat35)
{
    Vec3 vec = {2,5,4};
    Mat35 mat
    {
        3,2,1,5,1,
        4,6,3,4,1,
        2,1,4,4,3
    };

    auto trs = transposed(mat);
    auto exp = Vec5 {34,38,33,46,19};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* ####################################################################################### */
/* Vector to matrix: 4D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat41)
{
    Vec4 vec = {2,5,4,3};
    Mat41 mat
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
    Vec4 vec = {2,5,4,3};
    Mat42 mat
    {
        3,2,
        4,6,
        2,1,
        3,6
    };

    auto trs = transposed(mat);
    auto exp = Vec2 {43,56};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat43)
{
    Vec4 vec = {2,5,4,3};
    Mat43 mat
    {
        3,2,1,
        4,6,3,
        2,1,4,
        3,6,1
    };

    auto trs = transposed(mat);
    auto exp = Vec3 {43,56,36};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat44)
{
    Vec4 vec = {2,5,4,3};
    Mat44 mat
    {
        3,2,1,5,
        4,6,3,4,
        2,1,4,4,
        3,6,1,2
    };

    auto trs = transposed(mat);
    auto exp = Vec4 {43,56,36,52};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__Mat45)
{
    Vec4 vec = {2,5,4,3};
    Mat45 mat
    {
        3,2,1,5,1,
        4,6,3,4,1,
        2,1,4,4,3,
        3,6,1,2,3
    };

    auto trs = transposed(mat);
    auto exp = Vec5 {43,56,36,52,28};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* ####################################################################################### */
/* Vector to matrix: 4+D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat51)
{
    Vec5 vec = {2,5,4,3,1};
    Mat51 mat
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
    Vec5 vec = {2,5,4,3,1};
    Mat52 mat
    {
        3,2,
        4,6,
        2,1,
        3,6,
        1,1
    };

    auto trs = transposed(mat);
    auto exp = Vec2 {44,57};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat53)
{
    Vec5 vec = {2,5,4,3,1};
    Mat53 mat
    {
        3,2,1,
        4,6,3,
        2,1,4,
        3,6,1,
        1,1,1
    };

    auto trs = transposed(mat);
    auto exp = Vec3 {44,57,37};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat54)
{
    Vec5 vec = {2,5,4,3,1};
    Mat54 mat
    {
        3,2,1,5,
        4,6,3,4,
        2,1,4,4,
        3,6,1,2,
        1,1,1,1
    };

    auto trs = transposed(mat);
    auto exp = Vec4 {44,57,37,53};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__Mat55)
{
    Vec5 vec = {2,5,4,3,1};
    Mat55 mat
    {
        3,2,1,5,1,
        4,6,3,4,1,
        2,1,4,4,3,
        3,6,1,2,3,
        1,1,1,1,1
    };

    auto trs = transposed(mat);
    auto exp = Vec5 {44,57,37,53,29};

    ASSERT_TRUE((vec*mat) == exp);
    ASSERT_TRUE((trs*vec) == exp);
}