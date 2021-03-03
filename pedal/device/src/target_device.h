#ifndef BPB_PEDAL_DEVICE_TARGET_DEVICE_H
#define BPB_PEDAL_DEVICE_TARGET_DEVICE_H

#include <vector>

namespace BPB::Pedal::Device
{
    class TargetDevice
    {
        public:
            virtual ~TargetDevice() { }

            virtual void setPins(int state, std::vector<int>& targetPins) = 0;
    };
}

#endif