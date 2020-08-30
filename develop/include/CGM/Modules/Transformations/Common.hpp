#pragma once


#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Enums */
/* ####################################################################################### */

/**
 * Describe transformation order.
 */
enum class ETransformOrder
{
    SRT = 0,    /**< Scale, rotate, translate */
    STR,        /**< Scale, translate, rotate */
    TRS,        /**< Translate, rotate, scale */
    TSR,        /**< Translate, scale, rotate */
    RST,        /**< Rotate, scale, translate */
    RTS         /**< Rotate, translate, scale */
};

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/**
 * Describe transformation space.
 */
enum class ESpace
{
    Local = 0,    /**< Transform in local space. */
    World         /**< Transform in world space. */
};

CGM_NAMESPACE_END

/* ####################################################################################### */
/* Macro */
/* ####################################################################################### */

#define CGM_LOCAL   CGM::ESpace::Local
#define CGM_WORLD   CGM::ESpace::World

#define CGM_SRT     CGM::ETransformOrder::SRT
#define CGM_STR     CGM::ETransformOrder::STR
#define CGM_TRS     CGM::ETransformOrder::TRS
#define CGM_TSR     CGM::ETransformOrder::TSR
#define CGM_RST     CGM::ETransformOrder::RST
#define CGM_RTS     CGM::ETransformOrder::RTS