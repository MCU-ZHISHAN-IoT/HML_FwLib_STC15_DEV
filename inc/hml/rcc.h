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
 *                                macro                                      *
 *****************************************************************************/
/**
 * \brief Clock output type define
 * \note  STC15W1K08PWM, STC15W4K32S4, STC15W401AS subseries and STC15W1K20S with
 *        LQFP64 packaging output system clock, and others output main clock
 */
#define MAINCLCOK       0x00      /* Only output main clock */
#define SYSTEMCLOCK     0x01      /* Only output system clcok */

#if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W4K32S4) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W401AS ) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K08PWM )
    #define HML_CLOCK_OUTPUT_TYPE SYSTEMCLOCK
#elif (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K20S)
    #if ((HML_MCU_PACKAGING == LQFP64S) || (HML_MCU_PACKAGING == LQFP64L))
        #define HML_CLOCK_OUTPUT_TYPE SYSTEMCLOCK
    #else
        #define HML_CLOCK_OUTPUT_TYPE MAINCLOCK
    #endif
#else
    #define HML_CLOCK_OUTPUT_TYPE MAINCLOCK
#endif

/**
 * \brief Support selecting clock output pin define
 * \note  Main clock ouput pin can be set as MCLKO or MCLKO_2. MCUs with 8-pin,
 *        such as STC15F100W subseries, output via MCLCKO(P34); STC15F2K60S2,
 *        STC15W201S, STC15F408AD subseries output via MCLKO(P54); STC15W404S
 *        and STC15W1K16S subseries support MCLKO(P54) and MCLKO2(P16).
 * \note  Clock output pin can be set as SYSCLKO or SYSCLKO_2 for all MCUs support
 *        output system clock.
 */
#if (HML_CLOCK_OUTPUT_TYPE == SYSTEMCLOCK)
    #define HML_SUPPORT_SELECT_CLOCK_OUTPUT_PIN 1
#else
    #if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15F2K60S2) || \
        (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15F408AD ) || \
        (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W201S  )
        #define HML_SUPPORT_SELECT_CLOCK_OUTPUT_PIN 1
    #else
        #define HML_SUPPORT_SELECT_CLOCK_OUTPUT_PIN 0
    #endif
#endif

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 * \brief Enumerate main clock division factor(SYSCLK = MCLK/PRESCALER)
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
} RCC_prescaler;

/**
 * \brief Enumerate clcok division factor of main/system clock output, support
 *        0, 1, 2, 4, 16. Especially, '0' means MCU will not output clock.
 * \note  All MCUs with main clock output support 0, 1, 2, 4. 
 * \note  STC15W4K32S4\STC15W1K08PWM subseries and STC15W1K20S-LQFP64 only
 *        support 0, 1, 2, 4, 16. STC15W401AS subseries only supports 0, 1, 2, 4
 */
typedef enum
{
   RCC_outputPrescaler_0  = 0x00,
   RCC_outputPrescaler_1  = 0x01,
   RCC_outputPrescaler_2  = 0x02,
   RCC_outputPrescaler_4  = 0x03
#if ((HML_CLOCK_OUTPUT_TYPE == SYSTEMCLOCK) && \
     (HML_MCU_MODEL_SUBSERIES != MCU_SUBSERIES_STC15W401AS))
,
   RCC_outputPrescaler_16 = 0x04  /* 1/16 */
#endif
} RCC_outputPrescaler;

/**
 * \brief Define boot area
 */
typedef enum
{
    RCC_bootMode_ap  = 0x0,       /* boot from application area */
    RCC_bootMode_iap = 0x1        /* boot from IAP area */
} RCC_bootMode;

#if (HML_SUPPORT_SELECT_CLOCK_OUTPUT_PIN == 1)
/**
 * \brief Define clock output pin
 * \note  Main clock ouput pin can be set as MCLKO or MCLKO_2. MCUs with 8-pin,
 *        such as STC15F100W subseries, output via MCLCKO(P34); STC15F2K60S2,
 *        STC15W201S, STC15F408AD subseries output via MCLKO(P54); STC15W404S
 *        and STC15W1K16S subseries support MCLKO(P54) and MCLKO2(P16).
 * \note  Clock output pin can be set as SYSCLKO or SYSCLKO_2 for all MCUs support
 *        output system clock. 
 */
typedef enum
{
    RCC_clockOutputPin_primary = 0x0,  /* MLCKO/SYSCLKO */
    RCC_clockOutputPin_backup  = 0x1   /* MLCKO_2/SYSCLKO_2 */
} RCC_clockOutputPin;
#endif

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void RCC_clearResetFlag(void);
FunctionalState RCC_getResetFlag(void);
void RCC_reset(void);
void RCC_setBootMode(RCC_bootMode mode);
void RCC_setClockDivisionFactor(RCC_prescaler d);

#if (HML_SUPPORT_SELECT_CLOCK_OUTPUT_PIN == 1)
void RCC_setClockOutputPin(RCC_clockOutputPin pin);
void RCC_setClockOutputDivsionFactor(RCC_outputPrescaler d);
#endif

#endif
