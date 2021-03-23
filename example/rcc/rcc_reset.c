/*****************************************************************************/
/** 
 * \file        gpio_toggleIo.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       a example which shows software reset function
 * \note        
 * \version     v0.0
 * \ingroup     example
 * \remarks     test-board: FD51F_DB_V2.0; test-MCU: IAP15F2K61S2
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
 * \date        2020/11/09
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
    gc.value = SET;
    GPIO_config(PERIPH_GPIO_0, &gc);
    GPIO_configPortValue(PERIPH_GPIO_0, 0xFF);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/11/09
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void main(void)
{
    uint8_t i = 0;

    sys_init();

    /**
     * \brief blink LED in the beginning
     */
    for (i = 6; i > 0; i--)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_0, PIN_LED);
    }

    /**
     * \brief reset after 3 seconds
     */
    sleep(3000);
    RCC_reset();

    while(true);
}
