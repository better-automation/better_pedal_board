#ifndef BPB_BARIN_CORE_PEDAL_TARGET_STATE_H
#define BPB_BARIN_CORE_PEDAL_TARGET_STATE_H

#include "../mem_limits.h"

namespace BPB::Brain::Core
{
    struct PedalTargetState
    {
        int current[MAX_DEVICE_COUNT_PER_PEDAL];
        int next[MAX_DEVICE_COUNT_PER_PEDAL];
    };
}

#endif