
#include <Window/BaseWindow.hpp>

int main(int argc, char** argv)
{
    INIT_GLFW
    BaseWindow window;
    if (!window.create()){ exit(-1); }
    INIT_GLEW

    window.start();

    return 0;
}