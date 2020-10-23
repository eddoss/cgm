
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

private:
    std::unique_ptr<Geometry>
    space = nullptr;
};