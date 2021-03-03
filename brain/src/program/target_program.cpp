#include "target_program.h"

void TargetProgram::run()
{
    std::vector<TargetTriggerContext>& targetTriggers = context.getTargetTriggers();

    for (int triggerIndex = 0; triggerIndex < targetTriggers.size(); triggerIndex++)
    {
        Device& target = targetTriggers[triggerIndex].target;

        LayerState<int>& targetLayer = state.targetLayers[target.pedalIndex][target.deviceIndex];

        targetLayer = programService.runTrigger(targetLayer, triggerIndex);
    }

    for (int targetPedalIndex = 0; targetPedalIndex < context.pedals.size(); targetPedalIndex++)
    for (int targetDeviceIndex = 0; targetDeviceIndex < context.pedals[targetPedalIndex].targetDeviceCount; targetDeviceIndex++)
    {
        LayerStateNode<int>* targetLayer = state.targetLayers[targetPedalIndex][targetDeviceIndex];
        
        int& targetState = targets[targetPedalIndex].next[targetDeviceIndex];

        targetState = programService.runScheduledEvents(targetLayer);
    }
}