#pragma once


#include <CGM/Modules/Core.hpp>
#include <Application/BaseWindow.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <Rendering/IPainter.hpp>
#include <Scene/Geometry.hpp>
#include <Scene/Camera.hpp>


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
    Camera::Unique
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

    cgm::float32
    moveVerticalScale = 1.0f;

    cgm::float32
    moveHorizontalScale = 1.0f;

    cgm::float32
    moveForwardScale = 1.0f;
};