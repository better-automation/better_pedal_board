#ifndef BPB_PEDAL_PLATFORM_PLATFORM_SERVICE_H
#define BPB_PEDAL_PLATFORM_PLATFORM_SERVICE_H

#include <functional>
#include <memory>
#include <vector>

#include "../../../shared/include/platform/command_bus.h"
#include "../src/platform.h"

using namespace BPB::Shared::Platform;

namespace BPB::Pedal::Platform
{
    class PlatformService
    {
        private:
            CommandBus commandBus;
            std::function<std::shared_ptr<Platform>()> createPlatform;
            std::shared_ptr<Platform> platform;

        public:
            PlatformService(
                std::function<std::shared_ptr<Platform>()> createPlatform
            ) : 
                createPlatform(createPlatform)
            { }

            void clearCommand();
            std::vector<int> createSourcePinState();
            std::vector<int> createTargetPinState();
            std::string& getCommand();
            void initialize(std::vector<int>& sourceState);
            void loadPlatform();
            void readTargetDeviceState(std::vector<int>& targetDeviceState);
            void readPinState(std::vector<int>& sourceState);
            void writePinState(std::vector<int>& previousTargetState, std::vector<int>& targetState);
    };
}

#endif