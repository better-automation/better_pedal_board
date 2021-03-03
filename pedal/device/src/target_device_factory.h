#ifndef BPB_PEDAL_DEVICE_TARGET_DEVICE_FACTORY_H
#define BPB_PEDAL_DEVICE_TARGET_DEVICE_FACTORY_H

#include <map>
#include <memory>
#include <string>

#include "target_device.h"

namespace BPB::Pedal::Device
{
    class TargetDeviceFactory
    {
        public:
            std::shared_ptr<TargetDevice> create(std::string& type, std::map<std::string, std::string>& config);
    };
}

#endif