#pragma once


#include <CGM/Cartesian/ModuleGlobals.hpp>
#include <CGM/Cartesian/Common.hpp>
#include <CGM/Cartesian/3D/ModuleGlobals.hpp>
#include <CGM/Cartesian/3D/Types/Enums.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

struct Config
{
    /**
     * Current configuration 3D system right axis label.
     */
    EAxes
    right;

    /**
     * Current configuration 3D system up axis label.
     */
    EAxes
    up;

    /**
     * Current configuration 3D system forward axis label.
     */
    EAxes
    forward;

    /**
     * Current configuration 3D system handedness.
     */
    EHandedness
    handedness;

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Create current 3D system configuration.
     */
    constexpr Config();
    constexpr Config(const Config&)                 = delete;
    constexpr Config(Config&&)                      = delete;
    constexpr Config& operator = (const Config&)    = delete;
    constexpr Config& operator = (Config&&)         = delete;
};

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include "Config.inl"