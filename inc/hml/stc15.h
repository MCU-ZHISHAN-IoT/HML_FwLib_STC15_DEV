/*****************************************************************************/
/** 
 * \file        stc15.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       register and interrupt vector define for STC15/IAP15 series MCU
 * \note        
 * \version     
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_STC15_H___
#define ___HML_STC15_H___

#include <8051.h>
#include "hml/bit.h"

/*  BYTE Register  */
__sfr __at (0x84) S4CON      ;
__sfr __at (0x85) S4BUF      ;
__sfr __at (0x87) PCON       ;
__sfr __at (0x8E) AUXR       ;
__sfr __at (0x8F) AUXR2      ;
    #define INT_CLKO AUXR2   /* AUXR2's alias */
__sfr __at (0x91) P1M1       ;
__sfr __at (0x92) P1M0       ;
__sfr __at (0x93) P0M1       ;
__sfr __at (0x94) P0M0       ;
__sfr __at (0x95) P2M1       ;
__sfr __at (0x96) P2M0       ;
__sfr __at (0x97) PCON2      ;
    #define CLK_DIV PCON2    /* PCON2's alias */
__sfr __at (0x9A) S2CON      ;
__sfr __at (0x9B) S2BUF      ;
__sfr __at (0x9D) P1ASF      ;
__sfr __at (0xA1) BUS_SPEED  ;
__sfr __at (0xA2) AUXR1      ;
    #define P_SW1 AUXR1      /* AUXR1's alias */
__sfr __at (0xA9) SADDR      ;
__sfr __at (0xAA) WKTCL      ;
    #define WKTCL_CNT WKTCL  /* WKTCL's alias */
__sfr __at (0xAB) WKTCH      ;
    #define WKTCH_CNT WKTCH  /* WKTCH's alias */
__sfr __at (0xAC) S3CON      ;
__sfr __at (0xAD) S3BUF      ;
__sfr __at (0xAF) IE2        ;
__sfr __at (0xB1) P3M1       ;
__sfr __at (0xB2) P3M0       ;
__sfr __at (0xB3) P4M1       ;
__sfr __at (0xB4) P4M0       ;
__sfr __at (0xB5) IP2        ;
__sfr __at (0xB9) SADEN      ;
__sfr __at (0xBA) P_SW2      ;
__sfr __at (0xBC) ADC_CONTR  ;
__sfr __at (0xBD) ADC_RES    ;
__sfr __at (0xBE) ADC_RESL   ;
__sfr __at (0xC0) P4         ;
__sfr __at (0xC1) WDT_CONTR  ;
__sfr __at (0xC2) IAP_DATA   ;
__sfr __at (0xC3) IAP_ADDRH  ;
__sfr __at (0xC4) IAP_ADDRL  ;
__sfr __at (0xC5) IAP_CMD    ;
__sfr __at (0xC6) IAP_TRIG   ;
__sfr __at (0xC7) IAP_CONTR  ;
__sfr __at (0xC8) P5         ;
__sfr __at (0xC9) P5M1       ;
__sfr __at (0xCA) P5M0       ;
__sfr __at (0xCB) P6M1       ;
__sfr __at (0xCC) P6M0       ;
__sfr __at (0xCD) SPSTAT     ;
__sfr __at (0xCE) SPCTL      ;
__sfr __at (0xCF) SPDAT      ;
__sfr __at (0xD1) T4T3M      ;
__sfr __at (0xD2) T4H        ;
__sfr __at (0xD3) T4L        ;
__sfr __at (0xD4) T3H        ;
__sfr __at (0xD5) T3L        ;
__sfr __at (0xD6) T2H        ;
__sfr __at (0xD7) T2L        ;
__sfr __at (0xD8) CCON       ;
__sfr __at (0xD9) CMOD       ;
__sfr __at (0xDA) CCAPM0     ;
__sfr __at (0xDB) CCAPM1     ;
__sfr __at (0xDC) CCAPM2     ;
__sfr __at (0xE1) P7M1       ;
__sfr __at (0xE2) P7M0       ;
__sfr __at (0xE8) P6         ;
__sfr __at (0xE9) CL         ;
__sfr __at (0xEA) CCAP0L     ;
__sfr __at (0xEB) CCAP1L     ;
__sfr __at (0xEC) CCAP2L     ;
__sfr __at (0xF1) PWMCFG     ;
__sfr __at (0xF2) PCA_PWM0   ;
__sfr __at (0xF3) PCA_PWM1   ;
__sfr __at (0xF4) PCA_PWM2   ;
__sfr __at (0xF5) PWMCR      ;
__sfr __at (0xF6) PWMIF      ;
__sfr __at (0xF6) PWMFDCR    ;
__sfr __at (0xF8) P7         ;
__sfr __at (0xF9) CH         ;
__sfr __at (0xFA) CCAP0H     ;
__sfr __at (0xFB) CCAP1H     ;
__sfr __at (0xFC) CCAP2H     ;

