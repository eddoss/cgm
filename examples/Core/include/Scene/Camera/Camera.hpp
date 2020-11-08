#pragma once


#include <Scene/Camera/Models/ICameraModel.hpp>
#include <Scene/Camera/Controllers/ICameraController.hpp>


class Camera
{
public:
    using Shared = std::shared_ptr<Camera>;
    using Unique = std::unique_ptr<Camera>;
    using Weak = std::weak_ptr<Camera>;

public:
    Camera();
    Camera(ICameraModel::Shared cameraModel, ICameraController::Shared cameraController);

public:
    ICameraController::Shared
    controller;

    ICameraModel::Shared
    model;
};