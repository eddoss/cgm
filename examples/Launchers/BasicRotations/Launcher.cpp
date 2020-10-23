

#include <Launcher.hpp>


namespace cgx = cgm::xyz;

Launcher::Launcher()
    : space(Geometry::makeAxes(material))
{

}

void Launcher::render()
{
    Application::render();

    cgx::rotate<CGM_WORLD>(space->xform, static_cast<cgm::FLOAT>(tickDelta() * 3), cgx::up());
    cgx::rotate<CGM_LOCAL>(space->xform, static_cast<cgm::FLOAT>(tickDelta() * 9), cgx::forward());
    space->render(sceneCamera.inverseSpace(), sceneCamera.ndc());
}

void Launcher::beforeLoop()
{
    Application::beforeLoop();

    space->init();

    cgx::scale(space->xform, cgm::vec3(0.25f));
    cgx::rotate(space->xform, cgm::radians(45.0f), cgx::up());
    cgx::translate(space->xform, cgx::right() * 0.5f);
    cgx::translate(space->xform, cgx::forward() * 0.5f);
}