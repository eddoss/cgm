

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Core/Functions/Matrix.hpp>


using namespace std;


TEST(Matrix_Functions, Transpose)
{
    {
        CGM::Matrix<2,2,int> a
        {
            1, 2,
            3, 4
        };
        CGM::Matrix<2,2,int> b
        {
            1, 3,
            2, 4
        };

        transpose(a);

        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };
        CGM::Matrix<3,3,int> b
        {
            1, 4, 6,
            2, 3, 7,
            3, 2, 3
        };

        transpose(a);

        ASSERT_TRUE(a == b);
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
            1, 3, 3, 1,
            2, 2, 4, 2,
            3, 1, 3, 3,
            4, 2, 2, 4
        };

        transpose(a);

        ASSERT_TRUE(a == b);
    }

   /* -------------- */

    {
        CGM::Matrix<5,5,int> a
        {
            1, 2, 2, 3, 4,
            1, 3, 2, 3, 4,
            2, 0, 1, 7, 4,
            3, 2, 2, 9, 4,
            1, 3, 3, 0, 1
        };
        CGM::Matrix<5,5,int> b
        {
            1, 1, 2, 3, 1,
            2, 3, 0, 2, 3,
            2, 2, 1, 2, 3,
            3, 3, 7, 9, 0,
            4, 4, 4, 4, 1
        };

        transpose(a);

        ASSERT_TRUE(a == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Transposed)
{
    {
        CGM::Matrix<1,2,int> a
        {
            1, 2
        };
        CGM::Matrix<2,1,int> b
        {
            1,
            2
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,3,int> a
        {
            1, 2, 3
        };
        CGM::Matrix<3,1,int> b
        {
            1,
            2,
            3
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<1,4,int> a
        {
            1, 2, 3, 4
        };
        CGM::Matrix<4,1,int> b
        {
            1,
            2,
            3,
            4
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,1,int> a
        {
            1,
            2
        };
        CGM::Matrix<1,2,int> b
        {
            1,2
        };

        ASSERT_TRUE(transposed(a) == b);
    }

        /* -------------- */

    {
        CGM::Matrix<3,1,int> a
        {
            1,
            2,
            3
        };
        CGM::Matrix<1,3,int> b
        {
            1, 2, 3
        };

        ASSERT_TRUE(transposed(a) == b);
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
        CGM::Matrix<1,4,int> b
        {
            1,2,3,4
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,3,int> a
        {
            3, 5, 1,
            8, 4, 7
        };
        CGM::Matrix<3,2,int> b
        {
            3, 8,
            5, 4,
            1, 7
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<2,4,int> a
        {
            1, 2, 3, 5,
            4, 3, 2, 8
        };
        CGM::Matrix<4,2,int> b
        {
            1, 4,
            2, 3,
            3, 2,
            5, 8
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,2,int> a
        {
            1, 2,
            3, 4,
            3, 2
        };
        CGM::Matrix<2,3,int> b
        {
            1, 3, 3,
            2, 4, 2
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,4,int> a
        {
            1, 2, 5, 4,
            4, 8, 2, 1,
            2, 9, 2, 5
        };
        CGM::Matrix<4,3,int> b
        {
            1, 4, 2,
            2, 8, 9,
            5, 2, 2,
            4, 1, 5
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,2,int> a
        {
            1, 2,
            5, 4,
            4, 8,
            2, 1
        };
        CGM::Matrix<2,4,int> b
        {
            1, 5, 4, 2,
            2, 4, 8, 1
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,3,int> a
        {
            1, 2, 2,
            3, 4, 3,
            3, 2, 1,
            7, 2, 8
        };
        CGM::Matrix<3,4,int> b
        {
            1, 3, 3, 7,
            2, 4, 2, 2,
            2, 3, 1, 8
        };

        ASSERT_TRUE(transposed(a) == b);
    }


    /* -------------- */

    {
        CGM::Matrix<4,5,int> a
        {
            1,2,2,7,8,
            3,4,3,4,9,
            3,2,1,3,1,
            7,2,8,7,8
        };
        CGM::Matrix<5,4,int> b
        {
            1,3,3,7,
            2,4,2,2,
            2,3,1,8,
            7,4,3,7,
            8,9,1,8
        };

        ASSERT_TRUE(transposed(a) == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Determinant)
{
    {
        CGM::Matrix<2,2,int> a
        {
            1, 2,
            3, 4
        };

        ASSERT_TRUE(determinant(a) == -2);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };

        ASSERT_TRUE(determinant(a) == 25);
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

        ASSERT_TRUE(determinant(a) == 0);
    }

//   /* -------------- */
//
//    {
//        CGM::Matrix<5,5,int> a
//        {
//            1, 2, 2, 3, 4,
//            1, 3, 2, 3, 4,
//            2, 0, 1, 7, 4,
//            3, 2, 2, 9, 4,
//            1, 3, 3, 0, 1
//        };
//
//        ASSERT_TRUE(determinant(a), 4);
//    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Cofactors)
{
    {
        CGM::Matrix<2,2,int> a
        {
            1, 2,
            3, 4
        };
        CGM::Matrix<2,2,int> b
        {
            4, -3,
            -2, 1
        };

        ASSERT_TRUE(cofactors(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> a
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };
        CGM::Matrix<3,3,int> b
        {
            -5, 0, 10,
            15, -15, 5,
            -5, 10, -5
        };

        ASSERT_TRUE(cofactors(a) == b);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> a
        {
            2,8,1,7,
            5,3,5,9,
            0,2,1,6,
            4,8,3,2
        };
        CGM::Matrix<4,4,int> b
        {
            154,-4,-220,38,
            98,-36,-48,20,
            -287,43,272,-6,
            -119,47,170,-44
        };

        ASSERT_TRUE(cofactors(a) == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Inverse)
{
    {
        CGM::Matrix<2,2,double> mat
        {
            1, 2,
            3, 4
        };

        CGM::Matrix<2,2,double> inv
        {
            -2, 1,
            1.5, -0.5
        };

        {
            auto res = mat;
            bool suc = invertSafe(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            bool suc = false;
            res = inverseSafe(res, suc);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            invert(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001));
        }

        {
            auto res = mat;
            res = inverse(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001));
        }
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,double> mat
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };

        CGM::Matrix<3,3,double> inv
        {
            -0.2, 0.6, -0.2,
            0, -0.6, 0.4,
            0.4, 0.2, -0.2
        };

        {
            auto res = mat;
            bool suc = invertSafe(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            bool suc = false;
            res = inverseSafe(res, suc);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            invert(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001));
        }

        {
            auto res = mat;
            res = inverse(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001));
        }
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,double> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 2
        };
        CGM::Matrix<4,4,double> inv
        {
            -0.5, 0.75, -0.5, 0.75,
            0.5, -0.75, 1.0, -1.25,
            -0.5, 0.25, -0.5, 1.25,
            0.5, 0.0, 0.0f, -0.5
        };

        {
            auto res = mat;
            bool suc = invertSafe(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            bool suc = false;
            res = inverseSafe(res, suc);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            invert(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001));
        }

        {
            auto res = mat;
            res = inverse(res);
            ASSERT_TRUE(CGM::eq(res, inv, 0.001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Trace)
{
    {
        CGM::Matrix<2,2,int> mat
        {
            2, 0,
            0, 3
        };

        ASSERT_TRUE(trace(mat) == 5);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> mat
        {
            2, 0, 0,
            0, 3, 0,
            0, 0, 1
        };

        ASSERT_TRUE(trace(mat) == 6);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 4
        };

        ASSERT_TRUE(trace(mat) == 8);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> mat
        {
            1, 0, 0, 0, 0,
            0, 2, 0, 0, 0,
            0, 0, 4, 0, 0,
            0, 0, 0, 5, 0,
            0, 0, 0, 0, 1
        };

        ASSERT_TRUE(trace(mat) == 13);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Symmetric)
{
    {
        CGM::Matrix<2,2,int> mat
        {
            1, 2,
            2, 1
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1,2,
            3,4
        };

        ASSERT_FALSE(symmetric(mat));
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> mat
        {
            1, 2, 3,
            2, 1, 0,
            3, 0, 3
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1, 2, 3,
            2, 1, 2,
            3, 5, 3
        };

        ASSERT_FALSE(symmetric(mat));
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> mat
        {
            1, 2, 3, 4,
            2, 1, 0, 2,
            3, 0, 3, 2,
            4, 2, 2, 3
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1, 2, 3, 4,
            4, 1, 0, 2,
            3, 0, 3, 2,
            4, 2, 2, 3
        };

        ASSERT_FALSE(symmetric(mat));
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> mat
        {
            1, 2, 3, 4, 2,
            2, 1, 0, 2, 3,
            3, 0, 3, 2, 5,
            4, 2, 2, 3, 2,
            2, 3, 5, 2, 2
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1, 2, 3, 4, 2,
            2, 1, 0, 2, 3,
            3, 4, 3, 2, 5,
            4, 2, 2, 3, 2,
            2, 3, 5, 2, 2
        };

        ASSERT_FALSE(symmetric(mat));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Antisymmetric)
{
    CGM::Matrix<3,3,int> mat
    {
        0, -2, 4,
        2, 0, -3,
        -4, 3, 0
    };

    ASSERT_TRUE(antisymmetric(mat));

    mat =
    {
        1, 2, 3,
        2, 1, 0,
        3, 0, 4
    };

    ASSERT_FALSE(antisymmetric(mat));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Diagonal)
{
    {
        CGM::Matrix<2,2,int> mat
        {
            3, 0,
            0, 2
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(CGM::Matrix<2,2,int>(2)));
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> mat
        {
            2, 0, 0,
            0, 2, 0,
            0, 0, 4
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(CGM::Matrix<3,3,int>(2)));
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> mat
        {
            2, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 2, 0,
            0, 0, 0, 1
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(CGM::Matrix<4,4,int>(2)));
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> mat
        {
            4, 0, 0, 0, 0,
            0, 5, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 0, 1
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(CGM::Matrix<5,5,int>(2)));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Orthogonal)
{
    {
        CGM::Matrix<2,2,double> mat
        {
            0.958072, -0.286529,
            0.286529, 0.958072
        };

        ASSERT_TRUE(orthogonal(mat, 0.0001));
        ASSERT_FALSE(orthogonal(CGM::Matrix<2,2,double>(2.0), 0.0001));
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,double> mat
        {
            0.589794, -0.57689, 0.565102,
            0.180624, 0.776281, 0.603956,
            -0.787094, -0.254139, 0.562046
        };

        ASSERT_TRUE(orthogonal(mat, 0.0001));
        ASSERT_FALSE(orthogonal(CGM::Matrix<2,2,double>(2.0), 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Identity)
{
    {
        CGM::Matrix<2,2,int> ident
        {
            1, 0,
            0, 1
        };

        auto exp = cgm::identity<2,int>();

        ASSERT_TRUE(exp == ident);
    }

    /* -------------- */

    {
        CGM::Matrix<3,3,int> ident
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };

        auto exp = cgm::identity<3,int>();

        ASSERT_TRUE(exp == ident);
    }

    /* -------------- */

    {
        CGM::Matrix<4,4,int> ident
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        auto exp = cgm::identity<4,int>();

        ASSERT_TRUE(exp == ident);
    }

    /* -------------- */

    {
        CGM::Matrix<5,5,int> ident
        {
            1, 0, 0, 0, 0,
            0, 1, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 0, 1
        };

        auto exp = cgm::identity<5,int>();

        ASSERT_TRUE(exp == ident);
    }
}
