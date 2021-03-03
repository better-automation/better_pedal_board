#ifndef BPB_BRAIN_PROGRAM_EVENT_CONTEXT_H
#define BPB_BRAIN_PROGRAM_EVENT_CONTEXT_H

#include <memory>

namespace BPB::Brain::Program
{
    template <class TAction> struct EventContext
    {
        EventContext(
            std::shared_ptr<TAction> action,
            int delay
        ) : 
            action(action),
            delay(delay)
        { }

        std::shared_ptr<TAction> getAction()
        {
            return action;
        }

        int getDelay()
        {
            return delay;
        }

        private:
            std::shared_ptr<TAction> action;
            int delay;
    };
}

#endif