UINT32 inputChannels = ClassWire_GetChannelCount(pWires[1]);
UINT32 blockSize = ClassWire_GetBlockSize(pWires[1]);
UINT32 nSampleRate = ClassWire_GetSampleRate(pWires[1]);
UINT32 packedFlags = S->instance.packedFlags;
UINT32 totalWires = ClassMod_GetWireCount(packedFlags);
LOGI("inputChannels=%d, blockSize=%d, nSampleRate=%d, totalWires=%d",
     inputChannels, blockSize, nSampleRate, totalWires);

// Initialize thread related fields
InitializeCriticalSection(&cs);
threadRunning = TRUE;
threadHandle = CreateThread(
    NULL,       // security attributes
    0,          // stack size
    threadProc, // thread function
    S,          // parameters
    0,          // creation flag
    NULL        // thread ID
);
if (threadHandle == NULL) {
    LOGE("Failed to create thread");
    return NULL;
}

LOGI("initialized successfully");
return (ModInstanceDescriptor *)S;
