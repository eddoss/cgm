

#include <Launcher.hpp>
#include <CGM/Modules/Projections.hpp>


namespace cgx = cgm::xyz;

Launcher::Launcher()
{
    space = Geometry::makeAxes(sceneMaterial);
    cgx::scale<CGM_LOCAL>(space->xform, cgm::vec3(0.05f));
    setupFrame();
}

void
Launcher::render()
{
    Application::render();
    scenePainter->render(*frame, *sceneCamera);
    scenePainter->render(*space, *sceneCamera);
}

void
Launcher::beforeLoop()
{
    Application::beforeLoop();
    frame->init();
    space->init();
}

void
Launcher::buttonEvent(BaseWindow::EButton button, BaseWindow::EState state, BaseWindow::EModifier modifier)
{
    BaseWindow::buttonEvent(button, state, modifier);

    if (button == EButton::Left && state == EState::Press && keyState(EKey::LeftAlt) != EState::Press)
    {
        const auto intersectPoint = []
        (
            const cgm::vec3& rayVector,
            const cgm::vec3& rayPoint,
            const cgm::vec3& planeNormal,
            const cgm::vec3& planePoint
        ) -> cgm::vec3
        {
            const cgm::vec3& diff = rayPoint - planePoint;
            double prod1 = cgm::dot(diff, planeNormal);
            double prod2 = cgm::dot(rayVector, planeNormal);
            double prod3 = prod1 / prod2;
            return rayPoint - rayVector * prod3;
        };

        const auto posi = mousePosition();
        const auto posf = cgm::vec2
        {
            cgm::fit(cgm::FLOAT(posi.x), cgm::FLOAT(0), cgm::FLOAT(width()), cgm::FLOAT(-1), cgm::FLOAT(1)),
            cgm::fit(cgm::FLOAT(posi.y), cgm::FLOAT(0), cgm::FLOAT(height()), cgm::FLOAT(1), cgm::FLOAT(-1))
        };
        std::cout << posf << std::endl;
        const auto ray = cgm::cameraRay
        (
            posf,
            sceneCamera->properties().fov,
            sceneCamera->properties().aspect,
            sceneCamera->properties().near,
            sceneCamera->space()
        );

        auto pos = intersectPoint(sceneCamera->forward(), sceneCamera->position(), cgx::up(), cgm::vec3(0));
        cgx::setPosition(space->xform, pos);
        std::cout << ray << std::endl;
    }
}

void
Launcher::setupFrame()
{
    const auto screenPositions = std::vector
    {
        cgm::vec2 {-1.0f, -1.0f},
        cgm::vec2 {-1.0f, +1.0f},
        cgm::vec2 {+1.0f, +1.0f},
        cgm::vec2 {+1.0f, -1.0f}
    };

    auto points = std::vector<Geometry::Point>{};
    auto indices = std::vector<cgm::uint32>{};

    points.reserve(4);
    indices =
    {
        0, 1,
        Geometry::primitiveRestartValue,
        1, 2,
        Geometry::primitiveRestartValue,
        2, 3,
        Geometry::primitiveRestartValue,
        3, 0
    };

    for (const auto& screenPosition : screenPositions)
    {
        const auto worldPosition = cgm::cameraRay
        (
            screenPosition,
            sceneCamera->properties().fov,
            sceneCamera->properties().aspect,
            sceneCamera->properties().near,
            sceneCamera->space()
        );
        points.emplace_back(worldPosition, cgm::vec4(0.5f));
    }

    frame = std::make_unique<Geometry>(std::move(points), std::move(indices), sceneMaterial);
}
