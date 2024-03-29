/*****************************************************************************/
/** 
 * \file        conf.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML configurations, this file need to be modified by users
 * \note        
 * \version     v0.0
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_CONF_H___
#define ___HML_CONF_H___

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief Configure clock frequency of MCU
 */
#ifndef __CONF_FRE_CLKIN
    #warning no specified clock frequency, HML will fill it with '11.0592MHz'
    #define __CONF_FRE_CLKIN 11059200UL
#endif

/**
 * \brief Configure module of MCU
 */
#ifndef __CONF_MCU_MODEL
    #warning no specified MCU model, HML will fill it with 'STC15F2K60S2'
    #define __CONF_MCU_MODEL MCU_MODEL_STC15F2K60S2
#endif

/**
 * \brief Define MCU packaging
 */
#ifndef __CONF_MCU_PACKAGING
    #warning no specified MCU packaging, HML will fill it with 'LQFP'
    #define __CONF_MCU_PACKAGING LQFP
#endif

/**
 * \brief Select HML module which take part in compilation
 */
#define __CONF_COMPILE_EXTI  1
#define __CONF_COMPILE_GPIO  1
#define __CONF_COMPILE_IAP   1
#define __CONF_COMPILE_MEM   1
#define __CONF_COMPILE_RCC   1
#define __CONF_COMPILE_TIM   1
#define __CONF_COMPILE_TIM2  1
#define __CONF_COMPILE_UART  1
#define __CONF_COMPILE_UTIL  1
#define __CONF_COMPILE_WDT   1

#endif
