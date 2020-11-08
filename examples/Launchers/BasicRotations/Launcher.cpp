

#include <Launcher.hpp>
#include <CGM/Modules/Transformations/3D.hpp>


namespace cgx = cgm::xyz;

Launcher::Launcher()
    : space(Geometry::makeAxes(sceneMaterial))
{

}

void Launcher::render()
{
    Application::render();

    cgx::rotate(space->xform, static_cast<cgm::FLOAT>(tickDelta() * 3), cgx::up());
    cgx::rotate(space->xform, static_cast<cgm::FLOAT>(tickDelta() * 12), cgx::ArbitraryAxis{cgm::normalized(cgx::forward(space->xform)), cgx::position(space->xform)});
    scenePainter->render(*space, *sceneCamera);
}

void Launcher::beforeLoop()
{
    Application::beforeLoop();

    space->init();

    cgx::scale(space->xform, cgm::vec3(0.25f));
    cgx::translate(space->xform, cgx::up() * 0.75f);
    cgx::rotate(space->xform, cgm::radians(45.0f), cgx::up());
    cgx::translate(space->xform, cgx::right() * 0.5f);
    cgx::translate(space->xform, cgx::forward() * 0.5f);
}
