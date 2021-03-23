/*****************************************************************************/
/** 
 * \file        pwr.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operation for power control
 * \note        
 * \version     v0.0
 * \ingroup     PWR
******************************************************************************/

#ifndef ___PWR_H___
#define ___PWR_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/stc15.h"
#include "hml/macro.h"
#include "hml/types.h"

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void PWR_setPowerSavingMode(PWR_powerSavingMode mode);
void PWR_LVD_cmd(Action a);
void PWR_LVD_setInterruptPriority(Action a);
FunctionalState PWR_LVD_getFlag(void);

#endif
