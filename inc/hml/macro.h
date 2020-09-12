
/*****************************************************************************/
/** 
 * \file        macro.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML macro define
 * \note        
 * \version     v0.0
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_MACRO_H___
#define ___HML_MACRO_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/conf.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief Subseries define of STC15 MCU
 */
#define MCU_SUBSERIES_STC15F2K60S2     0x01
#define MCU_SUBSERIES_STC15W100        0x02
#define MCU_SUBSERIES_STC15W10X        0x03
#define MCU_SUBSERIES_STC15W201S       0x04
#define MCU_SUBSERIES_STC15W401S       0x05
#define MCU_SUBSERIES_STC15W404S       0x06
#define MCU_SUBSERIES_STC15W1K61S      0x07
#define MCU_SUBSERIES_STC15W1K08PWM    0x08
#define MCU_SUBSERIES_STC15W1K20S      0x09
#define MCU_SUBSERIES_STC15W4K32S4     0x0A
#define MCU_SUBSERIES_STC15F408AD      0x0B

/**
 * \brief mark MCU model of STC15 series
 */
#define MCU_MODEL_GENERIC              0x01

/* STC15F2K60S2 subseries */
#define MCU_MODEL_STC15F2K08S2         0x02
#define MCU_MODEL_STC15F2K16S2         0x03
#define MCU_MODEL_STC15F2K32S2         0x04
#define MCU_MODEL_STC15F2K40S2         0x05
#define MCU_MODEL_STC15F2K48S2         0x06
#define MCU_MODEL_STC15F2K56S2         0x07
#define MCU_MODEL_STC15F2K60S2         0x08
#define MCU_MODEL_IAP15F2K61S2         0x09
#define MCU_MODEL_IRC15F2K63S2         0x0A
#define MCU_MODEL_STC15F2K32S          0x0B
#define MCU_MODEL_STC15F2K60S          0x0C
#define MCU_MODEL_IAP15F2K61S          0x0D
#define MCU_MODEL_STC15F2K24AS         0x0E
#define MCU_MODEL_STC15F2K48AS         0x0F

#define MCU_MODEL_STC15L2K08S2         0x10
#define MCU_MODEL_STC15L2K16S2         0x11
#define MCU_MODEL_STC15L2K24S2         0x12
#define MCU_MODEL_STC15L2K32S2         0x13
#define MCU_MODEL_STC15L2K40S2         0x14
#define MCU_MODEL_STC15L2K48S2         0x15
#define MCU_MODEL_STC15L2K56S2         0x16
#define MCU_MODEL_STC15L2K60S2         0x17
#define MCU_MODEL_IAP15L2K61S2         0x18
#define MCU_MODEL_STC15L2K32S          0x19
#define MCU_MODEL_STC15L2K60S          0x1A
#define MCU_MODEL_IAP15L2K61S          0x1B
#define MCU_MODEL_STC15L2K24AS         0x1C
#define MCU_MODEL_STC15L2K48AS         0x1D

/* STC15W100 subseries */
#define MCU_MODEL_STC15F100W           0x20
#define MCU_MODEL_STC15F101W           0x21
#define MCU_MODEL_STC15F102W           0x22
#define MCU_MODEL_STC15F103W           0x23
#define MCU_MODEL_STC15F104W           0x24
#define MCU_MODEL_IAP15F105W           0x25
#define MCU_MODEL_IRC15F107W           0x26

#define MCU_MODEL_STC15L100W           0x27
#define MCU_MODEL_STC15L101W           0x28
#define MCU_MODEL_STC15L102W           0x29
#define MCU_MODEL_STC15L104W           0x2A
#define MCU_MODEL_IAP15L105W           0x2B

/* STC15W10x subseries */
#define MCU_MODEL_STC15W100            0x30
#define MCU_MODEL_STC15W101            0x31
#define MCU_MODEL_STC15W102            0x32
#define MCU_MODEL_STC15W103            0x33
#define MCU_MODEL_STC15W104            0x34
#define MCU_MODEL_IAP15W105            0x35
#define MCU_MODEL_IRC15W107            0x36

/* STC15W201S subseries */
#define MCU_MODEL_STC15W201S           0x40
#define MCU_MODEL_STC15W202S           0x41
#define MCU_MODEL_STC15W203S           0x42
#define MCU_MODEL_STC15W204S           0x43
#define MCU_MODEL_IAP15W205S           0x44
#define MCU_MODEL_IRC15W207S           0x45

/* STC15W401S subseries */
#define MCU_MODEL_STC15W401AS          0x50
#define MCU_MODEL_STC15W402AS          0x51
#define MCU_MODEL_STC15W404AS          0x52
#define MCU_MODEL_STC15W408AS          0x53
#define MCU_MODEL_IAP15W413AS          0x54
#define MCU_MODEL_IRC15W415AS          0x55

/* STC15W404S subseries */
#define MCU_MODEL_STC15W404S           0x60
#define MCU_MODEL_STC15W408S           0x61
#define MCU_MODEL_STC15W410S           0x62
#define MCU_MODEL_IAP15W413S           0x63
#define MCU_MODEL_IRC15W415S           0x64

/* STC15W1K61S subseries */
#define MCU_MODEL_STC15W1K16S          0x70
#define MCU_MODEL_STC15W1K24S          0x71
#define MCU_MODEL_IAP15W1K29S          0x72
#define MCU_MODEL_IRC15W1K31S          0x73

