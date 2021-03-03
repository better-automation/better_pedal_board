#ifndef BPB_PEDAL_PLATFORM_PLATFORM_H
#define BPB_PEDAL_PLATFORM_PLATFORM_H

#include <vector>

#include "../../../shared/include/platform/command_bus.h"

using namespace BPB::Shared::Platform;

namespace BPB::Pedal::Platform
{
    class Platform
    {
        public:
            virtual ~Platform() { }

            virtual int getSourcePinCount() = 0;
            virtual int getTargetPinCount() = 0;
            virtual void initialize(std::vector<int>& sourceState) = 0;
            virtual void readPins(std::vector<int>& result, CommandBus& commandBus) = 0;
            virtual void writePins(std::vector<int>& previousState, std::vector<int>& state) = 0;
    };
}

#endif