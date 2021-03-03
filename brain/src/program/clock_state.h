#ifndef BPB_BRAIN_PROGRAM_CLOCK_STATE_H
#define BPB_BRAIN_PROGRAM_CLOCK_STATE_H

#include <chrono>

namespace BPB::Brain::Program
{
    struct ClockState
    {
        ClockState(
            std::chrono::milliseconds now,
            unsigned long totalTicksElapsedCount = 0
        ) : 
            lastTickTime(now),
            totalTicksElapsedCount(totalTicksElapsedCount)
        { }

        std::chrono::milliseconds getLastTickTime()
        {
            return lastTickTime;
        }

        unsigned long getTotalTicksElapsedCount()
        {
            return totalTicksElapsedCount;
        }

        private:
            static const int TICKS_PER_BEAT = 48;
            
            std::chrono::milliseconds lastTickTime;
            unsigned long totalTicksElapsedCount;
    };
}

#endif