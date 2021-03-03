#include "clock_service.h"

using namespace BPB::Brain::Program;

ClockState ClockService::updateClockState(std::chrono::milliseconds now, const TempoState& tempo, const ClockState& state)
{
    std::chrono::milliseconds lastTickTime = state.getLastTickTime();
    unsigned long totalTicksElapsedCount = state.getTotalTicksElapsedCount();
    std::chrono::milliseconds timePerTick = tempo.getTimePerTick();

    int ticksElapsed = (now - lastTickTime) / timePerTick;
    
    std::chrono::milliseconds timeElapsed = ticksElapsed * timePerTick;

    lastTickTime += timeElapsed;
    totalTicksElapsedCount += ticksElapsed;

    return ClockState(lastTickTime, totalTicksElapsedCount);
}