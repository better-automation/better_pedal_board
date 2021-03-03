#ifndef BPB_BRAIN_PROGRAM_DATA_MODELS_PEDAL_DATA_H
#define BPB_BRAIN_PROGRAM_DATA_MODELS_PEDAL_DATA_H

#include <nlohmann/json.hpp>

#include <string>

namespace BPB::Brain::Program::Data::Models
{
    struct PedalData
    {
        std::string id;
        int sourceDeviceCount;
        int targetDeviceCount;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PedalData, id, sourceDeviceCount, targetDeviceCount);
}

#endif