/* extended BYTE Register  */
volatile __xdata __at (0xFF00) unsigned char PWM2T1H  ;
volatile __xdata __at (0xFF01) unsigned char PWM2T1L  ;
volatile __xdata __at (0xFF02) unsigned char PWM2T2H  ;
volatile __xdata __at (0xFF03) unsigned char PWM2T2L  ;
volatile __xdata __at (0xFF04) unsigned char PWM2CR   ;
volatile __xdata __at (0xFF10) unsigned char PWM3T1H  ;
volatile __xdata __at (0xFF11) unsigned char PWM3T1L  ;
volatile __xdata __at (0xFF12) unsigned char PWM3T2H  ;
volatile __xdata __at (0xFF13) unsigned char PWM3T2L  ;
volatile __xdata __at (0xFF14) unsigned char PWM3CR   ;
volatile __xdata __at (0xFF20) unsigned char PWM4T1H  ;
volatile __xdata __at (0xFF21) unsigned char PWM4T1L  ;
volatile __xdata __at (0xFF22) unsigned char PWM4T2H  ;
volatile __xdata __at (0xFF23) unsigned char PWM4T2L  ;
volatile __xdata __at (0xFF24) unsigned char PWM4CR   ;
volatile __xdata __at (0xFF30) unsigned char PWM5T1H  ;
volatile __xdata __at (0xFF31) unsigned char PWM5T1L  ;
volatile __xdata __at (0xFF32) unsigned char PWM5T2H  ;
volatile __xdata __at (0xFF33) unsigned char PWM5T2L  ;
volatile __xdata __at (0xFF34) unsigned char PWM5CR   ;
volatile __xdata __at (0xFF40) unsigned char PWM6T1H  ;
volatile __xdata __at (0xFF41) unsigned char PWM6T1L  ;
volatile __xdata __at (0xFF42) unsigned char PWM6T2H  ;
volatile __xdata __at (0xFF43) unsigned char PWM6T2L  ;
volatile __xdata __at (0xFF44) unsigned char PWM6CR   ;
volatile __xdata __at (0xFF50) unsigned char PWM7T1H  ;
volatile __xdata __at (0xFF51) unsigned char PWM7T1L  ;
volatile __xdata __at (0xFF52) unsigned char PWM7T2H  ;
volatile __xdata __at (0xFF53) unsigned char PWM7T2L  ;
volatile __xdata __at (0xFF54) unsigned char PWM7CR   ;
volatile __xdata __at (0xFFF0) unsigned char PWMCH    ;
volatile __xdata __at (0xFFF1) unsigned char PWMCL    ;
volatile __xdata __at (0xFFF2) unsigned char PWMCKS   ;

/*  BIT Register  */
/* CCON */
__sbit __at (0xD8) CCF0      ;
__sbit __at (0xD9) CCF1      ;
__sbit __at (0xDA) CCF2      ;
__sbit __at (0xDB) CCF3      ;
__sbit __at (0xDE) CR        ;
__sbit __at (0xDF) CF        ;

/* IE */
__sbit __at (0xA5) EADC      ;
__sbit __at (0xA6) ELDV      ;

/* IP */
__sbit __at (0xBD) PADC      ;
__sbit __at (0xBE) PLVD      ;
__sbit __at (0xBF) PPCA      ;

/* P4 */
__sbit __at (0xC0) P4_0      ;
__sbit __at (0xC1) P4_1      ;
__sbit __at (0xC2) P4_2      ;
__sbit __at (0xC3) P4_3      ;
__sbit __at (0xC4) P4_4      ;
__sbit __at (0xC5) P4_5      ;
__sbit __at (0xC6) P4_6      ;
__sbit __at (0xC7) P4_7      ;

