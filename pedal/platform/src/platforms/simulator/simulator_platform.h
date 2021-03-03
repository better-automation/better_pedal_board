#ifndef BPB_PEDAL_PLATFORMS_SIMULATOR_SIMULATOR_PLATFORM_H
#define BPB_PEDAL_PLATFORMS_SIMULATOR_SIMULATOR_PLATFORM_H

#include <string>
#include <vector>

#include "../../../src/platform.h"
#include "../../../../../shared/include/platform/simulator/simulator_serial_reader.h"

using namespace BPB::Shared::Platform::Simulator;

namespace BPB::Pedal::Platform::Platforms::Simulator
{
    class SimulatorPlatform : public Platform
    {
        private:
            SimulatorSerialReader reader;
            int sourcePinCount = 8;
            int targetPinCount = 8;

            void updateResult(std::string& input, std::vector<int>& result);

        public:
            SimulatorPlatform(SimulatorSerialReader reader) : reader(reader) { }

            int getSourcePinCount();
            int getTargetPinCount();
            void initialize(std::vector<int>& sourceState);
            void readPins(std::vector<int>& result, CommandBus& commandBus);
            void writePins(std::vector<int>& previousState, std::vector<int>& state);
    };
}

#endif