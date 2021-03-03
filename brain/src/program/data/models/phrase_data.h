#ifndef BPB_BRAIN_PROGRAM_DATA_MODELS_PHRASE_DATA_H
#define BPB_BRAIN_PROGRAM_DATA_MODELS_PHRASE_DATA_H

#include <nlohmann/json.hpp>

#include <deque>

#include "event_data.h"

namespace BPB::Brain::Program::Data::Models
{
    struct PhraseData {
        int delay;
        int repeatInterval;
        unsigned long scheduledStartTime;
        std::deque<EventData> eventQueue;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PhraseData, delay, repeatInterval, scheduledStartTime, eventQueue);
}

#endif