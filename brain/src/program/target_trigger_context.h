#ifndef BPB_BRAIN_PROGRAM_TARGET_TRIGGER_CONTEXT_H
#define BPB_BRAIN_PROGRAM_TARGET_TRIGGER_CONTEXT_H

#include "trigger_context.h"

#include <vector>

#include "device.h"
#include "phrase_context.h"
#include "target_action.h"

namespace BPB::Brain::Program
{
    struct TargetTriggerContext : public TriggerContext<TargetAction>
    {
        TargetTriggerContext(
            Device source,
            bool isUnconditional,
            int condition,
            PhraseContext<TargetAction> phrase,
            Device target
        ) :
            source(source),
            isUnconditional(isUnconditional),
            condition(condition),
            phrase(phrase),
            target(target)
        { }

        int getCondition()
        {
            return condition;
        }

        bool getIsUnconditional()
        {
            return isUnconditional;
        }

        const PhraseContext<TAction>& getPhrase()
        {
            return phrase;
        }

        const Device& getSource()
        {
            return source;
        }

        const Device& getTarget()
        {
            return target;
        }

        private:
            int condition;
            bool isUnconditional;
            PhraseContext<TargetAction> phrase;
            Device source;
            Device target;
    };
}

#endif