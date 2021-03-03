#ifndef BPB_BRAIN_PROGRAM_DATA_MODELS_TRIGGER_DATA_H
#define BPB_BRAIN_PROGRAM_DATA_MODELS_TRIGGER_DATA_H

#include <nlohmann/json.hpp>

#include <deque>

#include "phrase_data.h"

namespace BPB::Brain::Program::Data::Models
{
    struct TriggerData
    {
        int deviceSourceStateCondition;
        bool isUnconditional;
        std::deque<PhraseData> phrases;
        int sourceDeviceIndex;
        int sourcePedalIndex;
        int targetDeviceIndex;
        int targetPedalIndex;

        NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TriggerData, deviceSourceStateCondition, isUnconditional, phrases, sourceDeviceIndex, sourcePedalIndex, targetDeviceIndex, targetPedalIndex);
    };
}

#endif