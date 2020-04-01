

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Coordinates/Polar.hpp>
#include <Math3D/Core/Coordinates/Spherical.hpp>
#include <Math3D/Core/Coordinates/Cylindrical.hpp>
#include <Math3D/Core/Coordinates/Functions.hpp>
#include <Math3D/Core/Axes.hpp>
#include <Math3D/IO.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Coordinates, Axes)
{
    std::cout << std::endl;

    auto i = Vector<3,double> {0.562206, 0.686596, 0.460989};
    auto s = coord::spherical(i);
    auto o = coord::cartesian(s);
    auto c = coord::cylindrical(s);

    std::cout << i << std::endl;
    std::cout << o << std::endl;
    std::cout << coord::spherical(coord::cylindrical(s)) << std::endl;
    std::cout << s << std::endl;
}

/* --------------------------------------------------------------------------------------- */