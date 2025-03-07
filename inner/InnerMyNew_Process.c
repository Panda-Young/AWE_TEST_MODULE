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
