#include "platform_service.h"

using namespace BPB::Brain::Platform;
using namespace BPB::PlatformCore;

std::chrono::milliseconds PlatformService::getNow()
{
    return platform->getNow();
}

std::shared_ptr<std::istream> PlatformService::getProgramData()
{
    return platform->getProgramData();
}

void PlatformService::read(Controller& controller, std::vector<std::vector<int>>& result)
{
    platform->read(controller, result);
}

void PlatformService::writePedalTargetStates(std::vector<std::vector<int>>& previousStates, std::vector<std::vector<int>>& states)
{
    platform->write(previousStates, states);
}