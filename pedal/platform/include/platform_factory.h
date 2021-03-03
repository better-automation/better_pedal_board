#ifndef BPB_PEDAL_PLATFORM_PLATFORM_FACTORY_H
#define BPB_PEDAL_PLATFORM_PLATFORM_FACTORY_H

#include <memory>

#include "../src/platform.h"

namespace BPB::Pedal::Platform
{
    class PlatformFactory
    {
        public:
            static std::shared_ptr<Platform> create();
    };
}

#endif