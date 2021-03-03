#include "program_service.h"

#include "event_context.h"
#include "target_action.h"
#include "tempo_action.h"

using namespace BPB::Brain::Program;

template <class TAction, class TState>
PhraseState repeatPhrase(PhraseContext<TAction> phrase, PhraseState phraseState)
{
    int phraseStartTime = phraseState.scheduledStartTime + phrase.repeatInterval;
    unsigned long nextEventScheduledTime = phraseStartTime + phrase.events[0].delay;

    return PhraseState(0, nextScheduledEventTime, phraseStartTime);
}

template <class TAction, class TState>
PhraseState startPhrase(PhraseContext<TAction> phrase)
{
    int phraseStartTime = clock.totalTicksElapsedCount + phrase.delay;
    unsigned long nextEventScheduledTime = phraseStartTime + phrase.events[0].delay;

    return PhraseState(0, nextScheduledEventTime, phraseStartTime);
}

template <class TAction, class TState>
StateChange<TState> ProgramService<TAction, TState>::runScheduledEvents(PhraseContext<TAction> phrase, int sourceState, PhraseState& phraseState)
{
    StateChange<TState> stateChange;

    while (phraseState.nextEventScheduledTime <= clock.totalTicksElapsedCount)
    {
        if (phraseState.nextEventIndex == phrase.events.size())
        {
            if (phrase.repeatInterval == 0)
            {
                break;
            }
                
            phraseState = repeatPhrase(phrase, phraseState);
        }

        int eventIndex = phraseState.nextEventIndex;

        EventContext<TAction>& event = phrase.events[eventIndex];

        stateChange = actionRunner.getStateChange(*event.action, sourceState);
    
        int nextEventIndex = eventIndex + 1;

        phraseState.nextEventIndex = nextEventIndex;

        if (nextEventIndex < phrase.events.size())
        {
            EventContext<TAction>& nextEvent = phrase.events[nextEventIndex];

            phraseState.nextEventScheduledTime = phraseState.scheduledStartTime + nextEvent.delay;
        }
    }

    return stateChange;
}

template <class TAction, class TState>
TState ProgramService<TAction, TState>::runScheduledEvents(LayerStateList<TState>& destination)
{
    TState destinationState = actionRunner.getDefaultState();

    for (LayerStateNode<TState>& layer = *destination.begin(); layer != null; layer = layer.next)
    {
        int triggerIndex = layer.triggerIndex;
        TriggerContext<TAction>& trigger = context.triggers[triggerIndex];
        int sourceState = sources[trigger.source.pedalIndex].current[trigger.source.deviceIndex];
        PhraseState& phraseState = state.triggerPhrases[triggerIndex];

        StateChange<TState> stateChange = runScheduledEvents(trigger.phrase, sourceState, phraseState);
        
        if (!stateChange.hasValue)
        {
            continue;
        }

        destinationState = stateChange.value;
    }

    return destinationState;
}

template <class TAction, class TState> 
LayerStateList<TState> ProgramService<TAction, TState>::runTrigger(const LayerState<TState>& layer, int triggerIndex)
{
    TriggerContext<TAction> trigger = context.triggers[triggerIndex];

    PedalSourceState& source = sources[trigger.source.pedalIndex];

    int previousSourceState = source.previous[trigger.source.deviceIndex];
    int sourceState = source.current[trigger.source.deviceIndex];

    if (source.arePreviousStatesAvailable && sourceState == previousSourceState)
    {
        return destination;
    }

    if (trigger.isUnconditional || sourceState == trigger.condition)
    {
        state.triggerPhrases[triggerIndex] = startPhrase(trigger.phrase);

/*
    BASICALLY WHAT THIS BOILS DOWN TO IS THAT I'M GOING TO COPY THE ENTIRE PROGRAM/TRIGGER STATE 
*/


        return layer.add(layers);
    }
    
    return destination.remove(destination, layers);
}

template class BPB::Brain::Program::ProgramService<BPB::Brain::Program::Tests::ProgramServiceTests::MockAction, int>;
template class BPB::Brain::Program::ProgramService<TargetAction, int>;
template class BPB::Brain::Program::ProgramService<TempoAction, TempoState>;
