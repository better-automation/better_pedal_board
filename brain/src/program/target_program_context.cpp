#include "target_program_runner.h"

#include "destination.h"
#include "layer_state.h"
#include "program_service.h"
#include "target_action_runner.h"

using namespace BPB::Brain::Program;

std::vector<TriggerContext<TargetAction>*> TargetProgramContext::createTriggers(std::vector<TargetTriggerContext>& targetTriggers)
{
    std::vector<TriggerContext<TargetAction>*> triggers;

    for (TargetTriggerContext& trigger : targetTriggers)
        triggers.push_back(&trigger);

    return triggers;
}

std::vector<TargetTriggerContext> getTargetTriggers()
{
    return targetTriggers;
}

std::vector<TriggerContext<TargetAction>*> TargetProgramContext::getTriggers()
{
    return triggers;
}