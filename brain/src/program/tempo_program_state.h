#ifndef BPB_BRAIN_PROGRAM_TEMPO_PROGRAM_STATE_H
#define BPB_BRAIN_PROGRAM_TEMPO_PROGRAM_STATE_H

#include <chrono>

#include "layer_state.h"
#include "program_state.h"
#include "tempo_state.h"

namespace BPB::Brain::Program
{
    struct TempoProgramState : public ProgramState<TempoState>
    {
        TempoState tempo;
        LayerState<TempoState> tempoLayer;

        TempoProgramState(
            TempoState tempo,
            LayerState<TempoState> tempoLayer,
            std::vector<LayerState<TempoState>> triggerLayers,
            std::vector<std::vector<PhraseState>> triggerPhrases
        ) :
            tempo(tempo),
            tempoLayer(tempoLayer),
            ProgramState(triggerLayers, triggerPhrases)
        { }
    };
}

#endif