/* P5 */
__sbit __at (0xC8) P5_0      ;
__sbit __at (0xC9) P5_1      ;
__sbit __at (0xCA) P5_2      ;
__sbit __at (0xCB) P5_3      ;
__sbit __at (0xCC) P5_4      ;
__sbit __at (0xCD) P5_5      ;
__sbit __at (0xCE) P5_6      ;
__sbit __at (0xCF) P5_7      ;

/* P6 */
__sbit __at (0xE8) P6_0      ;
__sbit __at (0xE9) P6_1      ;
__sbit __at (0xEA) P6_2      ;
__sbit __at (0xEB) P6_3      ;
__sbit __at (0xEC) P6_4      ;
__sbit __at (0xED) P6_5      ;
__sbit __at (0xEE) P6_6      ;
__sbit __at (0xEF) P6_7      ;

/* P7 */
__sbit __at (0xF8) P7_0      ;
__sbit __at (0xF9) P7_1      ;
__sbit __at (0xFA) P7_2      ;
__sbit __at (0xFB) P7_3      ;
__sbit __at (0xFC) P7_4      ;
__sbit __at (0xFD) P7_5      ;
__sbit __at (0xFE) P7_6      ;
__sbit __at (0xFF) P7_7      ;

/* BIT number for bits which don't support bit addressing */
/* ADC_CONTR bits */
#define BIT_NUM_CHS0         0
#define BIT_NUM_CHS1         1
#define BIT_NUM_CHS2         2
#define BIT_NUM_ADC_START    3
#define BIT_NUM_ADC_FLAG     4
#define BIT_NUM_SPEED0       5
#define BIT_NUM_SPEED1       6
#define BIT_NUM_ADC_POWER    7

/* AUXR bits */
#define BIT_NUM_S1ST2        0
#define BIT_NUM_EXTRAM       1
#define BIT_NUM_T2X12        2
#define BIT_NUM_T2_CT2       3
#define BIT_NUM_T2R          4
#define BIT_NUM_UART_M0X6    5
#define BIT_NUM_T1X12        6
#define BIT_NUM_T0X12        7

/* AUXR1 bits */
#define BIT_NUM_DPS          0
#define BIT_NUM_SPI_S0       2
#define BIT_NUM_SPI_S1       3
#define BIT_NUM_CCP_S0       4
#define BIT_NUM_CCP_S1       5
#define BIT_NUM_S1_S0        6
#define BIT_NUM_S1_S1        7

/* AUXR2 bits */
#define BIT_NUM_T0CLKO       0
#define BIT_NUM_T1CLKO       1
#define BIT_NUM_T2CLKO       2
#define BIT_NUM_MCKO_S2      3
#define BIT_NUM_EX2          4
#define BIT_NUM_EX3          5
#define BIT_NUM_EX4          6

/* BUS_SPEED bits */
#define BIT_NUM_EXRTS0       0
#define BIT_NUM_EXRTS1       1

/* CCAPM0 bits */
#define BIT_NUM_ECCF0        0
#define BIT_NUM_PWM0         1
#define BIT_NUM_TOG0         2
#define BIT_NUM_MAT0         3
#define BIT_NUM_CAPN0        4
#define BIT_NUM_CAPP0        5
#define BIT_NUM_ECOM0        6

/* CCAPM1 bits */
#define BIT_NUM_ECCF1        0
#define BIT_NUM_PWM1         1
#define BIT_NUM_TOG1         2
#define BIT_NUM_MAT1         3
#define BIT_NUM_CAPN1        4
#define BIT_NUM_CAPP1        5
#define BIT_NUM_ECOM1        6

/* CCAPM2 bits */
#define BIT_NUM_ECCF2        0
#define BIT_NUM_PWM2         1
#define BIT_NUM_TOG2         2
#define BIT_NUM_MAT2         3
#define BIT_NUM_CAPN2        4
#define BIT_NUM_CAPP2        5
#define BIT_NUM_ECOM2        6

/* CMOD bits */
#define BIT_NUM_ECF          0
#define BIT_NUM_CPS0         1
#define BIT_NUM_CPS1         2
#define BIT_NUM_CIDL         7

/* IAP_CMD bits */
#define BIT_NUM_MS0          0
#define BIT_NUM_MS1          1

/* IAP_CONTR bits */
#define BIT_NUM_WT0          0
#define BIT_NUM_WT1          1
#define BIT_NUM_WT2          2
#define BIT_NUM_CMD_FAIL     4
#define BIT_NUM_SWRST        5
#define BIT_NUM_SWBS         6
#define BIT_NUM_IAPEN        7

