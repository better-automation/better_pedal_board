#ifndef BPB_BRAIN_PROGRAM_ACTION_RUNNER_H
#define BPB_BRAIN_PROGRAM_ACTION_RUNNER_H

#include "state_change.h"

namespace BPB::Brain::Program
{
    template<class TAction, class TState>
    class ActionRunner
    {
        public:
            virtual TState getDefaultState() = 0;
            virtual StateChange<TState> getStateChange(TAction& action, int sourceState) = 0;
    };
}

#endif