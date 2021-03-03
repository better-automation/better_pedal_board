#ifndef BPB_BRAIN_CORE_PEDAL_CONTEXT_H
#define BPB_BRAIN_CORE_PEDAL_CONTEXT_H

namespace BPB::Brain::Core
{
    struct PedalContext
    {
        int sourceDeviceCount;
        int targetDeviceCount;

        PedalContext(
            int sourceDeviceCount,
            int targetDeviceCount
        ) :
            sourceDeviceCount(sourceDeviceCount),
            targetDeviceCount(targetDeviceCount)
        { }
    };
}

#endif