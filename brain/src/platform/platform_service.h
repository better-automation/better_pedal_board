#ifndef BPB_BRAIN_PLATFORM_PLATFORM_SERVICE_H
#define BPB_BRAIN_PLATFORM_PLATFORM_SERVICE_H

#include <chrono>
#include <functional>
#include <istream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../../../platform_core/include/platform.h"

using namespace BPB::PlatformCore;

namespace BPB::Brain::Platform
{
    class PlatformService
    {
        private:
            std::shared_ptr<PlatformCore::Platform> platform;

        public:
            PlatformService(
                std::function<std::shared_ptr<PlatformCore::Platform>()> createPlatform
            ) : 
                platform(createPlatform())
            { }

            std::chrono::milliseconds getNow();
            std::shared_ptr<std::istream> getProgramData();
            void read(Controller& controller, std::vector<std::vector<int>>& result);
            void writePedalTargetStates(std::vector<std::vector<int>>& previousStates, std::vector<std::vector<int>>& states);
    };
}

#endif