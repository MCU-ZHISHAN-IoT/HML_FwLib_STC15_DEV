/*****************************************************************************/
/** 
 * \file        gpio.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operations for GPIO module
 * \note        
 * \version     v0.0
 * \ingroup     GPIO
******************************************************************************/

#include "hml/gpio.h"

#ifdef COMPILE_GPIO

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/03
 * \brief       configure target GPIO port
 * \param[in]   gpio: target GPIO port
 * \param[in]   gc  : configuration struct stores all information
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_config(PERIPH_GPIO gpio, GPIO_configTypeDef *gc)
{
    GPIO_configMode(gpio, gc->pin, gc->mode);
    GPIO_configPortValue(gpio, gc->value);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/01
 * \brief       configure state of target GPIO bit as SET or RESET
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \param[in]   f   : expected state
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_configBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin, FunctionalState f)
{
    if(f == RESET)
    {
        GPIO_resetBitValue(gpio,pin);
    }
    else
    {
        GPIO_setBitValue(gpio,pin);
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/08/30
 * \brief       configure work mode of target GPIO bit
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \param[in]   mode: expected work mode
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_configMode(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin, GPIO_mode mode)
{
    byte m0 = 0x00;     /* store mode bits */
    byte m1 = 0x00;

    /**
     * \note obtain mode bit
     */
    m0 = (TESTB(mode, 0)?pin:(~pin)) & pin;
    m1 = (TESTB(mode, 1)?pin:(~pin)) & pin;

    switch(gpio)
    {
        /* P0 */
        case PERIPH_GPIO_0:
        {
            P0M0 = P0M0 & (~pin) | m0;
            P0M1 = P0M1 & (~pin) | m1;
        } break;
        /* P1 */
        case PERIPH_GPIO_1:
        {
            P1M0 = P1M0 & (~pin) | m0;
            P1M1 = P1M1 & (~pin) | m1;
        } break;
        /* P2 */
        case PERIPH_GPIO_2:
        {
            P2M0 = P2M0 & (~pin) | m0;
            P2M1 = P2M1 & (~pin) | m1;
        } break;
        /* P3 */
        case PERIPH_GPIO_3:
        {
            P3M0 = P3M0 & (~pin) | m0;
            P3M1 = P3M1 & (~pin) | m1;
        } break;
        /* P4 */
        case PERIPH_GPIO_4:
        {
            P4M0 = P4M0 & (~pin) | m0;
            P4M1 = P4M1 & (~pin) | m1;
        } break;
        /* P5 */
        case PERIPH_GPIO_5:
        {
            P5M0 = P5M0 & (~pin) | m0;
            P5M1 = P5M1 & (~pin) | m1;
        } break;
        /* P6 */
        case PERIPH_GPIO_6:
        {
            P6M0 = P6M0 & (~pin) | m0;
            P6M1 = P6M1 & (~pin) | m1;
        } break;
        /* P7 */
        case PERIPH_GPIO_7:
        {
            P7M0 = P7M0 & (~pin) | m0;
            P7M1 = P7M1 & (~pin) | m1;
        } break;
        /* default */
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/08/31
 * \brief       configure value specified GPIO port
 * \param[in]   gpio: target GPIO port
 * \param[in]   val : expected value(0x00~0xFF)
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_configPortValue(PERIPH_GPIO gpio, byte val)
{
    switch(gpio)
    {
        case PERIPH_GPIO_0: P0 = val; break;
        case PERIPH_GPIO_1: P1 = val; break;
        case PERIPH_GPIO_2: P2 = val; break;
        case PERIPH_GPIO_3: P3 = val; break;
        case PERIPH_GPIO_4: P4 = val; break;
        case PERIPH_GPIO_5: P5 = val; break;
        case PERIPH_GPIO_6: P6 = val; break;
        case PERIPH_GPIO_7: P7 = val; break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/01
 * \brief       get state of target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      SET or RESET
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch(gpio)
    {
        case PERIPH_GPIO_0: return GET_BIT(P0, pin);
        case PERIPH_GPIO_1: return GET_BIT(P1, pin);
        case PERIPH_GPIO_2: return GET_BIT(P2, pin);
        case PERIPH_GPIO_3: return GET_BIT(P3, pin);
        case PERIPH_GPIO_4: return GET_BIT(P4, pin);
        case PERIPH_GPIO_5: return GET_BIT(P5, pin);
        case PERIPH_GPIO_6: return GET_BIT(P6, pin);
        case PERIPH_GPIO_7: return GET_BIT(P7, pin);
        default: return RESET;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/01
 * \brief       get value of target GPIO port
 * \param[in]   gpio: target GPIO port
 * \return      current value of target GPIO port
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
byte GPIO_getPortValue(PERIPH_GPIO gpio)
{
    switch(gpio)
    {
        case PERIPH_GPIO_0: return P0;
        case PERIPH_GPIO_1: return P1;
        case PERIPH_GPIO_2: return P2;
        case PERIPH_GPIO_3: return P3;
        case PERIPH_GPIO_4: return P4;
        case PERIPH_GPIO_5: return P5;
        case PERIPH_GPIO_6: return P6;
        case PERIPH_GPIO_7: return P7;
        default: return 0x00;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/01
 * \brief       reset target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_resetBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch(gpio)
    {
        case PERIPH_GPIO_0: CLR_BIT_MASK(P0, pin); break;
        case PERIPH_GPIO_1: CLR_BIT_MASK(P1, pin); break;
        case PERIPH_GPIO_2: CLR_BIT_MASK(P2, pin); break;
        case PERIPH_GPIO_3: CLR_BIT_MASK(P3, pin); break;
        case PERIPH_GPIO_4: CLR_BIT_MASK(P4, pin); break;
        case PERIPH_GPIO_5: CLR_BIT_MASK(P4, pin); break;
        case PERIPH_GPIO_6: CLR_BIT_MASK(P4, pin); break;
        case PERIPH_GPIO_7: CLR_BIT_MASK(P4, pin); break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/01
 * \brief       set target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_setBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch(gpio)
    {
        case PERIPH_GPIO_0: SET_BIT_MASK(P0, pin); break;
        case PERIPH_GPIO_1: SET_BIT_MASK(P1, pin); break;
        case PERIPH_GPIO_2: SET_BIT_MASK(P2, pin); break;
        case PERIPH_GPIO_3: SET_BIT_MASK(P3, pin); break;
        case PERIPH_GPIO_4: SET_BIT_MASK(P4, pin); break;
        case PERIPH_GPIO_5: SET_BIT_MASK(P5, pin); break;
        case PERIPH_GPIO_6: SET_BIT_MASK(P6, pin); break;
        case PERIPH_GPIO_7: SET_BIT_MASK(P7, pin); break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/09/01
 * \brief       toggle state of target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_toggleBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch(gpio)
    {
        case PERIPH_GPIO_0: NOT_BIT_MASK(P0, pin); break;
        case PERIPH_GPIO_1: NOT_BIT_MASK(P1, pin); break;
        case PERIPH_GPIO_2: NOT_BIT_MASK(P2, pin); break;
        case PERIPH_GPIO_3: NOT_BIT_MASK(P3, pin); break;
        case PERIPH_GPIO_4: NOT_BIT_MASK(P4, pin); break;
        case PERIPH_GPIO_5: NOT_BIT_MASK(P5, pin); break;
        case PERIPH_GPIO_6: NOT_BIT_MASK(P6, pin); break;
        case PERIPH_GPIO_7: NOT_BIT_MASK(P7, pin); break;
        default: break;
    }
}

#endif
