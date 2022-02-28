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

static uint8_t df = 0x1;       /* mark current divided factor */

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
 * \brief       reset
 * \param[in]   none
 * \return      none
 * \ingroup     RCC
 * \remarks     software reset
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

/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        2022/02/27
 * \brief       set division factor of main clock(SYSCLK = MCLK/PRESCALER)
 * \param[in]   d: division factor
 * \return      none
 * \ingroup     RCC
 * \remarks
******************************************************************************/
void RCC_setClockDivisionFactor(RCC_prescaler d)
{
    CLR_BIT_MASK(CLK_DIV, CLKS2 | CLKS1 | CLKS0);
    CLK_DIV = CLK_DIV | (byte)d; 
    df = 0x01 << d;
}

#if (HML_SUPPORT_SELECT_CLOCK_OUTPUT_PIN == 1)
/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        2022/02/22
 * \brief       set clock output pin
 * \param[in]   pin: expected pin
 * \return      none
 * \ingroup     RCC
 * \remarks     
******************************************************************************/
void RCC_setClockOutputPin(RCC_clockOutputPin pin)
{
    CONFB(PCON2, BIT_NUM_MCLKO_2, pin);
}

/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        2022/02/28
 * \brief       set clock output division factor
 * \param[in]   d: expected division factor
 * \return      none
 * \ingroup     RCC
 * \remarks
******************************************************************************/
void RCC_setClockOutputDivsionFactor(RCC_outputPrescaler d)
{
    /* config MCKO_S1 and MCKO_S2 */
    CLK_DIV = (CLK_DIV & (~(MCKO_S1 | MCKO_S0))) | ((d & 0x03) << 0x06);

#if ((HML_CLOCK_OUTPUT_TYPE == SYSTEMCLOCK) && \
     (HML_MCU_MODEL_SUBSERIES != MCU_SUBSERIES_STC15W401AS))
    /* config SYSCKO_S2 */
    AUXR2 = (AUXR & (~SYSCKO_S2)) | ((d & 0x04) << 0x01);
#endif
}

#endif

#endif
