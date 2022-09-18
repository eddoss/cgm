#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/transformations/module_globals.hpp>


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

CGM_NAMESPACE_END

/* ####################################################################################### */
/* Macro */
/* ####################################################################################### */

#define CGM_SRT CGM::ETransformOrder::SRT
#define CGM_STR CGM::ETransformOrder::STR
#define CGM_TRS CGM::ETransformOrder::TRS
#define CGM_TSR CGM::ETransformOrder::TSR
#define CGM_RST CGM::ETransformOrder::RST
#define CGM_RTS CGM::ETransformOrder::RTS
