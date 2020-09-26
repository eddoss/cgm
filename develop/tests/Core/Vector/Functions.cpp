

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Core/Types/Vector.hpp>
#include <CGM/detail/Core/Operators/Vector.hpp>
#include <CGM/detail/Core/Functions/Vector.hpp>


using namespace std;
using namespace CGM;

using Vec2 = Vector<2,float>;
using Vec3 = Vector<3,float>;
using Vec4 = Vector<4,float>;
using Vec5 = Vector<5,float>;


TEST(Vector_Functions, Normalize)
{
    {
        Vector<2,double> vec {0.122, 0.728};
        Vector<2,double> nrm {0.165, 0.986};

        {
            auto res = vec;
            auto suc = normalize(res);
            ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = normalized(res, suc);
            ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            normalizeForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.001));
        }

        {
            auto res = vec;
            res = normalizedForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.001));
        }
    }

    /* -------------- */

    {
        Vector<3,double> vec {7.897, 3.119, 3.880};
        Vector<3,double> nrm {0.846, 0.334, 0.416};

        {
            auto res = vec;
            auto suc = normalize(res);
            ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = normalized(res, suc);
            ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            normalizeForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.001));
        }

        {
            auto res = vec;
            res = normalizedForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.001));
        }
    }

    /* -------------- */

    {
        Vector<4,double> vec {4.043, 5.403, 2.650, 8.516};
        Vector<4,double> nrm {0.362, 0.483, 0.237, 0.761};

        {
            auto res = vec;
            auto suc = normalize(res);
            ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = normalized(res, suc);
            ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
        }

        {
            auto res = vec;
            normalizeForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.001));
        }

        {
            auto res = vec;
            res = normalizedForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.001));
        }
    }

    /* -------------- */

    {
        Vector<5,double> vec {1, 5, 6, 0, 0.7};
        Vector<5,double> nrm {0.126, 0.632, 0.759, 0.0, 0.088};

        {
            auto res = vec;
            auto suc = normalize(res);
            ASSERT_TRUE(CGM::eq(res, nrm, 0.01) && suc);
        }

        {
            auto res = vec;
            bool suc = false;
            res = normalized(res, suc);
            ASSERT_TRUE(eq(res, nrm, 0.01) && suc);
        }

        {
            auto res = vec;
            normalizeForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.01));
        }

        {
            auto res = vec;
            res = normalizedForce(res);
            ASSERT_TRUE(eq(res, nrm, 0.01));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Length)
{
    {
        Vec2 vec {2.650f, 4.315f};
        float len = length<float>(vec);
        float exp = 5.064f;

        ASSERT_TRUE(eq(len,exp,0.001f));
    }

    /* -------------- */

    {
        Vec3 vec {1.413f, 4.796f, 6.080f};
        float len = length<float>(vec);
        float exp = 7.872f;

        ASSERT_TRUE(eq(len,exp,0.001f));
    }

    /* -------------- */

    {
        Vec4 vec {9.487f, 9.632f, 1.152f, 1.088f};
        float len = length<float>(vec);
        float exp = 13.612f;

        ASSERT_TRUE(eq(len,exp,0.001f));
    }

    /* -------------- */

    {
        Vec5 vec {9.463f, 1.482f, 1.599f, 5.808f, 6.053f};
        float len = length<float>(vec);
        float exp = 12.833f;

        ASSERT_TRUE(eq(len,exp,0.001f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, LengthSquared)
{
    {
        Vec2 vec {0.095f, 7.089f};

        float len = lengthSquared(vec);
        float exp = 50.267f;

        ASSERT_TRUE(eq(len,exp,0.01f));
    }

    /* -------------- */

    {
        Vec3 vec {8.263f, 6.358f, 7.033f};

        float len = lengthSquared(vec);
        float exp = 158.169f;

        ASSERT_TRUE(eq(len,exp,0.01f));
    }

    /* -------------- */

    {
        Vec4 vec {9.678f, 1.690f, 8.336f, 2.821f};

        float len = lengthSquared(vec);
        float exp = 173.973f;

        ASSERT_TRUE(eq(len,exp,0.01f));
    }

    /* -------------- */

    {
        Vec5 vec {1.303f, 3.797f, 3.249f, 4.522f, 0.889f};

        float len = lengthSquared(vec);
        float exp = 47.912f;

        ASSERT_TRUE(eq(len,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Dot)
{
    {
        Vec2 a {0.064f, 8.342f};
        Vec2 b {3.742f, 0.920f};

        float dtp = dot(a,b);
        float exp = 7.913f;

        ASSERT_TRUE(eq(dtp,exp,0.01f));
    }

    /* -------------- */

    {
        Vec3 a {0.806f, 5.220f, 1.881f};
        Vec3 b {7.542f, 8.957f, 1.825f};

        float dtp = dot(a,b);
        float exp = 56.273f;

        ASSERT_TRUE(eq(dtp,exp,0.01f));
    }

    /* -------------- */

    {
        Vec4 a {6.947f, 6.123f, 8.154f, 3.350f};
        Vec4 b {5.936f, 9.405f, 1.050f, 2.622f};

        float dtp = dot(a,b);
        float exp = 116.179f;

        ASSERT_TRUE(eq(dtp,exp,0.01f));
    }

    /* -------------- */

    {
        Vec5 a {5.407f, 8.000f, 4.504f, 5.900f, 7.249f};
        Vec5 b {8.727f, 8.851f, 0.072f, 4.160f, 2.156f};

        float dtp = dot(a,b);
        float exp = 158.500f;

        ASSERT_TRUE(eq(dtp,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Distance)
{
    {
        Vec2 a {9.713f, 4.845f};
        Vec2 b {3.438f, 8.729f};

        float dst = distance(a,b);
        float exp = 7.380f;

        ASSERT_TRUE(eq(dst,exp,0.01f));
    }

    /* -------------- */

    {
        Vec3 a {4.943f, 1.648f, 3.803f};
        Vec3 b {4.543f, 4.029f, 0.980f};

        float dst = distance(a,b);
        float exp = 3.715f;

        ASSERT_TRUE(eq(dst,exp,0.01f));
    }

    /* -------------- */

    {
        Vec4 a {2.454f, 9.338f, 6.662f, 8.235f};
        Vec4 b {6.854f, 1.563f, 8.425f, 5.790f};

        float dst = distance(a,b);
        float exp = 9.429f;

        ASSERT_TRUE(eq(dst,exp,0.01f));
    }

    /* -------------- */

    {
        Vec5 a {3.961f, 4.584f, 3.928f, 1.790f, 0.999f};
        Vec5 b {9.414f, 4.900f, 4.636f, 7.628f, 1.956f};

        float dst = distance(a,b);
        float exp = 8.083f;

        ASSERT_TRUE(eq(dst,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Angle)
{
    {
        Vec2 a {0.258f, 0.966f};
        Vec2 b {0.688f, 0.726f};

        float ang = angle<float>(a,b);
        float exp = 0.497f;

        ASSERT_TRUE(eq(ang,exp,0.01f));
    }

    /* -------------- */

    {
        Vec3 a {0.825f, 0.153f, 0.544f};
        Vec3 b {0.076f, 0.906f, 0.417f};

        float ang = angle<float>(a,b);
        float exp = 1.128f;

        ASSERT_TRUE(eq(ang,exp,0.01f));
    }

    /* -------------- */

    {
        Vec4 a {0.522f, 0.526f, 0.224f, 0.632f};
        Vec4 b {0.534f, 0.617f, 0.554f, 0.164f};

        float ang = angle<float>(a,b);
        float exp = 0.589f;

        ASSERT_TRUE(eq(ang,exp,0.01f));
    }

    /* -------------- */

    {
        Vec5 a {0.519f, 0.546f, 0.514f, 0.093f, 0.399f};
        Vec5 b {0.386f, 0.363f, 0.702f, 0.476f, 0.001f};

        float ang = angle<float>(a,b);
        float exp = 0.637f;

        ASSERT_TRUE(eq(ang,exp,0.01f));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Functions, Cross)
{
    Vector<3,int> x {1,0,0};
    Vector<3,int> y {0,1,0};
    Vector<3,int> z {0,0,1};

#ifdef CGM_LEFT_HANDED
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