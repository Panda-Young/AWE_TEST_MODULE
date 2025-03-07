/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModMyNew.h
****************************************************************************
*
*     Description:  Copies input wire to output wire
*
*     Copyright:    2007-2022 DSP Concepts, Inc. All rights reserved.
*                   3235 Kifer Road
*                   Santa Clara, CA 95054
*
***************************************************************************/

/**
 * @addtogroup Modules
 * @{
 */

/**
 * @file
 * @brief Copies input wire to output wire
 */

#ifndef _MOD_MYNEW_H
#define _MOD_MYNEW_H

#include "ModCommon.h"
#include "MathHelper.h"


#define CLASSID_MYNEW (CLASS_ID_MODBASE + 60000)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modMyNewInstance
{
    ModuleInstanceDescriptor instance;
    
    
} awe_modMyNewInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modMyNewClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
// This points the constructor for this class to the base constructor
#define awe_modMyNewConstructor(ARG1, ARG2, ARG3, ARG4, ARG5) ClassModule_Constructor(CLASSID_MYNEW, ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // #ifndef AWE_STATIC_CODE


void awe_modMyNewProcess(void *pInstance);

 



#ifdef __cplusplus
}
#endif


#endif // _MOD_MYNEW_H

/**
 * @}
 *
 * End of file.
 */
