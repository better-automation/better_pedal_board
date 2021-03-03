#ifndef BPB_BRAIN_PROGRAM_DATA_MODELS_EVENT_DATA_H
#define BPB_BRAIN_PROGRAM_DATA_MODELS_EVENT_DATA_H

#include <nlohmann/json.hpp>

#include <map>
#include <string>

namespace BPB::Brain::Program::Data::Models
{
    struct EventData
    {
        std::string actionType;
        std::map<std::string, std::string> config;
        int delay;
        int targetDeviceIndex;
        int targetPedalIndex;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(EventData, actionType, config, delay, targetDeviceIndex, targetPedalIndex);
}

#endif