#ifndef BPB_PEDAL_DEVICE_SOURCE_DEVICE_H
#define BPB_PEDAL_DEVICE_SOURCE_DEVICE_H

#include <vector>

namespace BPB::Pedal::Device
{
    class SourceDevice
    {
        public:
            virtual ~SourceDevice() { }

            virtual int getState(std::vector<int>& pins) = 0;
    };
}

#endif