#ifndef BPB_BRAIN_PROGRAM_PROGRAM_CONTEXT_H
#define BPB_BRAIN_PROGRAM_PROGRAM_CONTEXT_H

#include <vector>

#include "action_runner.h"
#include "../core/pedal_context.h"
#include "trigger_context.h"

using namespace BPB::Brain::Core;

namespace BPB::Brain::Program
{
    template <class TAction>
    class ProgramContext
    {
        virtual std::vector<PedalContext> getPedals() = 0;
        virtual void run(PedalSourceState sources[], PedalTargetState targets[]) = 0;
        virtual std::vector<TriggerContext<TAction>*> getTriggers() = 0;
    };
}

#endif