/* IE2 bits */
#define BIT_NUM_ES2          0
#define BIT_NUM_ESPI         1
#define BIT_NUM_ET2          2
#define BIT_NUM_ES3          3
#define BIT_NUM_ES4          4
#define BIT_NUM_ET3          5
#define BIT_NUM_ET4          6

/* IP2 bits */
#define BIT_NUM_PS2          0
#define BIT_NUM_PSPI         1
#define BIT_NUM_PPWM         2
#define BIT_NUM_PPWMFD       3
#define BIT_NUM_PX4          4

/* P_SW2 bits */
#define BIT_NUM_S2_S         0
#define BIT_NUM_S3_S         1
#define BIT_NUM_S4_S         2
#define BIT_NUM_EAXSFR       7

/* P1ASF bits */
#define BIT_NUM_P10ASF       0
#define BIT_NUM_P11ASF       1
#define BIT_NUM_P12ASF       2
#define BIT_NUM_P13ASF       3
#define BIT_NUM_P14ASF       4
#define BIT_NUM_P15ASF       5
#define BIT_NUM_P16ASF       6
#define BIT_NUM_P17ASF       7

/* PCA_PWM0 bits */
#define BIT_NUM_EPC0L        0
#define BIT_NUM_EPC0H        1
#define BIT_NUM_EBS0_0       6
#define BIT_NUM_EBS0_1       7

/* PCA_PWM1 bits */
#define BIT_NUM_EPC1L        0
#define BIT_NUM_EPC1H        1
#define BIT_NUM_EBS1_0       6
#define BIT_NUM_EBS1_1       7

/* PCA_PWM2 bits */
#define BIT_NUM_EPC2L        0
#define BIT_NUM_EPC2H        1
#define BIT_NUM_EBS2_0       6
#define BIT_NUM_EBS2_1       7

/* PCA_PWM0 bits */
#define BIT_NUM_EPC0L        0
#define BIT_NUM_EPC0H        1
#define BIT_NUM_EBS0_0       6
#define BIT_NUM_EBS0_1       7

/* PCON bits */
#define BIT_NUM_IDL          0
#define BIT_NUM_PD           1
#define BIT_NUM_GF0          2
#define BIT_NUM_GF1          3
#define BIT_NUM_POF          4
#define BIT_NUM_LVDF         5
#define BIT_NUM_SMOD0        6
#define BIT_NUM_SMOD         7

/* PCON2 bits */
#define BIT_NUM_CLKS0        0
#define BIT_NUM_CLKS1        1
#define BIT_NUM_CLKS2        2
#define BIT_NUM_MCLKO_2      3
    #define BIT_NUM_SYSCLKO_2 BIT_NUM_MCLKO_2
#define BIT_NUM_TX_RX        4
#define BIT_NUM_ADRJ         5
#define BIT_NUM_MCLKO_S0     6
#define BIT_NUM_MCLKO_S1     7

/* PWMCFG bits */
#define BIT_NUM_C2INI        0
#define BIT_NUM_C3INI        1
#define BIT_NUM_C4INI        2
#define BIT_NUM_C5INI        3
#define BIT_NUM_C6INI        4
#define BIT_NUM_C7INI        5
#define BIT_NUM_CBTADC       6

/* PWMCR bits */
#define BIT_NUM_ENC2O        0
#define BIT_NUM_ENC3O        1
#define BIT_NUM_ENC4O        2
#define BIT_NUM_ENC5O        3
#define BIT_NUM_ENC6O        4
#define BIT_NUM_ENC7O        5
#define BIT_NUM_ECBI         6
#define BIT_NUM_ENPWM        7

/* PWMFDCR bits */
#define BIT_NUM_FDIF         0
#define BIT_NUM_FDIO         1
#define BIT_NUM_FDCMP        2
#define BIT_NUM_EFDI         3
#define BIT_NUM_FLTFLIO      4
#define BIT_NUM_ENFO         5

/* PWMIF bits */
#define BIT_NUM_C2IF         0
#define BIT_NUM_C3IF         1
#define BIT_NUM_C4IF         2
#define BIT_NUM_C5IF         3
#define BIT_NUM_C6IF         4
#define BIT_NUM_C7IF         5
#define BIT_NUM_CBIF         6

/* S2CON bits */
#define BIT_NUM_S2RI         0
#define BIT_NUM_S2TI         1
#define BIT_NUM_S2RB8        2
#define BIT_NUM_S2TB8        3
#define BIT_NUM_S2REN        4
#define BIT_NUM_S2SM2        5
#define BIT_NUM_S2SM0        7

