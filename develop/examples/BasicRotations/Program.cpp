

#include <Global.hpp>
#include "Program.hpp"
#include <iostream>
#include <cstdlib>
#include <CGM/Transformations/3D>

namespace cgx = cgm::xyz;

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

    cameraProperties.far = 500.0f;
    cameraProperties.near = 0.01f;
    cameraProperties.fov = 45.0f;
    cameraProperties.aspect = cgm::float32(m_width) / cgm::float32(m_height);

    camera.setProperties(cameraProperties);
    camera.setPosition({2,2,2});
    camera.setTarget({0,0,0});
}

void
Program::render()
{
//    camera.rotate(0.0f, tickDelta() * 100);
    auto worldToCamera = cgm::inverseForce(camera.space());

    for (const auto& object : objects)
    {
        object->render(worldToCamera, camera.perspective());
    }
}

void
Program::createObjects()
{
    material->create();
    material->addShaderPack(L"Resources/ColorView");
    material->link();

    objects.emplace_back(Geometry::makeAxes(material));

    for (const auto& object : objects)
    {
        object->init();
    }
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
    render();
}

void
Program::resizeEvent()
{
    cameraProperties.aspect = cgm::float32(m_width) / cgm::float32(m_height);
    camera.setProperties(cameraProperties);

    glViewport(0, 0, GLsizei(m_width), GLsizei(m_height));
    glClear(GL_COLOR_BUFFER_BIT);

    render();

    glfwSwapBuffers(m_window);
}

void
Program::mouseMoveEvent(cgm::Vector<2,int> position)
{
    auto dx = m_mouse_move_dir.x;
    auto dy = m_mouse_move_dir.y;

    if (buttonState(EButton::Left) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        camera.rotate(-dx * 2.25, -dy * 2.25);
    }
    else if (buttonState(EButton::Right) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        camera.move(0, 0, -dx * 0.1);
    }
    else if (buttonState(EButton::Middle) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        camera.move(-dx * 0.05, dy * 0.05, 0);
    }

}

void
Program::tickEvent()
{
    if (m_previous_tick_mouse_pos == cgm::Vector<2,int>(0))
    {
        m_previous_tick_mouse_pos = 0;
    }

    const auto currentPos = mousePosition();
    const auto delta = currentPos - m_previous_tick_mouse_pos;
    m_previous_tick_mouse_pos = currentPos;
    m_previous_tick_mouse_pos_delta.x = std::abs(delta.x);
    m_previous_tick_mouse_pos_delta.y = std::abs(delta.y);

    if (delta.x < 0)
    {
        m_mouse_move_dir.x = -1;
    }
    else if (delta.x == 0)
    {
        m_mouse_move_dir.x = 0;
    }
    else
    {
        m_mouse_move_dir.x = 1;
    }

    if (delta.y < 0)
    {
        m_mouse_move_dir.y = -1;
    }
    else if (delta.y == 0)
    {
        m_mouse_move_dir.y = 0;
    }
    else
    {
        m_mouse_move_dir.y = 1;
    }
}
