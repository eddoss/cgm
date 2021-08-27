

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>


using namespace std;


TEST(Vector_Functions, Normalize)
{
    {
        CGM::Vector<2,double> vec {0.122, 0.728};
        CGM::Vector<2,double> nrm {0.165, 0.986};

        {
            auto res = vec;
            auto suc = CGM::normalizeSafe(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = CGM::normalizedSafe(res, suc);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            CGM::normalize(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001));
        }

        {
            auto res = vec;
            res = CGM::normalized(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001));
        }
    }

    /* -------------- */

    {
        CGM::Vector<3,double> vec {7.897, 3.119, 3.880};
        CGM::Vector<3,double> nrm {0.846, 0.334, 0.416};

        {
            auto res = vec;
            auto suc = CGM::normalizeSafe(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = CGM::normalizedSafe(res, suc);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            CGM::normalize(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001));
        }

        {
            auto res = vec;
            res = CGM::normalized(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001));
        }
    }

    /* -------------- */

    {
        CGM::Vector<4,double> vec {4.043, 5.403, 2.650, 8.516};
        CGM::Vector<4,double> nrm {0.362, 0.483, 0.237, 0.761};

        {
            auto res = vec;
            auto suc = CGM::normalizeSafe(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = CGM::normalizedSafe(res, suc);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            CGM::normalize(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001));
        }

        {
            auto res = vec;
            res = CGM::normalized(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.001));
        }
    }

    /* -------------- */

    {
        CGM::Vector<5,double> vec {1, 5, 6, 0, 0.7};
        CGM::Vector<5,double> nrm {0.126, 0.632, 0.759, 0.0, 0.088};

        {
            auto res = vec;
            auto suc = CGM::normalizeSafe(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.01) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = CGM::normalizedSafe(res, suc);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.01) && suc);
        }

        {
            auto res = vec;
            CGM::normalize(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.01));
        }

        {
            auto res = vec;
            res = CGM::normalized(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.01));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Length)
{
    {
        CGM::Vector<2,float> vec {2.650f, 4.315f};
        float len = CGM::length(vec);
        float exp = 5.064f;

        ASSERT_TRUE(CGM::eq(len,exp,0.001f));
    }

    /* -------------- */

    {
        CGM::Vector<3,float> vec {1.413f, 4.796f, 6.080f};
        float len = CGM::length(vec);
        float exp = 7.872f;

        ASSERT_TRUE(CGM::eq(len,exp,0.001f));
    }

    /* -------------- */

    {
        CGM::Vector<4,float> vec {9.487f, 9.632f, 1.152f, 1.088f};
        float len = CGM::length(vec);
        float exp = 13.612f;

        ASSERT_TRUE(CGM::eq(len,exp,0.001f));
    }

    /* -------------- */

    {
        CGM::Vector<5,float> vec {9.463f, 1.482f, 1.599f, 5.808f, 6.053f};
        float len = CGM::length(vec);
        float exp = 12.833f;

        ASSERT_TRUE(CGM::eq(len,exp,0.001f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, LengthSquared)
{
    {
        CGM::Vector<2,float> vec {0.095f, 7.089f};

        float len = CGM::lengthSquared(vec);
        float exp = 50.267f;

        ASSERT_TRUE(CGM::eq(len,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<3,float> vec {8.263f, 6.358f, 7.033f};

        float len = CGM::lengthSquared(vec);
        float exp = 158.169f;

        ASSERT_TRUE(CGM::eq(len,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<4,float> vec {9.678f, 1.690f, 8.336f, 2.821f};

        float len = CGM::lengthSquared(vec);
        float exp = 173.973f;

        ASSERT_TRUE(CGM::eq(len,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<5,float> vec {1.303f, 3.797f, 3.249f, 4.522f, 0.889f};

        float len = CGM::lengthSquared(vec);
        float exp = 47.912f;

        ASSERT_TRUE(CGM::eq(len,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Dot)
{
    {
        CGM::Vector<2,float> a {0.064f, 8.342f};
        CGM::Vector<2,float> b {3.742f, 0.920f};

        float dtp = CGM::dot(a,b);
        float exp = 7.913f;

        ASSERT_TRUE(CGM::eq(dtp,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<3,float> a {0.806f, 5.220f, 1.881f};
        CGM::Vector<3,float> b {7.542f, 8.957f, 1.825f};

        float dtp = CGM::dot(a,b);
        float exp = 56.273f;

        ASSERT_TRUE(CGM::eq(dtp,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<4,float> a {6.947f, 6.123f, 8.154f, 3.350f};
        CGM::Vector<4,float> b {5.936f, 9.405f, 1.050f, 2.622f};

        float dtp = CGM::dot(a,b);
        float exp = 116.179f;

        ASSERT_TRUE(CGM::eq(dtp,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<5,float> a {5.407f, 8.000f, 4.504f, 5.900f, 7.249f};
        CGM::Vector<5,float> b {8.727f, 8.851f, 0.072f, 4.160f, 2.156f};

        float dtp = CGM::dot(a,b);
        float exp = 158.500f;

        ASSERT_TRUE(CGM::eq(dtp,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Distance)
{
    {
        CGM::Vector<2,float> a {9.713f, 4.845f};
        CGM::Vector<2,float> b {3.438f, 8.729f};

        float dst = CGM::distance(a,b);
        float exp = 7.380f;

        ASSERT_TRUE(CGM::eq(dst,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<3,float> a {4.943f, 1.648f, 3.803f};
        CGM::Vector<3,float> b {4.543f, 4.029f, 0.980f};

        float dst = CGM::distance(a,b);
        float exp = 3.715f;

        ASSERT_TRUE(CGM::eq(dst,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<4,float> a {2.454f, 9.338f, 6.662f, 8.235f};
        CGM::Vector<4,float> b {6.854f, 1.563f, 8.425f, 5.790f};

        float dst = CGM::distance(a,b);
        float exp = 9.429f;

        ASSERT_TRUE(CGM::eq(dst,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<5,float> a {3.961f, 4.584f, 3.928f, 1.790f, 0.999f};
        CGM::Vector<5,float> b {9.414f, 4.900f, 4.636f, 7.628f, 1.956f};

        float dst = CGM::distance(a,b);
        float exp = 8.083f;

        ASSERT_TRUE(CGM::eq(dst,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Angle)
{
    {
        CGM::Vector<2,float> a {0.258f, 0.966f};
        CGM::Vector<2,float> b {0.688f, 0.726f};

        float ang = CGM::angle(a,b);
        float exp = 0.497f;

        ASSERT_TRUE(CGM::eq(ang,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<3,float> a {0.825f, 0.153f, 0.544f};
        CGM::Vector<3,float> b {0.076f, 0.906f, 0.417f};

        float ang = CGM::angle(a,b);
        float exp = 1.128f;

        ASSERT_TRUE(CGM::eq(ang,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<4,float> a {0.522f, 0.526f, 0.224f, 0.632f};
        CGM::Vector<4,float> b {0.534f, 0.617f, 0.554f, 0.164f};

        float ang = CGM::angle(a,b);
        float exp = 0.589f;

        ASSERT_TRUE(CGM::eq(ang,exp,0.01f));
    }

    /* -------------- */

    {
        CGM::Vector<5,float> a {0.519f, 0.546f, 0.514f, 0.093f, 0.399f};
        CGM::Vector<5,float> b {0.386f, 0.363f, 0.702f, 0.476f, 0.001f};

        float ang = CGM::angle(a,b);
        float exp = 0.637f;

        ASSERT_TRUE(CGM::eq(ang,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Cross)
{
    CGM::Vector<3,int> x {1,0,0};
    CGM::Vector<3,int> y {0,1,0};
    CGM::Vector<3,int> z {0,0,1};

#ifdef CGM_CFG_LHS
    ASSERT_TRUE(cross(x,y) == -z);
    ASSERT_TRUE(cross(y,z) == -x);
    ASSERT_TRUE(cross(z,x) == -y);

    ASSERT_TRUE(cross(y,x) == z);
    ASSERT_TRUE(cross(z,y) == x);
    ASSERT_TRUE(cross(x,z) == y);
#else
    ASSERT_TRUE(cross(x,y) == z);
    ASSERT_TRUE(cross(y,z) == x);
    ASSERT_TRUE(cross(z,x) == y);

    ASSERT_TRUE(cross(y,x) == -z);
    ASSERT_TRUE(cross(z,y) == -x);
    ASSERT_TRUE(cross(x,z) == -y);
#endif
}