/* S3CON bits */
#define BIT_NUM_S3RI         0
#define BIT_NUM_S3TI         1
#define BIT_NUM_S3RB8        2
#define BIT_NUM_S3TB8        3
#define BIT_NUM_S3REN        4
#define BIT_NUM_S3SM2        5
#define BIT_NUM_S3ST3        6
#define BIT_NUM_S3SM0        7

/* S4CON bits */
#define BIT_NUM_S4RI         0
#define BIT_NUM_S4TI         1
#define BIT_NUM_S4RB8        2
#define BIT_NUM_S4TB8        3
#define BIT_NUM_S4REN        4
#define BIT_NUM_S4SM2        5
#define BIT_NUM_S4ST4        6
#define BIT_NUM_S4SM0        7

/* SPSTAT bits */
#define BIT_NUM_WCOL         6
#define BIT_NUM_SPIF         7

/* SPCTL bits */
#define BIT_NUM_SPR0         0
#define BIT_NUM_SPR1         1
#define BIT_NUM_CAPHA        2
#define BIT_NUM_CPOL         3
#define BIT_NUM_MSTR         4
#define BIT_NUM_DORD         5
#define BIT_NUM_SPEN         6
#define BIT_NUM_SSIG         7

/* T4T3M bits */
#define BIT_NUM_T3CLKO       0
#define BIT_NUM_T3X12        1
#define BIT_NUM_T3_CT        2
#define BIT_NUM_T3R          3
#define BIT_NUM_T4CLKO       4
#define BIT_NUM_T4X12        5
#define BIT_NUM_T4_CT        6
#define BIT_NUM_T4R          7

/* WKTCH bits */
#define BIT_NUM_WKTEN        7

/* BIT definitions for bits which don't support bit addressing */
/* ADC_CONTR bits */
#define CHS0            BIT_MASK(BIT_NUM_CHS0)
#define CHS1            BIT_MASK(BIT_NUM_CHS1)
#define CHS2            BIT_MASK(BIT_NUM_CHS2)
#define ADC_START       BIT_MASK(BIT_NUM_ADC_START)
#define ADC_FLAG        BIT_MASK(BIT_NUM_ADC_FLAG)
#define SPEED0          BIT_MASK(BIT_NUM_SPEED0)
#define SPEED1          BIT_MASK(BIT_NUM_SPEED1)
#define ADC_POWER       BIT_MASK(BIT_NUM_ADC_POWER)

/* AUXR bits */
#define S1ST2           BIT_MASK(BIT_NUM_S1ST2)
#define EXTRAM          BIT_MASK(BIT_NUM_EXTRAM)
#define T2X12           BIT_MASK(BIT_NUM_T2X12)
#define T2_CT2          BIT_MASK(BIT_NUM_T2_CT2)
#define T2R             BIT_MASK(BIT_NUM_T2R)
#define UART_M0X6       BIT_MASK(BIT_NUM_UART_M0X6)
#define T1X12           BIT_MASK(BIT_NUM_T1X12)
#define T0X12           BIT_MASK(BIT_NUM_T0X12)

/* AUXR2(INT_CLKO) bits */
#define T0CLKO          BIT_MASK(BIT_NUM_T0CLKO)
#define T1CLKO          BIT_MASK(BIT_NUM_T1CLKO)
#define T2CLKO          BIT_MASK(BIT_NUM_T2CLKO)
#define MCKO_S2         BIT_MASK(BIT_NUM_MCKO_S2)
#define EX2             BIT_MASK(BIT_NUM_EX2)
#define EX3             BIT_MASK(BIT_NUM_EX3)
#define EX4             BIT_MASK(BIT_NUM_EX4)

/* CCAPM0 bits */
#define ECCF0           BIT_MASK(BIT_NUM_ECCF0)
#define PWM0            BIT_MASK(BIT_NUM_PWM0)
#define TOG0            BIT_MASK(BIT_NUM_TOG0)
#define MAT0            BIT_MASK(BIT_NUM_MAT0)
#define CAPN0           BIT_MASK(BIT_NUM_CAPN0)
#define CAPP0           BIT_MASK(BIT_NUM_CAPP0)
#define ECOM0           BIT_MASK(BIT_NUM_ECOM0)

