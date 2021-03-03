#ifndef BPB_BRAIN_PROGRAM_TEMPO_STATE_H
#define BPB_BRAIN_PROGRAM_TEMPO_STATE_H

#include <chrono>

namespace BPB::Brain::Program
{
    struct TempoState
    {
        TempoState() :
            lastTapTime(std::chrono::milliseconds(0)),
            timePerTick(std::chrono::milliseconds(10))
        { }

        TempoState(
            std::chrono::milliseconds lastTickTime,
            std::chrono::milliseconds timePerTick
        ) : 
            lastTapTime(lastTickTime),
            timePerTick(timePerTick) 
        { }

        std::chrono::milliseconds getLastTapTime()
        {
            return lastTapTime;
        }

        std::chrono::milliseconds getTimePerTick()
        {
            return timePerTick;
        }
        
        private:
            std::chrono::milliseconds lastTapTime;
            std::chrono::milliseconds timePerTick;
    };
}

#endif