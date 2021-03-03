#ifndef BPB_PEDAL_DEVICE_SOURCE_DEVICE_FACTORY_H
#define BPB_PEDAL_DEVICE_SOURCE_DEVICE_FACTORY_H

#include <map>
#include <memory>
#include <string>

#include "source_device.h"

namespace BPB::Pedal::Device
{
    class SourceDeviceFactory
    {
        public:
            std::shared_ptr<SourceDevice> create(std::string& type, std::map<std::string, std::string>& config);
    };
}

#endif