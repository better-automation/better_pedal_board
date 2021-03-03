#include "../../platform_factory.h"

#include <memory>

#include "simulator_platform.h"

using namespace BPB::Brain::Platform;
using namespace BPB::Brain::Platform::Platforms::Simulator;

std::shared_ptr<Platform> PlatformFactory::create()
{
    return std::make_shared<SimulatorPlatform>(5);
}