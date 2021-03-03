#ifndef BPB_BRAIN_PROGRAM_TARGET_PROGRAM_STATE_H
#define BPB_BRAIN_PROGRAM_TARGET_PROGRAM_STATE_H

#include <vector>

#include "layer_state_node.h"
#include "program_state.h"

namespace BPB::Brain::Program
{
    struct TargetProgramState : ProgramState<int>
    {
        std::vector<std::vector<LayerStateNode<int>*>> targetLayers;

        TargetProgramState(
            std::vector<std::vector<LayerStateNode<int>*>> targetLayers,
            std::vector<LayerStateNode<int>> triggerLayers,
            std::vector<std::vector<PhraseState>> triggerPhrases
        ) :
            ProgramState(triggerLayers, triggerPhrases),
            targetLayers(targetLayers)
        { }
    };
}

#endif