

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Quaternion/Functions.hpp>


using namespace MATH3D_NAMESPACE;

using namespace std;

TEST(Quaternion_Functions, Dot)
{
    Quaternion<float> a {6.947f, 6.123f, 8.154f, 3.350f};
    Quaternion<float> b {5.936f, 9.405f, 1.050f, 2.622f};

    float dtp = dot(a,b);
    float exp = 116.179f;

    ASSERT_TRUE(equal(dtp,exp,0.01f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Conjugate)
{
    Quaternion<float> a {6.f, 5.f, 8.f, 3.f};
    Quaternion<float> b {6.f, -5.f, -8.f, -3.f};

    ASSERT_TRUE(conjugate(a) == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Conjugated)
{
    Quaternion<float> a {6.f, 5.f, 8.f, 3.f};
    Quaternion<float> b {6.f, -5.f, -8.f, -3.f};

    ASSERT_TRUE(conjugated(a) == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Length)
{
    Quaternion<float> q {9.487f, 9.632f, 1.152f, 1.088f};
    float len = length(q);
    float exp = 13.612f;

    ASSERT_TRUE(equal(len,exp,0.001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Norm)
{
    Quaternion<float> q {9.678f, 1.690f, 8.336f, 2.821f};

    float len = norm(q);
    float exp = 173.973f;

    ASSERT_TRUE(equal(len,exp,0.01f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Normalize)
{
    Quaternion<float> qat {4.043f, 5.403f, 2.650f, 8.516f};
    Quaternion<float> nrm {0.362f, 0.483f, 0.237f, 0.761f};

    normalize(qat);

    ASSERT_TRUE(equal(qat.s,nrm.s,0.001f));
    ASSERT_TRUE(equal(qat.x, nrm.x, 0.001f));
    ASSERT_TRUE(equal(qat.y, nrm.y, 0.001f));
    ASSERT_TRUE(equal(qat.z, nrm.z, 0.001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Normalized)
{
    Quaternion<float> qat {4.043f, 5.403f, 2.650f, 8.516f};
    Quaternion<float> nrm {0.362f, 0.483f, 0.237f, 0.761f};

    qat = normalized(qat);

    ASSERT_TRUE(equal(qat.s,nrm.s,0.001f));
    ASSERT_TRUE(equal(qat.x, nrm.x, 0.001f));
    ASSERT_TRUE(equal(qat.y, nrm.y, 0.001f));
    ASSERT_TRUE(equal(qat.z, nrm.z, 0.001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Invert)
{
    Quaternion<double> qat {1.22, 4.34, 5.11, 12.7};
    Quaternion<double> inv {0.0058731,-0.0208929,-0.0245997,-0.0611382};

    invert(qat);

    ASSERT_TRUE(equal(qat.s,inv.s,0.001));
    ASSERT_TRUE(equal(qat.x, inv.x, 0.001));
    ASSERT_TRUE(equal(qat.y, inv.y, 0.001));
    ASSERT_TRUE(equal(qat.z, inv.z, 0.001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Inverted)
{
    Quaternion<double> qat {1.22, 4.34, 5.11, 12.7};
    Quaternion<double> inv {0.0058731,-0.0208929,-0.0245997,-0.0611382};

    qat = inverted(qat);

    ASSERT_TRUE(equal(qat.s,inv.s,0.001));
    ASSERT_TRUE(equal(qat.x, inv.x, 0.001));
    ASSERT_TRUE(equal(qat.y, inv.y, 0.001));
    ASSERT_TRUE(equal(qat.z, inv.z, 0.001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Angle)
{
    Quaternion<float> a {1.22f, 4.34f, 5.11f, 3.74f};
    Quaternion<float> b {0.25f, 2.16f, 1.45f, 2.47f};

    normalize(a);
    normalize(b);

    float ang = angle(a,b);

    ASSERT_TRUE(equal(ang, 0.6855f, 0.0001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Identity)
{
    Quaternion<float> idn = identity<float>();
    Quaternion<float> exp = {1.0f, 0.f, 0.f, 0.f};

    ASSERT_TRUE(idn.s == exp.s);
    ASSERT_TRUE(idn.x == exp.x);
    ASSERT_TRUE(idn.y == exp.y);
    ASSERT_TRUE(idn.z == exp.z);
}