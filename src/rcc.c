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

#endif
