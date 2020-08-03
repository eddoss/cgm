

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Coordinates/Functions.hpp>
#include <CGM/Coordinates/Operators.hpp>


using namespace std;
using namespace CGM;

TEST(Coordinates, Spherical_Cartesian)
{
    auto cartesian_in   = coord::cartesian(0.562206, 0.686596, 0.460989);
    auto spherical      = coord::spherical(cartesian_in);
    auto cartesian_out  = coord::cartesian(spherical);

    ASSERT_TRUE(cartesian_in == cartesian_out);
}

/* --------------------------------------------------------------------------------------- */

TEST(Coordinates, Cylindrical_Cartesian)
{
    auto cartesian_in   = coord::cartesian(0.562206, 0.686596, 0.460989);
    auto cylindrical    = coord::cylindrical(cartesian_in);
    auto cartesian_out  = coord::cartesian(cylindrical);

    ASSERT_TRUE(cartesian_in == cartesian_out);
}

/* --------------------------------------------------------------------------------------- */

TEST(Coordinates, Cylindrical_Spherical)
{
    auto spherical_in   = coord::Spherical(0.562206, 0.686596, 0.460989);
    auto cylindrical    = coord::cylindrical(spherical_in);
    auto spherical_out  = coord::spherical(cylindrical);

    ASSERT_TRUE(spherical_in == spherical_out);
}