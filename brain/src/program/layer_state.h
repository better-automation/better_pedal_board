#ifndef BPB_BRAIN_PROGRAM_LAYER_STATE_H
#define BPB_BRAIN_PROGRAM_LAYER_STATE_H

#include "phrase_state.h"

namespace BPB::Brain::Program
{
    template<class TState>
    struct LayerState
    {
        LayerState() :
            hasValue(false)
        { }

        LayerState(
            TState value
        ) :
            value(value),
            hasValue(true)
        { }

        bool getHasValue()
        {
            return hasValue;
        }

        const TState& getValue()
        {
            return value;
        }

        private:
            bool hasValue;
            TState value;
    };
}

#endif