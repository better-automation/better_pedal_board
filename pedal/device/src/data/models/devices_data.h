#ifndef BPB_PEDAL_DEVICE_DATA_MODELS_PEDAL_DATA_H
#define BPB_PEDAL_DEVICE_DATA_MODELS_PEDAL_DATA_H

#include <nlohmann/json.hpp>

#include <deque>

#include "device_data.h"

namespace BPB::Pedal::Device::Data::Models
{
    struct DevicesData
    {
        std::deque<DeviceData> sourceDevices;
        std::deque<DeviceData> targetDevices;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DevicesData, sourceDevices, targetDevices);
}

#endif