#pragma once


#include <CGM/Modules/Core.hpp>
#include <Application/BaseWindow.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <Rendering/IRenderable.hpp>
#include <Rendering/Geometry.hpp>
#include <Rendering/Camera.hpp>


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
    tickEvent() override;

    void
    clearEvent() override;

    void
    renderEvent() override;

    void
    resizeEvent() override;

    void
    mouseMoveEvent(cgm::Vector<2,int> position) override;

protected:
    Camera::Properties
    sceneCameraProperties;

    Camera
    sceneCamera;

    ShaderProgram::Shared
    material {nullptr};

    Geometry::Unique
    sceneGrid;

    Geometry::Unique
    sceneGnomon;

    cgm::vec3
    sceneBgColor {0.1f, 0.1f, 0.1f};

private:
    cgm::Vector<2,int>
    m_mouse_move_dir;

    cgm::Vector<2,int>
    m_previous_tick_mouse_pos {0,0};

    cgm::Vector<2,int>
    m_previous_tick_mouse_pos_delta {0,0};
};