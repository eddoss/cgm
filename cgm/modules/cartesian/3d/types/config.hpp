#pragma once


#include <cgm/modules/core/types/enums.hpp>
#include <cgm/modules/cartesian/module_globals.hpp>
#include <cgm/modules/cartesian/common.hpp>
#include <cgm/modules/cartesian/3d/module_globals.hpp>


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


#include "config.inl"
