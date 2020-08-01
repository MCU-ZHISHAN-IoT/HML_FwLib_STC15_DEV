  /*****************************************************************************/
/**
 * \file        util.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       public operations
 * \note        
 * \version     v1.2
 * \ingroup     UTIL
******************************************************************************/

#include "hml/util.h"

/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        
 * \brief       disable master switch of MCU interrupt
 * \param[in]   
 * \return      none
 * \ingroup     UTIL
 * \remarks     
******************************************************************************/
void disableAllInterrupts(void)
{
    EA = DISABLE;
}

/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        
 * \brief       enable master switch of MCU interrupt
 * \param[in]   
 * \return      none
 * \ingroup     UTIL
 * \remarks     
******************************************************************************/
void enableAllInterrupts(void)
{
    EA = ENABLE;
}
