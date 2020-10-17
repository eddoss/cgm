
#include <Launcher.hpp>

int main(int argc, char** argv)
{
    Launcher app;
    app.start();

//    const auto U = cgm::xyz::up<int>();
//    const auto R = cgm::xyz::right<int>();
//    const auto F = cgm::xyz::forward<int>();
//
//    std::cout.flags(std::cout.flags() & std::ios::boolalpha);
//
//#ifdef CGM_CFG_RHS
//    std::cout << "R x U " << (cgm::cross(R,U) == F) << std::endl;
//    std::cout << "U x F " << (cgm::cross(U,F) == R) << std::endl;
//    std::cout << "F x R " << (cgm::cross(F,R) == U) << std::endl;
//#else
//    std::cout << "U x R " << (cgm::cross(U,R) == F) << std::endl;
//    std::cout << "F x U " << (cgm::cross(F,U) == R) << std::endl;
//    std::cout << "R x F " << (cgm::cross(R,F) == U) << std::endl;
//#endif
    // XYZ +
    // ZXY +
    // YZX +

    // ZYX -
    // XZY -
    // YXZ -
    return 0;
}