/* CCAPM1 bits */
#define ECCF1           BIT_MASK(BIT_NUM_ECCF1)
#define PWM1            BIT_MASK(BIT_NUM_PWM1)
#define TOG1            BIT_MASK(BIT_NUM_TOG1)
#define MAT1            BIT_MASK(BIT_NUM_MAT1)
#define CAPN1           BIT_MASK(BIT_NUM_CAPN1)
#define CAPP1           BIT_MASK(BIT_NUM_CAPP1)
#define ECOM1           BIT_MASK(BIT_NUM_ECOM1)

/* CCAPM2 bits */
#define ECCF2           BIT_MASK(BIT_NUM_ECCF2)
#define PWM2            BIT_MASK(BIT_NUM_PWM2)
#define TOG2            BIT_MASK(BIT_NUM_TOG2)
#define MAT2            BIT_MASK(BIT_NUM_MAT2)
#define CAPN2           BIT_MASK(BIT_NUM_CAPN2)
#define CAPP2           BIT_MASK(BIT_NUM_CAPP2)
#define ECOM2           BIT_MASK(BIT_NUM_ECOM2)

/* CMOD bits */
#define ECF             BIT_MASK(BIT_NUM_ECF)
#define CPS0            BIT_MASK(BIT_NUM_CPS0)
#define CPS1            BIT_MASK(BIT_NUM_CPS1)
#define CIDL            BIT_MASK(BIT_NUM_CIDL)

/* BUS_SPEED bits */
#define EXRTS0          BIT_MASK(BIT_NUM_EXRTS0)
#define EXRTS1          BIT_MASK(BIT_NUM_EXRTS1)

/* IAP_CMD bits */
#define MS0             BIT_MASK(BIT_NUM_MS0)
#define MS1             BIT_MASK(BIT_NUM_MS1)

/* IAP_CONTR bits */
#define WT0             BIT_MASK(BIT_NUM_WT0)
#define WT1             BIT_MASK(BIT_NUM_WT1)
#define WT2             BIT_MASK(BIT_NUM_WT2)
#define CMD_FAIL        BIT_MASK(BIT_NUM_CMD_FAIL)
#define SWRST           BIT_MASK(BIT_NUM_SWRST)
#define SWBS            BIT_MASK(BIT_NUM_SWBS)
#define IAPEN           BIT_MASK(BIT_NUM_IAPEN)

/* IE2 bits */
#define ES2             BIT_MASK(BIT_NUM_ES2)
#define ESPI            BIT_MASK(BIT_NUM_ESPI)
#define ET2             BIT_MASK(BIT_NUM_ET2)
#define ES3             BIT_MASK(BIT_NUM_ES3)
#define ES4             BIT_MASK(BIT_NUM_ES4)
#define ET3             BIT_MASK(BIT_NUM_ET3)
#define ET4             BIT_MASK(BIT_NUM_ET4)

/* IP2 bits */
#define PS2             BIT_MASK(BIT_NUM_PS2)
#define PSPI            BIT_MASK(BIT_NUM_PSPI)
#define PPWM            BIT_MASK(BIT_NUM_PPWM)
#define PPWMFD          BIT_MASK(BIT_NUM_PPWMFD)
#define PX4             BIT_MASK(BIT_NUM_PX4)

/* P_SW2 bits */
#define S2_S            BIT_MASK(BIT_NUM_S2_S)
#define S3_S            BIT_MASK(BIT_NUM_S3_S)
#define S4_S            BIT_MASK(BIT_NUM_S4_S)
#define EAXSFR          BIT_MASK(BIT_NUM_EAXSFR)

/* P1ASF bits */
#define P10ASF          BIT_MASK(BIT_NUM_P10ASF)
#define P11ASF          BIT_MASK(BIT_NUM_P11ASF)
#define P12ASF          BIT_MASK(BIT_NUM_P12ASF)
#define P13ASF          BIT_MASK(BIT_NUM_P13ASF)
#define P14ASF          BIT_MASK(BIT_NUM_P14ASF)
#define P15ASF          BIT_MASK(BIT_NUM_P15ASF)
#define P16ASF          BIT_MASK(BIT_NUM_P16ASF)
#define P17ASF          BIT_MASK(BIT_NUM_P17ASF)

/* PCA_PWM0 bits */
#define EPC0L           BIT_MASK(BIT_NUM_EPC0L)
#define EPC0H           BIT_MASK(BIT_NUM_EPC0H)
#define EBS0_0          BIT_MASK(BIT_NUM_EBS0_0)
#define EBS0_1          BIT_MASK(BIT_NUM_EBS0_1)

