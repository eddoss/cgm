

#include <Launcher.hpp>
#include <CGM/Transformations/3D.hpp>
#include <CGM/Primitives.hpp>


Launcher::Launcher()
    : space(Geometry::makeAxes(sceneMaterial))
{

}

void Launcher::render()
{
    Application::render();

    cgm::rotate(space->xform, static_cast<cgm::FLOAT>(tickDelta() * 3), cgm::up());
    cgm::rotate(space->xform, static_cast<cgm::FLOAT>(tickDelta() * 12), cgm::Ray{cgm::normalized(cgm::forward(space->xform)), cgm::position(space->xform)});
    scenePainter->render(*space, *sceneCamera);
}

void Launcher::beforeLoop()
{
    Application::beforeLoop();

    space->init();

    cgm::scale(space->xform, cgm::vec3(0.25f));
    cgm::translate(space->xform, cgm::up() * 0.75f);
    cgm::rotate(space->xform, cgm::radians(45.0f), cgm::up());
    cgm::translate(space->xform, cgm::right() * 0.5f);
    cgm::translate(space->xform, cgm::forward() * 0.5f);

    sceneAimCameraController->focus(cgm::vec3{0,0,0}, cgm::vec3{3,3,3});
}
