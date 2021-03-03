#ifndef BPB_BRAIN_PROGRAM_TARGET_STATE_ACTIONS_MIMIC_ACTION_H
#define BPB_BRAIN_PROGRAM_TARGET_STATE_ACTIONS_MIMIC_ACTION_H

#include "../target_action.h"

#include "../state_change.h"

using namespace BPB::Brain::Program;

namespace BPB::Brain::Program::Actions
{
    class MimicAction : public TargetAction
    {
        public:
            StateChange<int> getTargetState(int sourceDeviceState);
    };
}

#endif