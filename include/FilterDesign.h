/*******************************************************************************
*
*				Audio Framework
*				---------------
*
********************************************************************************
*	  FilterDesign.h
********************************************************************************
*
*	  Description:	AudioWeaver Framework filter design helper functions
*
*     Copyright:    (c) 2007-2021 DSP Concepts, Inc. All rights reserved.
*                   3235 Kifer Road
*                   Santa Clara, CA 95054
*
*******************************************************************************/

#ifndef _filter_design_h
#define _filter_design_h

#include "ModCommon.h"
#include "MathHelper.h"




/** 
 * @brief  Designs a first order IIR smoothing filter with a specified smoothing time.
 * @param[in] TIME                  Smoothing time in milliseconds
 * @param[in] SR					Sample rate
 * @param[in] BLOCKSIZE             Number of samples to process
 */
FLOAT32 design_smoother(FLOAT32 TIME, FLOAT32 SR, INT32 BLOCKSIZE);

/** 
 * @brief  General purpose design function for a wide variety of 1st and 2nd order filters
 * @param[in] TYPE					Filter Type 
 * @param[in] SR					Sample rate
 * @param[in] FREQUENCY				Filter Cut off frequency
 * @param[in] GGAIN					cut or boost, in dB
 * @param[in] Q						the sharpness or Q of the filter (dimensionless)
 * @param[out] coeff				Points to coefficents of size 5 in the order b0,b1,b2,a0,a1.
 * @param[in] precType				Data presicion selction, 0 for floating arthematics and 1 for double(64-bit) arthematics 
 */
/**
* @ all supported filter types
* @  0 = Pass through mode (gain = 1)
* @  1 = Scaler with level GGAIN
* @  2 = 1st order Butterworth LPF.  [FREQUENCY].
* @  3 = 2nd order Butterworth LPF.  [FREQUENCY].
* @  4 = 1st order Butterworth HPF.  [FREQUENCY].
* @  5 = 2nd order Butterworth HPF.  [FREQUENCY].
* @  6 = 1st order Allpass. [FREQUENCY].
* @  7 = 2nd order Allpass. [FREQUENCY, Q].
* @  8 = Low shelf [FREQUENCY, GGAIN].
* @  9 = Low shelf [FREQUENCY, GGAIN, Q].
* @  10 = High shelf [FREQUENCY, GGAIN].
* @  11 = High shelf [FREQUENCY, GGAIN, Q].
* @  12 = Peak EQ [FREQUENCY, GGAIN, Q].
* @  13 = Notch [FREQUENCY, Q].
* @  14 = Bandpass [FREQUENCY, Q].
*/
void design_second_order_filter(INT32 TYPE, FLOAT32 SR, FLOAT32 FREQUENCY, FLOAT32 GGAIN, FLOAT32 Q, FLOAT32 * FCOEFFS);

/** 
 * @brief  Converts SOS coefficients to state spece
 * @param[in] IN					5 input coefficients: b0, b1, b2, a1, a2
 * @param[out] OUT				    5 output coefficients:  Fb, Gaa, Gab, K, Fa.
 */

void design_sos2ss(const FLOAT32 * INCOEFF, FLOAT32 * OUTCOEFF);

/** 
 * @brief  General purpose butterworth filters
 * @param[in] ORDER					Filter order
 * @param[in] CUTOFF				Filter Cut off frequency
 * @param[in] SR					Sample rate
 * @param[in] ISLOW					Filter type TYPE=0 is a lowpass filter, TYPE=1 is a high pass filter, TYPE=2 is an allpass filter
 * @param[out] coeff				Points to coefficents of size 5 in the order b0,b1,b2,a0,a1.
 * @param[in] precType				Data presicion selction, 0 for floating arthematics and 1 for double(64-bit) arthematics 
 */
void design_butterworth(INT32 ORDER, FLOAT32 CUTOFF, FLOAT32 SR, INT32 FILTERTYPE, FLOAT32 *fcoeffs);

/** 
 * @brief  Designs a single section of a cascade graphic EQ.
 * @param[in] FREQ_L				Low frequency edge (in Hz)
 * @param[in] FREQ_H				Upper frequency edge (in Hz)
 * @param[in] GAINDB				Gain in the center of the band (in dB)
 * @param[in] SR					Sample rate 
 * @param[in] ORDER					filter order.  This must be a multiple of 4 (i.e, 4, 8, 12, etc.)
  * @param[out] coeff				Points to coefficents of size 5 in the order b0,b1,b2,a0,a1.
  */
void design_geq(FLOAT32 FREQ_L, FLOAT32 FREQ_H, FLOAT32 GAINDB, FLOAT32 SR, INT32 ORDER, FLOAT32 * COEFFS);

void design_emphasis_filter(INT32 PRE, FLOAT32 tTAU, FLOAT32 SR, FLOAT32 *COEFFS);

/* @brief Designs FIR filters that perform fractional sample delay
   @param[in]  Fractdelay   Desired delay value, in sample.
   @param[in]  *coeff_ptr   Coefficients are written here.
   The resulting filters are 42 samples long.
 */
void design_fractionaldelay(FLOAT32 Fractdelay, FLOAT32 * coeffs_ptr);

#endif  // _filter_design_h
