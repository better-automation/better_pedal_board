#include "../../../include/platform_factory.h"

#include <memory>

#include "simulator_platform.h"
#include "../../../../../shared/include/platform/simulator/simulator_serial_reader.h"

using namespace BPB::Pedal::Platform;
using namespace BPB::Pedal::Platform::Platforms::Simulator;
using namespace BPB::Shared::Platform::Simulator;

std::shared_ptr<Platform> PlatformFactory::create()
{
    return std::make_shared<SimulatorPlatform>(SimulatorSerialReader());
}