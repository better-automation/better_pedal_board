#ifndef BPB_BRAIN_PROGRAM_TRIGGER_CONTEXT_H
#define BPB_BRAIN_PROGRAM_TRIGGER_CONTEXT_H

#include <vector>

#include "device.h"
#include "phrase_context.h"

namespace BPB::Brain::Program
{
    template <class TAction> 
    struct TriggerContext
    {
        virtual int getCondition() = 0;
        virtual bool getIsUnconditional() = 0;
        virtual const PhraseContext<TAction>& getPhrase() = 0;
        virtual const Device& getSource() = 0;
    };
}

#endif