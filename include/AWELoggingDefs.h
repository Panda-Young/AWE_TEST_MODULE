/*******************************************************************************
*
*				Audio Framework
*				---------------
*
********************************************************************************
*	  AWELoggingDefs.h
********************************************************************************
*
*	  Description:	Public API AWE common logging definitions
*
*	  Copyright:	(c) 2007-2024 DSP Concepts, Inc. All rights reserved.
*					3235 Kifer Road
*					Santa Clara, CA 95054
*
*******************************************************************************/

/**
* @file 
* @brief The AWE logging definition header
*/

#ifndef _AWELOGGINGDEFS_H
#define _AWELOGGINGDEFS_H

#ifdef	__cplusplus
extern "C" {
#endif

// Log level macros, in order of increasing verbosity
#define AWE_LOG_LEVEL_NONE		        (0)       // This can be used in the logging register functions to disable all logging messages
#define AWE_LOG_LEVEL_ERROR		        (1)
#define AWE_LOG_LEVEL_WARNING	        (2)
#define AWE_LOG_LEVEL_INFO		        (3)
#define AWE_LOG_LEVEL_DEBUG		        (4)

// Log type macros dedicated to AWE Core framework
#define AWE_LOG_DATA_DUMP               (1U << 0U)
#define AWE_LOG_SYSTEM_MSG              (1U << 1U)
#define AWE_LOG_PACKET_PROCESSING_MSG   (1U << 2U)
#define AWE_LOG_AWB_LOADING_MSG         (1U << 3U)
#define AWE_LOG_CPU_OVERFLOW_MSG        (1U << 4U)
#define AWE_LOG_FRAMEWORK_MSG           (1U << 5U)
#define AWE_LOG_HEAP_MSG                (1U << 6U)
#define AWE_LOG_MODULE_MSG			    (1U << 7U)

// Default type mask to accept all log messages
#define AWE_LOG_ALL_TYPE_MASK			(0xFFFFFFFFU)

#ifdef	__cplusplus
}
#endif

#endif  // header guard end

