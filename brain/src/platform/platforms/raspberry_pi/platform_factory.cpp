#include "../../../include/platform_factory.h"

#include <map>
#include <string>

#include "raspberry_pi_platform.h"

using namespace BPB::Brain::Platform;
using namespace BPB::Brain::Platform::Platforms::RaspberryPi;

std::shared_ptr<Platform> PlatformFactory::create(std::map<std::string, std::string> config)
{
    return std::make_shared<RaspberryPiPlatform>();
}