/* STC15W1K08PWM subseries */
#define MCU_MODEL_STC15W1K08PWM        0x80
#define MCU_MODEL_STC15W1K16PWM        0x81

/* STC15W1K20S subseries */
#define MCU_MODEL_STC15W1K20S          0x90

/* STC15W4K32S4 subseries */
#define MCU_MODEL_STC15W4K16S4         0xA0
#define MCU_MODEL_STC15W4K32S4         0xA1
#define MCU_MODEL_STC15W4K40S4         0xA2
#define MCU_MODEL_STC15W4K48S4         0xA3
#define MCU_MODEL_STC15W4K56S4         0xA4
#define MCU_MODEL_IAP15W4K58S4         0xA5
#define MCU_MODEL_IAP15W4K61S4         0xA6
#define MCU_MODEL_IRC15W4K63S4         0xA7

/* STC15F408AD subseries */
#define MCU_MODEL_STC15F408AD          0xB0
#define MCU_MODEL_IAP15F413AD          0xB1
#define MCU_MODEL_STC15L408AD          0xB2
#define MCU_MODEL_IAP15L413AD          0xB3

/**
 * \brief check macro for MCU model
 */
#define IS_STC15F2K60S2_SUBSERIES(model)         ((model >= MCU_MODEL_STC15F2K08S2) && (model <= MCU_MODEL_STC15L2K48AS))
#define IS_STC15W100_SUBSERIES(model)            ((model >= MCU_MODEL_STC15F100W) && (model <= MCU_MODEL_IAP15L105W))
#define IS_STC15W10X_SUBSERIES(model)            ((model >= MCU_MODEL_STC15W100) && (model <= MCU_MODEL_IRC15W107))
#define IS_STC15W201S_SUBSERIES(model)           ((model >= MCU_MODEL_STC15W201S) && (model <= MCU_MODEL_IRC15W207S))
#define IS_STC15W401S_SUBSERIES(model)           ((model >= MCU_MODEL_STC15W401AS) && (model <= MCU_MODEL_IRC15W415AS))
#define IS_STC15W404S_SUBSERIES(model)           ((model >= MCU_MODEL_STC15W404S) && (model <= MCU_MODEL_IRC15W415S))
#define IS_STC15W1K61S_SUBSERIES(model)          ((model >= MCU_MODEL_STC15W1K16S) && (model <= MCU_MODEL_IRC15W1K31S))
#define IS_STC15W1K08PWM_SUBSERIES(model)        ((model == MCU_MODEL_STC15W1K08PWM) || (model == MCU_MODEL_STC15W1K16PWM))
#define IS_STC15W1K20S_SUBSERIES(model)          (model == MCU_MODEL_STC15W1K20S)
#define IS_STC15W4K32S4_SUBSERIES(model)         ((model == MCU_MODEL_STC15W4K16S4) || (model == MCU_MODEL_IRC15W4K63S4))
#define IS_STC15F408AD_SUBSERIES(model)          ((model == MCU_MODEL_STC15F408AD) || (model == MCU_MODEL_IAP15L413AD))

/**
 * \brief compile select
 */
#if (__CONF_COMPILE_EXTI == 1)
    #define COMPILE_EXTI
#endif
#if (__CONF_COMPILE_GPIO == 1)
    #define COMPILE_GPIO
#endif
#if (__CONF_COMPILE_IAP == 1)
    #define COMPILE_IAP
#endif
#if (__CONF_COMPILE_UTIL == 1)
    #define COMPILE_UTIL
#endif

/*****************************************************************************
 *                           run-time check                                  *
 *****************************************************************************/

/**
 * \brief MCU model check
 */
#if (defined __CONF_MCU_MODEL)
    #if (__CONF_MCU_MODEL == MCU_MODEL_GENERIC)
        #warning the value of macro HML_MCU_MODEL will be filled with MCU_MODEL_STC15F2K60S2
        #undef __CONF_MCU_MODEL
        #define __CONF_MCU_MODEL MCU_MODEL_STC15F2K60S2
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15F2K60S2
    #elif IS_STC15F2K60S2_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15F2K60S2
    #elif IS_STC15W100_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W100
    #elif IS_STC15W10X_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W10X
    #elif IS_STC15W201S_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W201S
    #elif IS_STC15W401S_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W401S
    #elif IS_STC15W404S_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W404S
    #elif IS_STC15W1K61S_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W1K61S
    #elif IS_STC15W1K08PWM_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W1K08PWM
    #elif IS_STC15W1K20S_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W1K20S
    #elif IS_STC15W4K32S4_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15W4K32S4
    #elif IS_STC15F408AD_SUBSERIES(__CONF_MCU_MODEL)
        #define HML_MCU_MODEL_SUBSERIES MCU_SUBSERIES_STC15F408AD
    #else
        #error HML run-time check: error: unknow or unsupported MCU model!(ERROR_CODE-0x03)
    #endif
    #define HML_MCU_MODEL __CONF_MCU_MODEL
#else
    #error HML run-time check: error: unspecify MCU model!(ERROR_CODE-0x04)
#endif

/**
 * \brief SDCC version check
 */
#if (__SDCC_VERSION_MAJOR == 3)
    #if (__SDCC_VERSION_MINOR < 6)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x07)
    #endif
#else
    #if (__SDCC_VERSION_MAJOR < 3)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x07)
    #endif
#endif

#endif
