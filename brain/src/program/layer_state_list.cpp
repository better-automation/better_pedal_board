#include "layer_state_list.h"

using namespace BPB::Brain::Program;

template<class TState>
LayerStateList<TState> LayerStateList<TState>::add(LayerStateNode<TState>* nodeToAdd)
{
    LayerStateNode<TState>* headNode = (head == nodeToAdd) ? head->getNext() : head;

    if (head == nullptr)
    {
        *nodeToAdd = LayerStateNode(nodeToAdd->getValue());

        return LayerStateList<TState>(nodeToAdd);
    }

    for (LayerStateNode<TState>* node = headNode; node != nullptr; node = node->getNext())
    {
        if (node->getNext() == nodeToAdd)
        {
            *node = LayerStateNode(node->getValue(), node->getNext()->getNext());
        }

        if (node->getNext() == nullptr)
        {
            *nodeToAdd = LayerStateNode(nodeToAdd->getValue());

            *node = LayerStateNode(node->getValue(), nodeToAdd);

            break;
        }
    }

    return LayerStateList<TState>(headNode);
}

template<class TState>
LayerStateNode<TState>* LayerStateList<TState>::begin()
{
    return head;
}

template<class TState>
LayerStateList<TState> LayerStateList<TState>::remove(LayerStateNode<TState>* nodeToRemove)
{
    if (head == nullptr)
    {
        return LayerStateList();
    }

    if (head == nodeToRemove)
    {
        return LayerStateList(head->getNext());
    }

    for (LayerStateNode<TState>* node = head; node->getNext() != nullptr; node = node->getNext())
    {
        if (node->getNext() == nodeToRemove)
        {
            *node = LayerStateNode(node->getValue(), node->getNext()->getNext());

            break;
        }
    }

    return LayerStateList<TState>(head);
}