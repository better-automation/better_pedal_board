#ifndef BPB_PEDAL_DEVICE_SOURCE_DEVICES_LATCHING_FOOTSWITCH_H
#define BPB_PEDAL_DEVICE_SOURCE_DEVICES_LATCHING_FOOTSWITCH_H

#include <vector>

#include "../source_device.h"

using namespace BPB::Pedal::Device;

namespace BPB::Pedal::Device::SourceDevices
{
    class LatchingFootswitch : public SourceDevice
    {
        private:
            int sourcePin;

        public:
            LatchingFootswitch(int sourcePin) : sourcePin(sourcePin) { }

            int getState(std::vector<int>& pins);
    };
}

#endif