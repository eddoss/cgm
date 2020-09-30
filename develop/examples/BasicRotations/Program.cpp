

#include <Global.hpp>
#include "Program.hpp"
#include <iostream>
#include <cstdlib>


Program::Program()
    : material(new ShaderProgram)
{
    INIT_GLFW
    if (!create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant create GLFW window")
        exit(-1);
    }
    INIT_GLEW
}

void
Program::createObjects()
{
    material->create();
//    material->addShaderPack(L"Resources/Plain");
    material->addShaderPack(L"Resources/ColorView");
    material->link();

//    objects.emplace_back(Geometry::makeTriangle(material));
    objects.emplace_back(Geometry::makeAxes(material));

    for (const auto& object : objects)
    {
        object->init();
    }

    perspective = makePerspective(m_width, m_height, 45, 0.01, 100);
}

void
Program::beforeLoop()
{
    createObjects();

    glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, 1.0f);
    glViewport(0, 0, GLsizei(m_width), GLsizei(m_height));
    glEnable(GL_MULTISAMPLE);

//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);
//    glDepthMask(GL_TRUE);

//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
//    glFrontFace(GL_CCW);

//    glPrimitiveRestartIndex(Geometry::primitiveRestartValue);
//    glEnable(GL_PRIMITIVE_RESTART);
}

void
Program::clearEvent()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void
Program::renderEvent()
{
    for (const auto& object : objects)
    {
        object->render(camera, perspective);
    }
}

void
Program::resizeEvent()
{
    perspective = makePerspective(m_width, m_height, 45, 0.01, 100);
    glViewport(0, 0, GLsizei(m_width), GLsizei(m_height));
    glClear(GL_COLOR_BUFFER_BIT);

    for (const auto& object : objects)
    {
        object->render(camera, perspective);
    }
    glfwSwapBuffers(m_window);
}

cgm::mat4
Program::makePerspective(size_t w, size_t h, cgm::float32 fovy, cgm::float32 n, cgm::float32 f)
{
    cgm::float32 aspect = cgm::float32(w)/cgm::float32(h);

    if (cgm::eq(n,f) || cgm::eq(aspect, 0.0f))
    {
        return {};
    }

    cgm::float32 fov = cgm::radians(fovy/2);
    cgm::float32 sin = std::sin(fov);

    if (cgm::eq(sin,0.0f))
    {
        return {};
    }

    cgm::float32 ctg = std::cos(fov) / sin;
    cgm::float32 clp = f - n;

    cgm::mat4 matrix (0.0f);
    matrix(0,0) = ctg / aspect;
    matrix(1,1) = ctg;
    matrix(2,2) = -(n + f) / clp;
    matrix(2,3) = -(n * f) / clp;
    matrix(3,2) = -1.0f;

    return matrix;
}
