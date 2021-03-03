#ifndef BPB_BRAIN_PLATFORM_PLATFORM_FACTORY_H
#define BPB_BRAIN_PLATFORM_PLATFORM_FACTORY_H

#include <memory>

#include "../../../platform_core/include/platform.h"

using namespace BPB::PlatformCore;

namespace BPB::Brain::Platform
{
    class PlatformFactory
    {
        public:
            static std::shared_ptr<PlatformCore::Platform> create();
    };
}

#endif