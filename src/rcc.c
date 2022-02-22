/*****************************************************************************/
/** 
 * \file        rcc.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operation for reset and clock control
 * \note        
 * \version     v0.2
 * \ingroup     RCC
******************************************************************************/

#include "hml/rcc.h"

#ifdef COMPILE_RCC

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2021/03/08
 * \brief       clear reset flag
 * \param[in]   none
 * \return      
 * \ingroup     RCC
 * \remarks     clear POF bit of PCON register
******************************************************************************/
void RCC_clearResetFlag(void)
{
    CLR_BIT_MASK(PCON, POF);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/11/09
 * \brief       obtain reset flag
 * \param[in]   none
 * \return      value of POF bit
 * \ingroup     RCC
 * \remarks     POF bit can help user judge MCU reset action. If the value is 
 *              equal to SET, it means the reset action is cold start. Otherwise
 *              it's a hot start. User shoul clear reset flag before using it.
******************************************************************************/
FunctionalState RCC_getResetFlag(void)
{
    return (FunctionalState)(GET_BIT(PCON, POF));
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/11/09
 * \brief       set division factor of main clock
 * \param[in]   val: division factor
 * \return      none
 * \ingroup     RCC
 * \remarks     system clock comes from main clock(MCLK) via prescaler. MCLK may
 *              be internal RC oscillating circuit or external crystal oscillator
******************************************************************************/
void RCC_reset(void)
{
    SET_BIT_MASK(IAP_CONTR, SWRST);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2022/02/22
 * \brief       set boot mode
 * \param[in]   mode: expected mode
 * \return      none
 * \ingroup     RCC
 * \remarks     
******************************************************************************/
void RCC_setBootMode(RCC_bootMode mode)
{
    CONFB(IAP_CONTR, BIT_NUM_SWBS, mode);
}

#if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W404S) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K16S)
/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        2022/02/22
 * \brief       set main clock output pin(some models support)
 * \param[in]   pin: expected pin
 * \return      none
 * \ingroup     RCC
 * \remarks     Main clock can output via Pin MCLKO/MCLKO_2. STC15 MCU with 8-pin
 *              output via P34(MCLKO), and STC15F2k60S2/STC15W201S/STC15F408AD
 *              subseries output via P54(MCLKO). Especially, STC15W404S/STC15W1K16S
 *              subseries support P54(MCLKO) or P16(MCLKO_2). These MCUs can not
 *              support output system clock.
******************************************************************************/
void RCC_setMainClockOutputPin(RCC_mclkOutputPin pin)
{
    CONFB(PCON2, BIT_NUM_MCLKO_2, pin); 
}
#endif

#if (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W4K32S4) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W401AS ) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K08PWM ) || \
    (HML_MCU_MODEL_SUBSERIES == MCU_SUBSERIES_STC15W1K20S)
/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        2022/02/22
 * \brief       set system clock output pin(some models support)
 * \param[in]   pin: expected pin
 * \return      none
 * \ingroup     RCC
 * \remarks     STC15W4K32S4/STC15W401AS/STC15W1K08PWM/STC15W1K20S(LQFP) support
 *              output sytem clock via P54(SYSCLKO)/P16(SYSCLKO_2) which depends
 *              on control bit SYSCLKO_2 in register PCON2(CLK_DIV). These MCUs
 *              can not output main clock.
******************************************************************************/
void RCC_setSystemClockOutputPin(RCC_sysclkOutputPin pin)
{
    CONFB(PCON2, BIT_NUM_SYSCLKO_2, pin);
}
#endif

#endif
