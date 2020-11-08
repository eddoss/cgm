

#include <Launcher.hpp>
#include <CGM/Modules/Projections.hpp>
#include <CGM/Modules/Transformations/3D.hpp>
#include <Rendering/DotPainter.hpp>


namespace cgx = cgm::xyz;

Launcher::Launcher()
    : projector(new Camera)
    , dotPainter(new DotPainter)
{
//    setupFrustum();
//    setupDots(60);

    object = Geometry::makeAxes(sceneMaterial);

#ifdef CGM_CFG_COLUMN_MAJOR
    object->xform = object->xform * cgx::scalingMatrix(cgm::vec3(0.2f));
#else
    object->xform = cgx::scalingMatrix(cgm::vec3(0.2f)) * object->xform;
#endif
}

void
Launcher::render()
{
    Application::render();

    const auto& camera = *sceneCamera;

//    dotPainter->render(*dots, camera);
    scenePainter->render(*object, camera);
//    scenePainter->render(*frustum, camera);
}

void
Launcher::beforeLoop()
{
    Application::beforeLoop();

    glPointSize(0.0f);

//    dots->init();
    object->init();
//    frustum->init();
}

void
Launcher::mouseMoveEvent(cgm::Vector<2,int> position)
{
    Application::mouseMoveEvent(position);

    if (keyState(EKey::LeftAlt) != EState::Press && buttonState(EButton::Left) == EState::Press)
    {
        const auto windowPos = mousePosition();
        const auto viewportPos = convertToScreen<cgm::float32>(windowPos);

        locateSpace(viewportPos);
    }
}

void
Launcher::buttonEvent(BaseWindow::EButton button, BaseWindow::EState state, BaseWindow::EModifier modifier)
{
    BaseWindow::buttonEvent(button, state, modifier);

    if (button == EButton::Left && modifier != EModifier::Alt)
    {
        const auto windowPos = mousePosition();
        const auto viewportPos = convertToScreen<cgm::float32>(windowPos);

        locateSpace(viewportPos);
    }
}

void
Launcher::setupDots(size_t freq)
{
    const auto& model = *scenePerspectiveCameraModel;
    const auto& contr = *projector->controller;

    const auto countHeight = freq;
    const auto countWidth = size_t(countHeight * model.properties().aspect);

    const auto stepHeight = 1.0f / countHeight;
    const auto stepWidth = 1.0f / countWidth;

    const auto color = cgm::vec4 {0.5f, 0.0f, 0.5f, 1.0f};
    const auto projectorFov = cgm::radians(model.properties().fov);
    const auto projectorAspect = model.properties().aspect;
//    const auto projectorSpace = proj.space();
//    const auto projectorPos = proj.position();

    auto points = std::vector<Geometry::Point> {};

//    for (size_t i = 0; i < countWidth + 1; ++i)
//    {
//        const auto x = cgm::fit01(stepWidth * i, -1.0f, 1.0f);
//        for (size_t j = 0; j < countHeight + 1; ++j)
//        {
//            const auto y = cgm::fit01(stepHeight * j, -1.0f, 1.0f);
//            const auto ray = cgm::perspectiveRay({x,y}, projectorFov, projectorAspect, projectorSpace);
//            const auto pos = intersection(ray, projectorPos, cgx::up(), cgm::vec3(0.0f));
//            points.emplace_back(pos, color);
//        }
//    }

    dots = std::make_unique<Geometry>(std::move(points), std::vector<cgm::uint32>{}, sceneMaterial);
}

