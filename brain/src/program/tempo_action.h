#ifndef BPB_BRAIN_PROGRAM_TEMPO_ACTION_H
#define BPB_BRAIN_PROGRAM_TEMPO_ACTION_H

#include <chrono>

#include "state_change.h"
#include "tempo_state.h"

namespace BPB::Brain::Program
{
    class TempoAction
    {
        public:
            virtual ~TempoAction() { }

            virtual StateChange<TempoState> getTempoState(int sourceDeviceState, std::chrono::milliseconds lastTickTime, TempoState tempo) = 0;
    };
}

#endif