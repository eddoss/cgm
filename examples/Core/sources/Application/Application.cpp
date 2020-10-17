

#include <Application/Application.hpp>
#include <Global.hpp>
#include <CGM/Modules/Transformations/3D.hpp>
#include <iostream>
#include <memory>
#include <cstdlib>

namespace cgx = cgm::xyz;

Application::Application()
{
    INIT_GLFW
    if (!create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant create GLFW window")
    }
    INIT_GLEW

    sceneCameraProperties.far = 500.0f;
    sceneCameraProperties.near = 0.01f;
    sceneCameraProperties.fov = 45.0f;
    sceneCameraProperties.aspect = cgm::float32(m_width) / cgm::float32(m_height);
    sceneCamera.setProperties(sceneCameraProperties);
    sceneCamera.setPosition({2, 2, 2});
    sceneCamera.setTarget({0, 0, 0});

    material = std::make_shared<ShaderProgram>();
    sceneGrid = Geometry::makeGrid(20, 100, {0.125,0.125,0.125,1.0}, material);
    sceneGnomon = Geometry::makeAxes(material);
}

void
Application::render()
{
    sceneGrid->render(sceneCamera.inverseSpace(), sceneCamera.ndc());
    sceneGnomon->render(sceneCamera.inverseSpace(), sceneCamera.ndc());
}

void
Application::beforeLoop()
{
    material->create();
    material->addShaderPack(L"Resources/ColorView");
    material->link();

    sceneGrid->init();
    sceneGnomon->init();

    glClearColor(sceneBgColor.x, sceneBgColor.y, sceneBgColor.z, 1.0f);
    glViewport(0, 0, GLsizei(m_width), GLsizei(m_height));

    glPrimitiveRestartIndex(Geometry::primitiveRestartValue);
    glEnable(GL_PRIMITIVE_RESTART);

    glEnable(GL_MULTISAMPLE);

//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);
//    glDepthMask(GL_TRUE);

//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
//    glFrontFace(GL_CCW);
}

void
Application::clearEvent()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void
Application::renderEvent()
{
    render();
}

void
Application::resizeEvent()
{
    sceneCameraProperties.aspect = cgm::float32(m_width) / cgm::float32(m_height);
    sceneCamera.setProperties(sceneCameraProperties);

    glViewport(0, 0, GLsizei(m_width), GLsizei(m_height));
    glClear(GL_COLOR_BUFFER_BIT);

    render();

    glfwSwapBuffers(m_window);
}

void
Application::mouseMoveEvent(cgm::Vector<2,int> position)
{
    auto dx = m_mouse_move_dir.x;
    auto dy = m_mouse_move_dir.y;

    if (buttonState(EButton::Left) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        sceneCamera.rotate(-dx * 2.25, -dy * 2.25);
    }
    else if (buttonState(EButton::Right) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        sceneCamera.move(0, 0, -dx * 0.1);
    }
    else if (buttonState(EButton::Middle) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        sceneCamera.move(-dx * 0.025, dy * 0.025, 0);
    }
}

void
Application::tickEvent()
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
