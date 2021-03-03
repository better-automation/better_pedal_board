#ifndef BPB_PEDAL_DEVICES_H
#define BPB_PEDAL_DEVICES_H

#include <memory>
#include <vector>

#include "source_device.h"
#include "target_device.h"

namespace BPB::Pedal::Device
{
    struct Devices
    {
        std::vector<std::shared_ptr<SourceDevice>> sourceDevices;
        std::vector<std::shared_ptr<TargetDevice>> targetDevices;

        Devices(
            std::vector<std::shared_ptr<SourceDevice>> sourceDevices = {}, 
            std::vector<std::shared_ptr<TargetDevice>> targetDevices = {}
        ) : 
            sourceDevices(sourceDevices), 
            targetDevices(targetDevices)
        { }
    };
}

#endif