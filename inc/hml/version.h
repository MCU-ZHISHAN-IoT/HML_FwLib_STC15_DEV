/*****************************************************************************/
/** 
 * \file        version.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML version information
 * \note        
 * \version     v0.0
 * \ingroup     VERSION
******************************************************************************/

#ifndef ___HML_VERSION_H___
#define ___HML_VERSION_H___

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\ brief: string literal representation of the current library name
 */
#define __HML_NAME_STRING__ "HML_FwLib_STC15"

/**
 *\ brief: string literal representation of the current library version
 */
#define __HML_VERSION_STRING__ "0.0.0"

/**
 *\ brief:
 * Numerical representation of the current library version.
 *
 * In the numerical representation, the major number is multiplied by
 * 10000, the minor number by 100, and all three parts are then
 * added.  It is intended to provide a monotonically increasing
 * numerical value that can easily be used in numerical checks.
 */
#define __HML_VERSION__ 000000UL

/**
 *\breif: string literal representation of the release date.
 */
#define __HML_DATE_STRING__ "20200610"

/**
 *\breif: numerical representation of the release date.
 */
#define __HML_DATE__ 20200610UL

/**
 *\breif: library major version number.
 */
#define __HML_VERSION_MAJOR__ 0

/**
 *\brief: library minor version number.
 */
#define __HML_VERSION_MINOR__ 0

/**
 *\brief: library patch version number.
 */
#define __HML_VERSION_PATCH__ 0

#endif
