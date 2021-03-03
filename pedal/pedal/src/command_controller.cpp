#include "command_controller.h"

#include "../../platform/include/command.h"

using namespace BPB::Pedal;
using namespace BPB::Pedal::Platform;

void CommandController::initializePlatform(std::vector<int>& platformSourceState)
{
    platformSourceState = platformService.createSourcePinState();

    platformService.initialize(platformSourceState);
}

void CommandController::updateTargetState(std::vector<int>& targetDeviceState, std::vector<int>& platformTargetState)
{
    std::vector<int> previousTargetDeviceState = targetDeviceState;

    platformService.readTargetDeviceState(targetDeviceState);

    std::vector<int> previousPlatformTargetState = platformTargetState;

    deviceService.updatePlatformTargetState(previousTargetDeviceState, targetDeviceState, platformTargetState);

    platformService.writePinState(previousPlatformTargetState, platformTargetState);
}

void CommandController::runCommand(std::string& command, std::vector<int>& platformSourceState, std::vector<int>& platformTargetState, std::vector<int>& sourceDeviceState, std::vector<int>& targetDeviceState)
{
    if (command == Command::INITIALIZE_PLATFORM)
    {
        initializePlatform(platformSourceState);

        return;
    }

    if (command == Command::RECEIVE_TARGET_DEVICE_STATE) 
    {
        updateTargetState(targetDeviceState, platformTargetState);

        return;
    }
}