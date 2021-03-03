#ifndef BPB_BRAIN_PROGRAM_TARGET_PROGRAM_CONTEXT
#define BPB_BRAIN_PROGRAM_TARGET_PROGRAM_CONTEXT

#include <vector>

#include "action_runner.h"
#include "../core/pedal_context.h"
#include "program_context.h"
#include "target_action.h"
#include "target_action_runner.h"
#include "target_trigger_context.h"
#include "trigger_context.h"

namespace BPB::Brain::Program
{
    class TargetProgramContext : public ProgramContext<TargetAction>
    {
        private:
            TargetActionRunner actionRunner;
            std::vector<PedalContext>& pedals;
            std::vector<TargetTriggerContext> targetTriggers;
            std::vector<TriggerContext<TargetAction>*> triggers;

            static std::vector<TriggerContext<TargetAction>*> createTriggers(std::vector<TargetTriggerContext>& targetTriggers);

        public:
            TargetProgramContext(
                std::vector<PedalContext>& pedals,
                std::vector<TargetTriggerContext> targetTriggers
            ) :
                pedals(pedals),
                targetTriggers(targetTriggers),
                triggers(createTriggers(targetTriggers))
            { }

        std::vector<TargetTriggerContext> getTargetTriggers();
        std::vector<TriggerContext<TAction>*> getTriggers();
    };
}

#endif