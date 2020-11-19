#pragma once

#include <iostream>
#include <filesystem>

#define CGM_EXAMPLES_FUNC_INFO(message) std::cout << message << std::endl;

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_FUNC_WARNING(message) std::cout << "\n[WARNING | " << __FUNCTION__ << "()]: " << message << std::endl << __FILE__ << ":" << __LINE__ << std::endl;

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_FUNC_ERROR(message) std::cout << "\n[ERROR | " << __FUNCTION__ << "()]: " << message << std::endl << __FILE__ << ":" << __LINE__ << std::endl; exit(-1);

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;


std::wstring
static resource(const std::string& path)
{
    auto resPath = std::filesystem::path(CGM_EXAMPLES_RESOURCES_DIR) / path;

    if (!std::filesystem::exists(resPath))
    {
        CGM_EXAMPLES_FUNC_ERROR(std::string("Invalid resource file. [") + resPath.string() + "]")
    }

    return resPath;
}