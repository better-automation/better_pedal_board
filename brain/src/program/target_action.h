#ifndef BPB_BRAIN_PROGRAM_TARGET_STATE_ACTION_H
#define BPB_BRAIN_PROGRAM_TARGET_STATE_ACTION_H

#include "state_change.h"

namespace BPB::Brain::Program
{
    class TargetAction
    {
        public:
            virtual ~TargetAction() { }

            virtual StateChange<int> getStateChange(int sourceDeviceState) = 0;
    };
}

#endif