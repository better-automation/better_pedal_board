#ifndef BPB_BRAIN_PROGRAM_STATE_CHANGE_H
#define BPB_BRAIN_PROGRAM_STATE_CHANGE_H

namespace BPB::Brain::Program
{
    template <class TState>
    struct StateChange
    {
        bool hasValue;
        TState value;

        StateChange() :
            hasValue(false)
        { }

        StateChange(
            TState value
        ) :
            hasValue(true),
            value(value)
        { }
    };
}

#endif