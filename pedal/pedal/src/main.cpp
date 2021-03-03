#include <vector>

#include "command_controller.h"
#include "../../../shared/include/data/data_store.h"
#include "../../device/include/device_service.h"
#include "../../platform/include/platform_factory.h"
#include "../../platform/include/platform_service.h"

using namespace BPB::Pedal;
using namespace BPB::Pedal::Device;
using namespace BPB::Pedal::Platform;
using namespace BPB::Shared::Data;

int main()
{
    DataStore dataStore("../../dev-data/");

    PlatformService platformService(PlatformFactory::create);

    platformService.loadPlatform();

    DeviceService deviceService(dataStore);

    deviceService.loadDevices();

    CommandController controller(platformService, deviceService);

    std::vector<int> platformSourceState;
    std::vector<int> platformTargetState;
    std::vector<int> sourceDeviceState;
    std::vector<int> targetDeviceState;

    while (true)
    {
        std::vector<int> previousPlatformSourceState = platformSourceState;

        platformService.readPinState(platformSourceState);

        std::string& command = platformService.getCommand();

        if (!command.empty())
        {
            controller.runCommand(command, platformSourceState, platformTargetState, sourceDeviceState, targetDeviceState);

            platformService.clearCommand();
        }

        deviceService.updateSourceDeviceState(platformSourceState, sourceDeviceState);
    }
}