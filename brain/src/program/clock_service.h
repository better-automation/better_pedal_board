#ifndef BPB_BRAIN_PROGRAM_CLOCK_SERVICE_H
#define BPB_BRAIN_PROGRAM_CLOCK_SERVICE_H

#include <chrono>

#include "clock_state.h"
#include "tempo_state.h"

namespace BPB::Brain::Program
{
    class ClockService
    {
        public:
            ClockState updateClockState(std::chrono::milliseconds now, const TempoState& tempo, const ClockState& state);
    };
}

#endif