UINT32 inputChannels = ClassWire_GetChannelCount(pWires[1]);
UINT32 blockSize = ClassWire_GetBlockSize(pWires[1]);
UINT32 nSampleRate = ClassWire_GetSampleRate(pWires[1]);

LOGI("inputChannels=%d, blockSize=%d, nSampleRate=%d", inputChannels, blockSize, nSampleRate);
LOGI("initialized successfully");

return (ModInstanceDescriptor *)S;