/* PCA_PWM1 bits */
#define EPC1L           BIT_MASK(BIT_NUM_EPC1L)
#define EPC1H           BIT_MASK(BIT_NUM_EPC1H)
#define EBS1_0          BIT_MASK(BIT_NUM_EBS1_0)
#define EBS1_1          BIT_MASK(BIT_NUM_EBS1_1)

/* PCA_PWM2 bits */
#define EPC2L           BIT_MASK(BIT_NUM_EPC2L)
#define EPC2H           BIT_MASK(BIT_NUM_EPC2H)
#define EBS2_0          BIT_MASK(BIT_NUM_EBS2_0)
#define EBS2_1          BIT_MASK(BIT_NUM_EBS2_1)

/* PCON bits */
#define POF             BIT_MASK(BIT_NUM_POF)
#define LVDF            BIT_MASK(BIT_NUM_LVDF)
#define SMOD0           BIT_MASK(BIT_NUM_SMOD0)

/* PCON2 bits */
#define CLKS0           BIT_MASK(BIT_NUM_CLKS0)
#define CLKS1           BIT_MASK(BIT_NUM_CLKS1)
#define CLKS2           BIT_MASK(BIT_NUM_CLKS2)
#define MCLKO_2         BIT_MASK(BIT_NUM_MCLKO_2)
#define SYSCLKO_2       BIT_MASK(BIT_NUM_SYSCLKO_2)   /* CLK_DIV.3's alias */
#define TX_RX           BIT_MASK(BIT_NUM_TX_RX)
#define ADRJ            BIT_MASK(BIT_NUM_ADRJ)
#define MCLKO_S0        BIT_MASK(BIT_NUM_MCKO_S0)
#define MCLKO_S1        BIT_MASK(BIT_NUM_MCKO_S1)

/* PWMCFG bits */
#define C2INI           BIT_MASK(BIT_NUM_C2INI)
#define C3INI           BIT_MASK(BIT_NUM_C3INI)
#define C4INI           BIT_MASK(BIT_NUM_C4INI)
#define C5INI           BIT_MASK(BIT_NUM_C5INI)
#define C6INI           BIT_MASK(BIT_NUM_C6INI)
#define C7INI           BIT_MASK(BIT_NUM_C7INI)
#define CBTADC          BIT_MASK(BIT_NUM_CBTADC)

/* PWMCR bits */
#define ENC2O           BIT_MASK(BIT_NUM_ENC2O)
#define ENC3O           BIT_MASK(BIT_NUM_ENC3O)
#define ENC4O           BIT_MASK(BIT_NUM_ENC4O)
#define ENC5O           BIT_MASK(BIT_NUM_ENC5O)
#define ENC6O           BIT_MASK(BIT_NUM_ENC6O)
#define ENC7O           BIT_MASK(BIT_NUM_ENC7O)
#define ECBI            BIT_MASK(BIT_NUM_ECBI)
#define ENPWM           BIT_MASK(BIT_NUM_ENPWM)

/* PWMFDCR bits */
#define FDIF            BIT_MASK(BIT_NUM_FDIF)
#define FDIO            BIT_MASK(BIT_NUM_FDIO)
#define FDCMP           BIT_MASK(BIT_NUM_FDCMP)
#define EFDI            BIT_MASK(BIT_NUM_EFDI)
#define FLTFLIO         BIT_MASK(BIT_NUM_FLTFLIO)
#define ENFD            BIT_MASK(BIT_NUM_ENFD)

/* PWMIF bits */
#define C2IF            BIT_MASK(BIT_NUM_C2IF)
#define C3IF            BIT_MASK(BIT_NUM_C3IF)
#define C4IF            BIT_MASK(BIT_NUM_C4IF)
#define C5IF            BIT_MASK(BIT_NUM_C5IF)
#define C6IF            BIT_MASK(BIT_NUM_C6IF)
#define C7IF            BIT_MASK(BIT_NUM_C7IF)
#define CBIF            BIT_MASK(BIT_NUM_CBIF)

