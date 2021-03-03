#ifndef BPB_BRAIN_PROGRAM_TRIGGER_STATE_H
#define BPB_BRAIN_PROGRAM_TRIGGER_STATE_H

#include <vector>

#include "layer_state.h"
#include "phrase_state.h"

namespace BPB::Brain::Program
{
    template<class TState>
    struct TriggerState
    {
        LayerState<TState> layer;
        PhraseState phrase;
        int triggerIndex;

        ProgramState(
            LayerState<TState> layer;
            PhraseState phrase;
            int triggerIndex;
        ) :
            triggerLayers(triggerLayers),
            triggerPhrases(triggerPhrases)
        { }
    };
}

#endif
