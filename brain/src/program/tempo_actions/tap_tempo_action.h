#ifndef BPB_BRAIN_PROGRAM_TEMPO_STATE_ACTIONS_TAP_TEMPO_ACTION_H
#define BPB_BRAIN_PROGRAM_TEMPO_STATE_ACTIONS_TAP_TEMPO_ACTION_H

#include <chrono>

#include "../state_change.h"
#include "../tempo_action.h"
#include "../tempo_state.h"

using namespace BPB::Brain::Program;

namespace BPB::Brain::Program::TempoActions
{
    class TapTempoAction : TempoAction
    {
        public:
            StateChange<TempoState> getTempoState(int sourceDeviceState, std::chrono::milliseconds lastTickTime, TempoState tempo);
    };
}

#endif