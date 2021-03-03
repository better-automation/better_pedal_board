#ifndef BPB_BRAIN_PROGRAM_TEMPO_PROGRAM_CONTEXT_H
#define BPB_BRAIN_PROGRAM_TEMPO_PROGRAM_CONTEXT_H

#include "program_context.h"

#include "tempo_action.h"
#include "trigger_context.h"

namespace BPB::Brain::Program
{
    struct TempoProgramContext : ProgramContext<TempoAction>
    {
        private:
            std::vector<TriggerContext<TempoAction>*> _triggers;

        public:
            std::vector<TriggerContext<TempoAction>> triggers;

            TempoProgramContext(
                std::vector<PedalContext>& pedals,
                std::vector<TriggerContext<TempoAction>> triggers
            ) :
                ProgramContext(pedals),
                triggers(triggers)
            { 
                for (TriggerContext<TempoAction>& trigger : triggers)
                    _triggers.push_back(&trigger);
            }

            std::vector<TriggerContext<TempoAction>*> getTriggers() { return _triggers; };
    };
}

#endif