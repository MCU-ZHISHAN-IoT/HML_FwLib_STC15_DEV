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
 * \brief mark main clock division value (SYSCLK = MCLK/PRESCALER )
 * \note STC15W4K32S4/STC15W1K08PWM subseries and STC15W1K20S-LQFP64 only support 1, 2, 4, 16
 *       STC15W401AS subseries only supports 1, 2, 4
 */
typedef enum
{
    RCC_prescaler_1   = 0x00,
    RCC_prescaler_2   = 0x01,
    RCC_prescaler_4   = 0x02
#if (HML_MCU_MODEL_SUBSERIES != MCU_SUBSERIES_STC15W401AS)
,
#if (HML_MCU_MODEL_SUBSERIES != MCU_SUBSERIES_STC15W4K32S4) && \
    (HML_MCU_MODEL_SUBSERIES != MCU_SUBSERIES_STC15W1K08PWM)
    RCC_prescaler_8   = 0x03,
#endif
    RCC_prescaler_16  = 0x04
#if (HML_MCU_MODEL_SUBSERIES != MCU_SUBSERIES_STC15W4K32S4) && \
    (HML_MCU_MODEL_SUBSERIES != MCU_SUBSERIES_STC15W1K08PWM)
,
    RCC_prescaler_32  = 0x05,
    RCC_prescaler_64  = 0x06,
    RCC_prescaler_128 = 0x07      /* 1/128 */
#endif
#endif
} RCC_MCLK_prescalerValue;

/**
 * \brief boot area define
 */
typedef enum
{
    RCC_bootMode_ap  = 0x0,       /* boot from application area */
    RCC_bootMode_iap = 0x1        /* boot from IAP area */
} RCC_bootMode;

#if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W404S) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K16S)
/**
 * \brief define main clock output pin
 */
typedef enum
{
    RCC_mclkOutputPin_MCLKO   = 0x0,   /* output via MCLKO(P54) */
    RCC_mclkOutputPin_MCLKO_2 = 0x1    /* output via MCLKO_2(P16) */
} RCC_mclkOutputPin;
#endif

#if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W4K32S4)  || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W401AS)   || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K08PWM) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K20S)
/**
 * \brief define system clock output pin
 */
typedef enum
{
    RCC_sysclkOutputPin_SYSCLKO   = 0x0,    /* output via SYSCLKO(P54) */
    RCC_sysclkOutputPin_SYSCLKO_2 = 0x1,    /* output via SYSCLKO_2(P16) */
} RCC_sysclkOutputPin;
#endif

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void RCC_clearResetFlag(void);
FunctionalState RCC_getResetFlag(void);
void RCC_reset(void);
void RCC_setBootMode(RCC_bootMode mode);

#if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W404S) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K16S)
void RCC_setMainClockOutputPin(RCC_mclkOutputPin pin);
#endif

#if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W4K32S4)  || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W401AS)   || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K08PWM) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K20S)
void RCC_setSystemClockOutputPin(RCC_sysclkOutputPin pin);
#endif

// void RCC_setMainClockOutputPrescaleValue(RCC_MCLK_outputPrescaleValue val);
// void RCC_setMainClockPrescaleValue(RCC_MCLK_prescalerValue val);
// uint32_t RCC_getSystemClockFrequency(void);

#endif
