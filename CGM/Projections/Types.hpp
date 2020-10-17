#pragma once


#include <CGM/Projections/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Describe common graphics API.
 **/
enum class EGraphicsApi
{
    OpenGL,
    DirectX,
    Vulkan,
    Metal
};

CGM_NAMESPACE_END