#ifndef BPB_BRAIN_PROGRAM_LAYER_STATE_NODE_H
#define BPB_BRAIN_PROGRAM_LAYER_STATE_NODE_H

#include "layer_state.h"

namespace BPB::Brain::Program
{
    template <class TState>
    struct LayerStateNode
    {
        LayerStateNode(const LayerStateNode<TState>& node) : 
            next(node.next),
            value(node.value)
        { }

        LayerStateNode(
            const LayerState<TState>& value,
            LayerStateNode<TState>* next = nullptr
        ) : 
            value(value),
            next(next)
        { }

        LayerStateNode<TState>* getNext()
        {
            return next;
        }

        const LayerState<TState>& getValue()
        {
            return value;
        }

        private:
            LayerStateNode<TState>* next;
            const LayerState<TState>& value;
    };
}

#endif