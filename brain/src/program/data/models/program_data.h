#ifndef BPB_BRAIN_PROGRAM_DATA_MODELS_PROGRAM_DATA_H
#define BPB_BRAIN_PROGRAM_DATA_MODELS_PROGRAM_DATA_H

#include <nlohmann/json.hpp>

#include <deque>

#include "pedal_data.h"
#include "trigger_data.h"

namespace BPB::Brain::Program::Data::Models
{
    struct ProgramData
    {
        std::deque<PedalData> pedals;
        std::deque<TriggerData> triggers;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ProgramData, pedals, triggers);
}

#endif