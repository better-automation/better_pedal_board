#ifndef BPB_BRAIN_PROGRAM_LAYER_STATE_LIST_H
#define BPB_BRAIN_PROGRAM_LAYER_STATE_LIST_H

#include <vector>

#include "layer_state_node.h"

namespace BPB::Brain::Program
{
    template<class TState>
    class LayerStateList
    {
        private:
            LayerStateNode<TState>* head;

        public:
            LayerStateList(LayerStateNode<TState>* head = nullptr)
                : head(head) { }

            LayerStateList<TState> add(LayerStateNode<TState>* nodeToAdd);
            LayerStateNode<TState>* begin();
            LayerStateList<TState> remove(LayerStateNode<TState>* nodeToRemove);
    };
}

#endif