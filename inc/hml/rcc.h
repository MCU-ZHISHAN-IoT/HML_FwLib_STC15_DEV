/*****************************************************************************/
/** 
 * \file        rcc.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operation for reset and clock control
 * \note        
 * \version     v0.0
 * \ingroup     RCC
******************************************************************************/

#ifndef ___HML_RCC_H___
#define ___HML_RCC_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/util.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 * \brief mark main clock division value
 */
typedef enum
{
    RCC_prescaler_1   = 0x00,
    RCC_prescaler_2   = 0x01,
    RCC_prescaler_4   = 0x02,
    RCC_prescaler_8   = 0x03,
    RCC_prescaler_16  = 0x04,
    RCC_prescaler_32  = 0x05,
    RCC_prescaler_64  = 0x06,
    RCC_prescaler_128 = 0x07      /* 1/128 */
} RCC_MCLK_prescalerValue;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void RCC_clearResetFlag(void);
FunctionalState RCC_getResetFlag(void);
void RCC_reset(void);
void RCC_setBootMode(RCC_bootMode mode);
// void RCC_setMainClockOutputPin(RCC_MCLK_outputPin pin);
// void RCC_setMainClockOutputPrescaleValue(RCC_MCLK_outputPrescaleValue val);
// void RCC_setMainClockPrescaleValue(RCC_MCLK_prescalerValue val);
// void RCC_setSystemClockOutputPin(RCC_MCLK_sysclkOutputPin pin)
// uint32_t RCC_getSystemClockFrequency(void);

#endif
