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
#include <windows.h>
#include "../source/logger.h"

#define MYNEW_VERSION_STRING "0.1.0"
DWORD WINAPI threadProc(LPVOID lpParameter);
#define MASK_MyNew_currentFrame 0x00000100
#define OFFSET_MyNew_currentFrame 0x00000008

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
    INT32              currentFrame;        // current frame number
    
} awe_modMyNewInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modMyNewClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
ModInstanceDescriptor * awe_modMyNewConstructor(INT32 * FW_RESTRICT retVal, UINT32 nIO, WireInstance ** FW_RESTRICT pWires, size_t argCount, const Sample * FW_RESTRICT args);
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
