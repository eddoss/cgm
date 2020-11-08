#pragma once


#include <Application/Application.hpp>


class Launcher : public Application
{
public:
    Launcher();

protected:
    void
    render() override;

    void
    beforeLoop() override;

    void
    mouseMoveEvent(cgm::Vector<2, int> position) override;

    void
    buttonEvent(EButton button, EState state, EModifier modifier) override;

private:

    void
    setupDots(size_t freq);

    void
    setupFrustum();

    void
    locateSpace(const cgm::vec2& screenPos);

    cgm::vec3
    intersection(const cgm::vec3& rayVector, const cgm::vec3& rayPoint,const cgm::vec3& planeNormal, const cgm::vec3& planePoint);

private:
    Camera::Unique
    projector = nullptr;

    Geometry::Unique
    dots = nullptr;

    Geometry::Unique
    frustum = nullptr;

    Geometry::Unique
    object = nullptr;

    IPainter::Unique
    dotPainter = nullptr;
};