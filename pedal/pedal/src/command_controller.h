#ifndef BPB_PEDAL_COMMAND_CONTROLLER_H
#define BPB_PEDAL_COMMAND_CONTROLLER_H

#include <vector>

#include "../../device/include/device_service.h"
#include "../../platform/include/platform_service.h"

using namespace BPB::Pedal::Device;
using namespace BPB::Pedal::Platform;

namespace BPB::Pedal
{
    class CommandController
    {
        private:
            DeviceService& deviceService;
            PlatformService& platformService;

            void initializePlatform(std::vector<int>& platformSourceState);
            void updateTargetState(std::vector<int>& targetDeviceState, std::vector<int>& platformTargetState);

        public:
            CommandController(
                PlatformService& platformService,
                DeviceService& deviceService
            ) : 
                platformService(platformService),
                deviceService(deviceService)
            { }

            void runCommand(std::string& command, std::vector<int>& platformSourceState, std::vector<int>& platformTargetState, std::vector<int>& sourceDeviceState, std::vector<int>& targetDeviceState);
    };
}

#endif