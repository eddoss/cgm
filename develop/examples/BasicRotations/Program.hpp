#pragma once


#include <CGM/Core>
#include <Window/BaseWindow.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <Rendering/IRenderable.hpp>
#include <Rendering/Geometry.hpp>


class Program : public BaseWindow
{
public:
    Program();

protected:
    virtual void
    createObjects();

protected:
    void
    beforeLoop() override;

    void
    clearEvent() override;

    void
    renderEvent() override;

    void
    resizeEvent() override;

protected:
    static cgm::mat4
    makePerspective(size_t w, size_t h, cgm::float32 fovy, cgm::float32 n, cgm::float32 f);

    std::vector<IRenderable::Shared>
    objects;

    ShaderProgram::Shared
    material {nullptr};

    cgm::mat4
    camera {cgm::identity<4>()};

    cgm::mat4
    perspective;

    cgm::vec3
    backgroundColor {0.1f, 0.1f, 0.1f};
};