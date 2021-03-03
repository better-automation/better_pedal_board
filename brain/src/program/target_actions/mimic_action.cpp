#include "mimic_action.h"

using namespace BPB::Brain::Program::Actions;

StateChange<int> MimicAction::getTargetState(int sourceDeviceState)
{
    return StateChange(sourceDeviceState);
}