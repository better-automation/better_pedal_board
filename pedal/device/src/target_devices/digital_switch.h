#ifndef BPB_PEDAL_DEVICE_TARGET_DEVICES_DIGITAL_SWITCH_H
#define BPB_PEDAL_DEVICE_TARGET_DEVICES_DIGITAL_SWITCH_H

#include <vector>

#include "../target_device.h"

using namespace BPB::Pedal::Device;

namespace BPB::Pedal::Device::TargetDevices
{
    class DigitalSwitch : public TargetDevice
    {
        private:
            int targetPin;

        public:
            DigitalSwitch(int targetPin) : targetPin(targetPin) { }

            void setPins(int state, std::vector<int>& targetPins);
    };
}

#endif