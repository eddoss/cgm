#pragma once


#include <CGM/Modules/Core.hpp>
#include <Application/BaseWindow.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <Rendering/IPainter.hpp>
#include <Scene/Geometry.hpp>
#include <Scene/Camera/Models/Perspective.hpp>
#include <Scene/Camera/Controllers/Aim.hpp>
#include <Scene/Camera/Controllers/Flyable.hpp>


class Application : public BaseWindow
{
public:
    Application();

protected:
    virtual void
    render();

protected:
    void
    beforeLoop() override;

    void
    clearEvent() override;

    void
    renderEvent() override;

    void
    resizeEvent() override;

    void
    mouseMoveEvent(cgm::Vector<2,int> position) override;

protected:
    void
    setupSceneCamera();

protected:
    PerspectiveCameraModel::Shared
    scenePerspectiveCameraModel {nullptr};

    AimCameraController::Shared
    sceneAimCameraController {nullptr};

    FlyableCameraController::Shared
    sceneFlyableCameraController {nullptr};

    Camera::Shared
    sceneCamera {nullptr};

    ShaderProgram::Shared
    sceneMaterial {nullptr};

    IPainter::Shared
    scenePainter {nullptr};

    Geometry::Unique
    sceneGrid {nullptr};

    Geometry::Unique
    sceneGnomon {nullptr};

    cgm::vec3
    sceneBgColor {0.1f, 0.1f, 0.1f};

    cgm::vec3
    moveScale {1.0f, 1.0f, 1.0f};   // horizontal, vertical, forward

    cgm::vec2
    rotateScale {1.0f, 1.0f};       // horizontal, vertical
};