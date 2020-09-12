/*****************************************************************************/
/** 
 * \file        gpio_toggleIo.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       a example which shows how to toggle state of specified IO
 * \note        
 * \version     v0.0
 * \ingroup     example
 * \remarks     test-board: ELH(黑灵) STC15F board; test-MCU: STC15F2K60S2
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief LED is connected to P35 on target board
 */
#define PIN_LED    PERIPH_GPIO_PIN_5

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/09
 * \brief       init MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    GPIO_configTypeDef gc;

    gc.pin   = PIN_LED;
    gc.mode  = GPIO_mode_PP;
    gc.value = RESET;
    GPIO_config(PERIPH_GPIO_3, &gc);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/03
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void main(void)
{
    sys_init();

    /**
     * \brief blink LED
     */
    while(true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_3, PIN_LED);
    }
}
