

#include <Launcher.hpp>
#include <CGM/Modules/Coordinates.hpp>
#include <CGM/Modules/Transformations/3D.hpp>


namespace cgx = cgm::xyz;

Launcher::Launcher()
    : polyPainter(std::make_shared<PolyPainter>())
{
    sceneAimCameraController->setPosition(cgm::coord::cartesian(0.0f, 0.0f, 10.0f));
    sceneAimCameraController->setAim(cgm::coord::cartesian(0.0f, 0.0f, 0.0f));
}

void
Launcher::render()
{
    Application::render();
    polyPainter->render(*shape, *sceneCamera);
//    for (auto& shape : shapes)
//    {
//        polyPainter->render(*shape, *sceneCamera);
//    }
}

void
Launcher::clearEvent()
{
    Application::clearEvent();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
Launcher::beforeLoop()
{
    Application::beforeLoop();

//    glEnable(GL_BLEND);
//    glBlendFunc(GL_ONE, GL_SRC_ALPHA);

    glPrimitiveRestartIndex(Geometry::primitiveRestartValue);
    glEnable(GL_PRIMITIVE_RESTART);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glBlendEquation(GL_FUNC_SUBTRACT);

    sceneBgColor = cgm::vec3(0.0f);

    const auto color = cgm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    const auto count = cgm::uint32(6);
    const auto radius = cgm::float32(1.0f);

    shape = Geometry::makeCircles(radius, count, color, sceneMaterial);

    shape->init();
//    const auto circlesCount = size_t(6);
//    const auto circlePointsCount = cgm::uint32(50);
//    const auto circleRadius = cgm::float32(1.0f);
//    const auto circleColor = cgm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
//    const auto layoutRadius = circleRadius / 1.0;
//    const auto angleStep = CGM_PI2 / circlesCount;
//
//    for (size_t i = 0; i < circlesCount; ++i)
//    {
//        const auto coeff = cgm::float32(i) / circlesCount;
//        const auto angle = angleStep * i;
//        const auto circleCenter = cgx::rotated(cgx::right() * layoutRadius, angle, cgx::forward());
//
//        auto circle = Geometry::makeCircle(circleRadius, circlePointsCount, circleColor, sceneMaterial);
//        cgx::translate(circle->xform, circleCenter);
//        cgx::translate(circle->xform, -cgx::forward() * coeff);
//        circle->init();
//        shapes.emplace_back(std::move(circle));
//    }
}
