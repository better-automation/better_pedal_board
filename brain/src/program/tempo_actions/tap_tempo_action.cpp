#include "tap_tempo_action.h"

using namespace BPB::Brain::Program;
using namespace BPB::Brain::Program::TempoActions;

const std::chrono::milliseconds TAP_TEMPO_DEBOUNCE_RATE(1);

StateChange<TempoState> TapTempoAction::getTempoState(int sourceDeviceState, std::chrono::milliseconds lastTickTime, TempoState tempo)
{
    std::chrono::milliseconds timePerBeat = lastTickTime - tempo.lastTapTime;

    if (timePerPeat < TAP_TEMPO_DEBOUNCE_RATE)
    {
        return StateChange(tempo);
    }

    if (timePerBeat > std::chrono::seconds(4))
    {
        return StateChange(TempoState(lastTickTime, tempo.timePerTick));
    }

    std::chrono::milliseconds timePerTick = timePerBeat / ClockState::TICKS_PER_BEAT;

    return StateChange(TempoState(lastTickTime, timePerTick));
}