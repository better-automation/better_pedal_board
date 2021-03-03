#include "../include/platform_service.h"

using namespace BPB::Pedal::Platform;

void PlatformService::clearCommand()
{
    commandBus.clearCommand();
}

std::vector<int> PlatformService::createSourcePinState()
{
    return std::vector<int>(8);
}

std::vector<int> PlatformService::createTargetPinState()
{
    return std::vector<int>(8);
}

std::string& PlatformService::getCommand()
{
    return commandBus.getCommand();
}

void PlatformService::initialize(std::vector<int>& sourceState)
{
    platform->initialize(sourceState);
}

void PlatformService::loadPlatform()
{
    platform = createPlatform();
}

void PlatformService::readPinState(std::vector<int>& sourceState)
{
    platform->readPins(sourceState, commandBus);
}

void PlatformService::writePinState(std::vector<int>& previousTargetState, std::vector<int>& targetState)
{
    if (targetState.empty())
    {
        return;
    }

    platform->writePins(previousTargetState, targetState);
}