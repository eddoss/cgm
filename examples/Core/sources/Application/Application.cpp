

#include <Application/Application.hpp>
#include <Rendering/LinePainter.hpp>
#include <memory>
#include <CGM/Cartesian/3D/Types/Config.hpp>

namespace cgx = cgm::xyz;

Application::Application()
    : sceneCamera(new Camera)
    , sceneMaterial(new ShaderProgram)
    , scenePainter(new LinePainter)
{
    Camera::Properties props;
    props.far = 500.0f;
    props.near = 0.01f;
    props.fov = 90.0f;
    props.aspect = cgm::float32(width()) / cgm::float32(height());

    sceneCamera->setProperties(props);
    sceneCamera->setPosition({3,3,3});
    sceneCamera->setTarget({0,0,0});

    sceneGrid = Geometry::makeGrid(20, 100, {0.125,0.125,0.125,1.0}, sceneMaterial);
    cgx::translate(sceneGrid->xform, 0.005f * cgx::down());

    sceneGnomon = Geometry::makeAxes(sceneMaterial);
}

void
Application::render()
{
    scenePainter->render(*sceneGrid, *sceneCamera);
    scenePainter->render(*sceneGnomon, *sceneCamera);
}

void
Application::beforeLoop()
{
    sceneMaterial->create();
    sceneMaterial->addShaderPack(L"Resources/ColorView");
    sceneMaterial->link();

    sceneGrid->init();
    sceneGnomon->init();

    glPrimitiveRestartIndex(Geometry::primitiveRestartValue);
    glEnable(GL_PRIMITIVE_RESTART);

    glEnable(GL_MULTISAMPLE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthMask(GL_TRUE);
}

void
Application::clearEvent()
{
    glClearColor(sceneBgColor.x, sceneBgColor.y, sceneBgColor.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
Application::renderEvent()
{
    render();
}

void
Application::resizeEvent()
{
    BaseWindow::resizeEvent();

    auto props = sceneCamera->properties();
    props.aspect = cgm::float32(width()) / cgm::float32(height());
    sceneCamera->setProperties(props);

    glViewport(0, 0, GLsizei(width()), GLsizei(height()));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    render();

    glfwSwapBuffers(m_window);
}

void
Application::mouseMoveEvent(cgm::Vector<2,int> position)
{
    BaseWindow::mouseMoveEvent(position);

    const auto offset = mouseOffset();

    if (buttonState(EButton::Left) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        if constexpr (cgm::xyz::Config().handedness == cgm::EHandedness::Left)
        {
            sceneCamera->rotate(offset.x * 250, -offset.y * 250);
        }
        else
        {
            sceneCamera->rotate(-offset.x * 250, -offset.y * 250);
        }
    }
    else if (buttonState(EButton::Right) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        sceneCamera->move(0, 0, offset.x * 5);
    }
    else if (buttonState(EButton::Middle) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        if constexpr (cgm::xyz::Config().handedness == cgm::EHandedness::Left)
        {
            sceneCamera->move(-offset.x * 2, -offset.y * 2, 0);
        }
        else
        {
            sceneCamera->move(offset.x * 2, -offset.y * 2, 0);
        }
    }
}
