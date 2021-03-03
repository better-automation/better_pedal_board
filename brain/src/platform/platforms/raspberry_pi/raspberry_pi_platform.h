#ifndef BPB_BRAIN_PLATFORM_PLATFORMS_RAPSBERRY_PI_RASPBERRY_PI_PLATFORM_H
#define BPB_BRAIN_PLATFORM_PLATFORMS_RAPSBERRY_PI_RASPBERRY_PI_PLATFORM_H

#include <chrono>
#include <string>
#include <vector>

#include "../../../../../shared/include/platform/command_bus.h"
#include "../../platform.h"

using namespace BPB::Brain::Platform;

namespace BPB::Brain::Platform::Platforms::RaspberryPi
{
    class RaspberryPiPlatform : public Platform
    {
        private:
            int sourcePinCount = 4;
            int targetPinCount = 4;

        public:
            std::chrono::milliseconds getNow();
            int getSourcePinCount();
            int getTargetPinCount();
            void initialize(std::vector<int>& pedalSourceStates);
            void read(std::vector<int>& result, CommandBus& commandBus);
            std::string readInstructions();
            void write(std::vector<int>& previousState, std::vector<int>& state);
    };
}

#endif