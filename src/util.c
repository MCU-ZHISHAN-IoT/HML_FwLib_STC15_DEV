  /*****************************************************************************/
/**
 * \file        util.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       public operations
 * \note        
 * \version     v0.0
 * \ingroup     UTIL
******************************************************************************/

#include "hml/util.h"

#ifdef COMPILE_UTIL

/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        2020/09/01
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
 * \date        2020/09/01
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

/*****************************************************************************/
/**
 * \author      Qiyuan Chen & Jiabin Hsu
 * \date        2020/01/28
 * \brief       get _sleep_1ms initial value
 * \param[in]   none
 * \return      none
 * \ingroup     UTIL
 * \remarks     private function, don' use it
******************************************************************************/
uint16_t _sleep_getInitValue(void)
{
    return 0xFFFF - ((__CONF_FRE_CLKIN/(float)1000/16) - 1);
}

/*****************************************************************************/
/**
 * \author      Jiabin Hsu
 * \date        2020/09/11
 * \brief       sleep 1 ms
 * \param[in]   none
 * \return      none
 * \ingroup     UTIL
 * \remarks     private function, don' use it
******************************************************************************/
void _sleep_1ms(void)
{
    __asm
        push dpl                    ;#3
        push dph                    ;#3
        mov dpl, r6                 ;#2
        mov dph, r7                 ;#2
    delay1ms_loop$:
        inc dptr                    ;#1
        mov a,dpl                   ;#2
        anl a,dph                   ;#2
        cpl a                       ;#1
        nop                         ;#1
        nop                         ;#1
        nop                         ;#1
        nop                         ;#1
        nop                         ;#1
        nop                         ;#1
        jnz delay1ms_loop$          ;#4

        pop dph                     ;#2
        pop dpl                     ;#2

        ret                         ;#4
    __endasm;
}

/*****************************************************************************/
/**
 * \author      Jiabin Hsu
 * \date        2020/09/11
 * \brief       software delay according to MCU clock frequency
 * \param[in]   t: how many one ms you want to delay
 * \return      none
 * \ingroup     UTIL
 * \remarks
******************************************************************************/
void sleep(uint16_t t)
{
    __asm
        push ar5
        push ar6
        push ar7

        push dph
        push dpl

    ; freq -> r6,r7
        lcall __sleep_getInitValue
        mov ar6,dpl
        mov ar7,dph

    ; t -> dptr
        pop dpl
        pop dph

    ; 0xFFFF - t
        clr c
        mov a,#0xFF
        subb a,dpl
        mov dpl,a
        mov a,#0xFF
        subb a,dph
        mov dph,a

    ; return if time equals 0
        mov a,dpl
        anl a,dph
        cpl a
        jz ENDL$

    ; loop for sleep
    ; loop from (0xFFFF - t) to (0xFFFF)
    LOOP$:
        lcall __sleep_1ms               ;#16 * ((__CONF_FRE_CLKIN/(float)1000/16) - 2) + 18
        inc dptr                        ;#1
        mov a,dpl                       ;#2
        anl a,dph                       ;#2
        cpl a                           ;#1
        nop                             ;#1
        nop                             ;#1
        nop                             ;#1
        nop                             ;#1
        nop                             ;#1
        nop                             ;#1
        jnz LOOP$                       ;#2
    ENDL$:
        pop ar7
        pop ar6
        pop ar5
        ret
    __endasm;

    /**
     * \note disable SDCC warning
     */
    t = 0;
}

#endif
