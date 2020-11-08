
#pragma once


#include <Application/Application.hpp>
#include <Rendering/PolyPainter.hpp>


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
    clearEvent() override;

private:
    PolyPainter::Shared
    polyPainter;

//    std::vector<Geometry::Unique>
//    shapes;

    Geometry::Unique
    shape;
};