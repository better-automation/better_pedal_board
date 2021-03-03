#include "target_action_runner.h"

#include "device.h"

using namespace BPB::Brain::Program;

int TargetActionRunner::getDefaultState()
{
    return 0;
}

StateChange<int> TargetActionRunner::getStateChange(TargetAction& action, int sourceState)
{
    return action.getStateChange(sourceState);
}