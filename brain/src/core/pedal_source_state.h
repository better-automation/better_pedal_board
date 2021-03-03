#ifndef BPB_BARIN_CORE_PEDAL_SOURCE_STATE_H
#define BPB_BARIN_CORE_PEDAL_SOURCE_STATE_H

#include "../mem_limits.h"

namespace BPB::Brain::Core
{
    struct PedalSourceState
    {
        int current[MAX_DEVICE_COUNT_PER_PEDAL];
        int previous[MAX_DEVICE_COUNT_PER_PEDAL];
        bool arePreviousStatesAvailable = false;
    };
}

#endif