

#include <Launcher.hpp>


int main(int argc, const char* argv[])
{
    if (argc < 4)
    {
        CGM_EXAMPLES_FUNC_ERROR("Invalid commandline arguments count.")
    }

    CLI parameters;
    parameters.fontFile = argv[3];
    parameters.gamma = std::atof(argv[2]);
    parameters.spaa = true;

    if (std::string(argv[2]) == "off")
    {
        parameters.spaa = false;
    }

    Text2DLauncher app {parameters};
    app.run();

    return 0;
}