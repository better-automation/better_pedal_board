#ifndef BPB_PEDAL_DEVICE_DATA_MODELS_DEVICE_DATA_H
#define BPB_PEDAL_DEVICE_DATA_MODELS_DEVICE_DATA_H

#include <nlohmann/json.hpp>

#include <map>
#include <string>

namespace BPB::Pedal::Device::Data::Models
{
    struct DeviceData
    {
        std::map<std::string, std::string> config;
        std::string type;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DeviceData, config, type);
}

#endif