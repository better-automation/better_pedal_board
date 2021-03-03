#include "set_state_action.h"

using namespace BPB::Brain::Program::Actions;

StateChange<int> SetStateAction::getTargetState(int sourceDeviceState)
{
    return StateChange(targetState);
}