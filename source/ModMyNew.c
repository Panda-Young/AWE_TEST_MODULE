/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModMyNew.c
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

#define NOREDEF


#include "Framework.h"
#include "Errors.h"
#include "ModMyNew.h"


#ifdef __cplusplus
extern "C" {
#endif

/* ----------------------------------------------------------------------
** THIS IS AN AUTO-GENERATED FILE. Please make all changes in the inner file. 
** Changes made to this file will be overwritten during module generation.
** Audio module class object.  This describes the audio module to the
** framework.  It contains pointers to functions and number of
** variables.
** ------------------------------------------------------------------- */

CREATE_MODULE_CLASS(Class_awe_modMyNew, (1 + 0))

AWE_MOD_SLOW_ANY_CONST
const Class_awe_modMyNew awe_modMyNewClass =
{
    {
        { awe_modMyNewConstructor, CLASSID_MYNEW, },
        awe_modMyNewProcess,                // Processing function
        IOMatchUpModule_Bypass,                 // Bypass function
        0,                                    // Set function
        0,                                    // Get function
        0,				                      // Unused field
        ClassModule_PackArgCounts(1, 0),    // (Public words, private words)
        {0x00000000, 0x00000000}, // Specifies which variables are floating-point
    },
#ifdef BUILD64
    {
        offsetof(awe_modMyNewInstance, currentFrame),
    }
#endif
};


/* ----------------------------------------------------------------------
** Memory allocation function.  This is required because the module
** requires additional memory outside of its instance structure.
** ------------------------------------------------------------------- */

AWE_MOD_SLOW_CODE
ModInstanceDescriptor *awe_modMyNewConstructor(INT32 * FW_RESTRICT retVal, UINT32 nIO, WireInstance ** FW_RESTRICT pWires, size_t argCount, const Sample * FW_RESTRICT args)
{   
	awe_modMyNewInstance *S = (awe_modMyNewInstance *) BaseClassModule_Constructor((ModClassModule *) &awe_modMyNewClass, retVal, nIO, pWires, argCount, args);
	
	// Check if BaseClassModule_Constructor() finished properly.  If not,
	// the error code is in *retVal
	if (S == NULL)
	{
	    return 0;
	}
	

    UINT32 inputChannels = ClassWire_GetChannelCount(pWires[1]);
    UINT32 blockSize = ClassWire_GetBlockSize(pWires[1]);
    UINT32 nSampleRate = ClassWire_GetSampleRate(pWires[1]);
    
    LOGI("inputChannels=%d, blockSize=%d, nSampleRate=%d", inputChannels, blockSize, nSampleRate);
    LOGI("initialized successfully");
    
    return (ModInstanceDescriptor *)S;
}

/* ----------------------------------------------------------------------
** Real-time Processing function.
** ------------------------------------------------------------------- */

AWE_MOD_FAST_CODE
void awe_modMyNewProcess(void *pInstance)
{
    awe_modMyNewInstance *S = (awe_modMyNewInstance *)pInstance;
    WireInstance **pWires = ClassModule_GetWires(S);
    UINT32 numSamples = ClassWire_GetNumSamples(pWires[0]);
    UINT32 *pSrc = (UINT32 *)(pWires[0] ->buffer);
    UINT32 *pDst = (UINT32 *)(pWires[1] ->buffer);
    UINT32 i;
    for (i = 0; i < numSamples; i++)
    {
        *pDst++ = *pSrc++;
    }
    LOGD("frame %d processing...", S->currentFrame++);
}




#ifdef __cplusplus
}
#endif

/**
 * @}
 *
 * End of file.
 */
