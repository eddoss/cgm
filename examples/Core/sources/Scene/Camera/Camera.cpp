

#include <Scene/Camera/Camera.hpp>

Camera::Camera()
    : controller(nullptr)
    , model(nullptr)
{

}

Camera::Camera(ICameraModel::Shared cameraModel, ICameraController::Shared cameraController)
    : controller(cameraController)
    , model(cameraModel)
{

}