void
Launcher::setupFrustum()
{
//    const cgm::float32 fov      = cgm::radians(projector->properties().fov);
//    const cgm::float32 aspect   = projector->properties().aspect;
//    const cgm::float32 near     = projector->properties().near;
//    const cgm::float32 far      = projector->properties().far;
//
//    const cgm::float32 near_h   = near * std::tan(fov * 0.5f);
//    const cgm::float32 near_w   = near_h * aspect;
//    const cgm::float32 far_h    = far * std::tan(fov * 0.5f);
//    const cgm::float32 far_w    = far_h * aspect;
//
//    const auto near_lb = cgm::coord::cartesian<cgm::float32>(-near_h, -near_w, near);
//    const auto near_lt = cgm::coord::cartesian<cgm::float32>(+near_h, -near_w, near);
//    const auto near_rt = cgm::coord::cartesian<cgm::float32>(+near_h, +near_w, near);
//    const auto near_rb = cgm::coord::cartesian<cgm::float32>(-near_h, +near_w, near);
//
//    const auto far_lb = cgm::coord::cartesian<cgm::float32>(-far_h, -far_w, far);
//    const auto far_lt = cgm::coord::cartesian<cgm::float32>(+far_h, -far_w, far);
//    const auto far_rt = cgm::coord::cartesian<cgm::float32>(+far_h, +far_w, far);
//    const auto far_rb = cgm::coord::cartesian<cgm::float32>(-far_h, +far_w, far);
//
//    const auto color = cgm::vec4 {0.7, 0.0, 0.7, 1.0};
//    auto points = std::vector<Geometry::Point>
//    {
//        {near_lb, color}, {near_lt, color},     // near plane left line
//        {near_lt, color}, {near_rt, color},     // near plane top line
//        {near_rt, color}, {near_rb, color},     // near plane right line
//        {near_lb, color}, {near_rb, color},     // near plane bottom line
//
//        {far_lb, color}, {far_lt, color},       // far plane left line
//        {far_lt, color}, {far_rt, color},       // far plane top line
//        {far_rt, color}, {far_rb, color},       // far plane right line
//        {far_lb, color}, {far_rb, color},       // far plane bottom line
//
//        {near_lb, color}, {far_lb, color},      // side line: left bottom
//        {near_lt, color}, {far_lt, color},      // side line: left top
//        {near_rt, color}, {far_rt, color},      // side line: right top
//        {near_rb, color}, {far_rb, color}       // side line: right bottom
//    };
//
//
//    const auto rv = Geometry::primitiveRestartValue;
//    auto indices  = std::vector<cgm::uint32>
//    {
//        0, 1, rv,
//        2, 3, rv,
//        4, 5, rv,
//        6, 7, rv,
//
//        8, 9, rv,
//        10, 11, rv,
//        12, 13, rv,
//        14, 15, rv,
//
//        16, 17, rv,
//        18, 19, rv,
//        20, 21, rv,
//        22, 23
//    };
//
//    frustum = std::make_unique<Geometry>(std::move(points), std::move(indices), sceneMaterial);
//    frustum->xform = projector->space();
}

cgm::vec3
Launcher::intersection(const cgm::vec3& rayVector, const cgm::vec3& rayPoint,const cgm::vec3& planeNormal, const cgm::vec3& planePoint)
{
    const cgm::vec3& diff = rayPoint - planePoint;
    double prod1 = cgm::dot(diff, planeNormal);
    double prod2 = cgm::dot(rayVector, planeNormal);
    double prod3 = prod1 / prod2;
    return rayPoint - rayVector * prod3;
}

void
Launcher::locateSpace(const cgm::vec2& tap)
{
    const auto& model = *scenePerspectiveCameraModel;
    const auto& contr = *sceneAimCameraController;

    const auto fov     = cgm::radians(model.properties().fov);
    const auto pos     = contr.position();
    const auto aspect  = model.properties().aspect;
    const auto& space  = contr.space();

    const auto proj_ray = cgm::perspectiveRay(tap, fov, aspect, space);
    const auto intersec = intersection(proj_ray, pos, cgx::up(), cgm::vec3(0));

    cgx::setPosition(object->xform, intersec);

//    std::cout << "      Screen: " << tap_pos << std::endl;
//    std::cout << "   World Ray: " << proj_ray << std::endl;
//    std::cout << "Intersection: " << intersec << std::endl;
}