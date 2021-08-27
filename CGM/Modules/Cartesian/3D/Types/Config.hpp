#pragma once


#include <CGM/Modules/Core/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/ModuleGlobals.hpp>
#include <CGM/Modules/Cartesian/Common.hpp>
#include <CGM/Modules/Cartesian/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

struct Config
{
    /**
     * Current configuration 3D system right axis label.
     */
    const E3D
    right;

    /**
     * Current configuration 3D system up axis label.
     */
    const E3D
    up;

    /**
     * Current configuration 3D system forward axis label.
     */
    const E3D
    forward;

    /**
     * Current configuration 3D system handedness.
     */
    const EHandedness
    handedness;

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Create current 3D system configuration.
     */
    constexpr Config();
    constexpr Config& operator = (const Config&)    = delete;
    constexpr Config& operator = (Config&&)         = delete;
};

/* ####################################################################################### */
/* Macro */
/* ####################################################################################### */

#define CGM_CONFIG CGM::Config()

CGM_NAMESPACE_END


#include "Config.inl"