/* S2CON bits */
#define S2RI            BIT_MASK(BIT_NUM_S2RI)
#define S2TI            BIT_MASK(BIT_NUM_S2TI)
#define S2RB8           BIT_MASK(BIT_NUM_S2RB8)
#define S2TB8           BIT_MASK(BIT_NUM_S2TB8)
#define S2REN           BIT_MASK(BIT_NUM_S2REN)
#define S2SM2           BIT_MASK(BIT_NUM_S2SM2)
#define S2SM0           BIT_MASK(BIT_NUM_S2SM0)

/* S3CON bits */
#define S3RI            BIT_MASK(BIT_NUM_S3RI)
#define S3TI            BIT_MASK(BIT_NUM_S3TI)
#define S3RB8           BIT_MASK(BIT_NUM_S3RB8)
#define S3TB8           BIT_MASK(BIT_NUM_S3TB8)
#define S3REN           BIT_MASK(BIT_NUM_S3REN)
#define S3SM2           BIT_MASK(BIT_NUM_S3SM2)
#define S3ST3           BIT_MASK(BIT_NUM_S3ST3)
#define S3SM0           BIT_MASK(BIT_NUM_S3SM0)

/* S4CON bits */
#define S4RI            BIT_MASK(BIT_NUM_S4RI)
#define S4TI            BIT_MASK(BIT_NUM_S4TI)
#define S4RB8           BIT_MASK(BIT_NUM_S4RB8)
#define S4TB8           BIT_MASK(BIT_NUM_S4TB8)
#define S4REN           BIT_MASK(BIT_NUM_S4REN)
#define S4SM2           BIT_MASK(BIT_NUM_S4SM2)
#define S4ST4           BIT_MASK(BIT_NUM_S4ST4)
#define S4SM0           BIT_MASK(BIT_NUM_S4SM0)

/* SPSTAT bits */
#define WCOL            BIT_MASK(BIT_NUM_WCOL)
#define SPIF            BIT_MASK(BIT_NUM_SPIF)

/* SPCTL bits */
#define SPR0            BIT_MASK(BIT_NUM_SPR0)
#define SPR1            BIT_MASK(BIT_NUM_SPR1)
#define CAPHA           BIT_MASK(BIT_NUM_CAPHA)
#define CPOL            BIT_MASK(BIT_NUM_CPOL)
#define MSTR            BIT_MASK(BIT_NUM_MSTR)
#define DORD            BIT_MASK(BIT_NUM_DORD)
#define SPEN            BIT_MASK(BIT_NUM_SPEN)
#define SSIG            BIT_MASK(BIT_NUM_SSIG)

/* T4T3M bits */
#define T3CLKO          BIT_MASK(BIT_NUM_T3CLKO)
#define T3X12           BIT_MASK(BIT_NUM_T3X12)
#define T3_CT           BIT_MASK(BIT_NUM_T3_CT)
#define T3R             BIT_MASK(BIT_NUM_T3R)
#define T4CLKO          BIT_MASK(BIT_NUM_T4CLKO)
#define T4X12           BIT_MASK(BIT_NUM_T4X12)
#define T4_CT           BIT_MASK(BIT_NUM_T4_CT)
#define T4R             BIT_MASK(BIT_NUM_T4R)

/* WKTCH bits */
#define WKTEN           BIT_MASK(BIT_NUM_WKTEN)

/* Interrupt numbers: address = (number * 8) + 3 */
#define SI1_VECTOR      SI0_VECTOR     /* rename with STC Micro offical rule */
#define ADC_VECTOR      5    /* 0x2b analog-digital converter */
#define LVD_VECTOR      6    /* 0x33 low voltage detect */
#define PCA_VECTOR      7    /* 0x3b PCA module */
#define SI2_VECTOR      8    /* 0x43 serial port 2 */
#define SPI_VECTOR      9    /* 0x4b SPI bus */
#define IE2_VECTOR      10   /* 0x53 external interrupt 2 */
#define IE3_VECTOR      11   /* 0x5b external interrupt 3 */
#define TF2_VECTOR      12   /* 0x63 timer 2 */
#define IE4_VECTOR      16   /* 0x83 external interrupt 4 */
#define SI3_VECTOR      17   /* 0x8b serial port 3 */
#define SI4_VECTOR      18   /* 0x93 serial port 4 */
#define TF3_VECTOR      19   /* 0x9b timer 3 */
#define TF4_VECTOR      20   /* 0xa3 timer 4 */
#define CMP_VECTOR      21   /* 0xab comparator */
#define PWM_VECTOR      22   /* 0xb3 PWM module */
#define PWME_VECTOR     23   /* 0xbb PWM exception */

#endif
