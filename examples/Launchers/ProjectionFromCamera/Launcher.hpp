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
    buttonEvent(EButton button, EState state, EModifier modifier) override;

private:
    void
    setupFrame();

private:
    Geometry::Unique
    frame = nullptr;

    Geometry::Unique
    space = nullptr;
};