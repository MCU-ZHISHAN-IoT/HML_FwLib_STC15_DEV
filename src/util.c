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
 * \date        2022/02/26
 * \brief       get _sleep_1ms initial value
 * \param[in]   none
 * \return      none
 * \ingroup     UTIL
 * \remarks     private function, don' use it
******************************************************************************/
uint16_t _sleep_getInitValue(void)
{
    return (uint16_t)(MCU_FRE_CLK/(float)1000/5) - 18;
}

/*****************************************************************************/
/**
 * \author      Jiabin Hsu
 * \date        2022/01/27
 * \brief       sleep 1 ms, at STC-Y5 instruction set
 * \param[in]   none
 * \return      none
 * \ingroup     UTIL
 * \remarks     private function, don' use it
******************************************************************************/
void _sleep_1ms(void)
{
    __asm
        push ar6                    ;#3 low
        push ar7                    ;#3 high
        inc  ar7                    ;#3
    delay1ms_loop$:
        djnz ar6,delay1ms_loop$     ;#5
        djnz ar7,delay1ms_loop$     ;#5
        pop ar7                     ;#2
        pop ar6                     ;#2
        ret                         ;#4
    __endasm;
}

/*****************************************************************************/
/**
 * \author      Jiabin Hsu
 * \date        2022/02/26
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
        lcall __sleep_1ms               ;#5*(ar7*(256 + 1) + ar6)  _sleep_1ms
                                        ;#4                        lcall
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
        nop                             ;#1
        nop                             ;#1
        nop                             ;#1
        jnz LOOP$                       ;#4
    ENDL$:
        pop ar7
        pop ar6
        pop ar5
        ret
    __endasm;

    UNUSED(t);
}

#endif
