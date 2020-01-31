

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Vector/Vector.hpp>


using namespace std;

TEST(SFINAE_IS_GOOD, Print)
{
    Vector<2> vec_2D {1,2};
    Vector<3> vec_3D {1,2,3};
    Vector<4> vec_4D {1,2,3,4};

    std::cout << "\n\n-------------------\n";

    std::cout << vec_2D.y() << std::endl;
    std::cout << vec_3D.z() << std::endl;
    std::cout << vec_4D.w() << std::endl;
}