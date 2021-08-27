

#include <Application/Application.hpp>
#include <CGM/Cartesian/3D.hpp>
#include <CGM/Transformations/3D.hpp>
#include <Rendering/LinePainter.hpp>
#include <Scene/Camera/Controllers/Aim.hpp>
#include <Scene/Camera/Controllers/Flyable.hpp>
#include <Scene/Camera/Models/Perspective.hpp>
#include <memory>


Application::Application()
    : sceneCamera(std::make_shared<Camera>())
    , sceneMaterial(std::make_shared<ShaderProgram>())
    , scenePainter(std::make_shared<LinePainter>())
{
    setupSceneCamera();

    sceneGrid = Geometry::makeGrid(20, 100, {0.125,0.125,0.125,1.0}, sceneMaterial);
    cgm::translate(sceneGrid->xform, 0.005f * cgm::down());

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
    sceneMaterial->addShaderPack(resource("Shaders/ColorView"));
    sceneMaterial->link();

    sceneGrid->init();
    sceneGnomon->init();

    glPrimitiveRestartIndex(CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE);
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

    const auto aspectRatio = aspect<cgm::f32>();

    {
        auto props = scenePerspectiveCameraModel->properties();
        props.aspect = aspectRatio;
        scenePerspectiveCameraModel->setProperties(props);
    }
    {
        auto props = sceneOrthographicCameraModel->properties();
        props.aspect = aspectRatio;
        sceneOrthographicCameraModel->setProperties(props);
    }

    glViewport(0, 0, GLsizei(width()), GLsizei(height()));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    render();

    glfwSwapBuffers(m_window);
}

void
Application::mouseMoveEvent(cgm::Vector<2,int> position)
{
    BaseWindow::mouseMoveEvent(position);

    auto& controller = sceneCamera->controller;
    const auto offset = mouseOffset();

    if (buttonState(EButton::Left) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        if constexpr (cgm::Config().handedness == cgm::EHandedness::Left)
        {
            controller->rotate(offset.x * 250 * rotateScale.x, -offset.y * 250 * rotateScale.y);
        }
        else
        {
            controller->rotate(-offset.x * 250 * rotateScale.x, -offset.y * 250 * rotateScale.y);
        }
    }
    else if (buttonState(EButton::Right) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        controller->move(0, 0, offset.x * 5 * moveScale.z);
        auto props = sceneOrthographicCameraModel->properties();
        props.zoom = cgm::distance(sceneAimCameraController->position(), sceneAimCameraController->aim());
        sceneOrthographicCameraModel->setProperties(props);
    }
    else if (buttonState(EButton::Middle) == EState::Press && keyState(EKey::LeftAlt) == EState::Press)
    {
        controller->move(-offset.x * 2 * moveScale.x, -offset.y * moveScale.y * 2, 0);
    }
}

void
Application::setupSceneCamera()
{
    const auto position = cgm::vec3 {3.0f, 3.0f, 3.0f};
    const auto target = cgm::vec3 {0.0f, 0.0f, 0.0f};
    sceneAimCameraController = std::make_shared<AimCameraController>(target, position);

    const cgm::f32 aspect = this->aspect<cgm::f32>();
    const cgm::f32 fov = 45.0f;
    const cgm::f32 near = 0.01f;
    const cgm::f32 far = 1000.0f;
    scenePerspectiveCameraModel = std::make_shared<PerspectiveCameraModel>(aspect, fov, near, far);

    const cgm::f32 zoom = cgm::distance(position, target);
    sceneOrthographicCameraModel = std::make_shared<OrthographicCameraModel>(aspect, zoom, near, far);

//    sceneCamera = std::make_shared<Camera>(sceneOrthographicCameraModel, sceneAimCameraController);
    sceneCamera = std::make_shared<Camera>(scenePerspectiveCameraModel, sceneAimCameraController);
}
