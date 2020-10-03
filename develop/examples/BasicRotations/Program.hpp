#pragma once


#include <CGM/Core>
#include <Window/BaseWindow.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <Rendering/IRenderable.hpp>
#include <Rendering/Geometry.hpp>
#include <Rendering/Camera.hpp>


class Program : public BaseWindow
{
public:
    Program();

protected:
    virtual void
    render();

    virtual void
    createObjects();

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
    std::vector<IRenderable::Shared>
    objects;

    ShaderProgram::Shared
    material {nullptr};

    cgm::vec3
    backgroundColor {0.1f, 0.1f, 0.1f};

    Camera::Properties
    cameraProperties;

    Camera
    camera;

private:
    cgm::Vector<2,int>
    m_mouse_move_dir;

    cgm::Vector<2,int>
    m_previous_tick_mouse_pos {0,0};

    cgm::Vector<2,int>
    m_previous_tick_mouse_pos_delta {0,0};
};