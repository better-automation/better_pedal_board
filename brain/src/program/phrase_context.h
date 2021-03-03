#ifndef BPB_BRAIN_PROGRAM_PHRASE_CONTEXT_H
#define BPB_BRAIN_PROGRAM_PHRASE_CONTEXT_H

#include <vector>

#include "event_context.h"

namespace BPB::Brain::Program
{
    template <class TAction> 
    struct PhraseContext
    {
        PhraseContext(
            int delay,
            int repeatInterval,
            std::vector<EventContext<TAction>> events
        ) :
            delay(delay),
            repeatInterval(repeatInterval),
            events(events)
        { }

        int getDelay()
        {
            return delay;
        }

        int getRepeatInterval()
        {
            return repeatInterval;
        }

        const std::vector<EventContext<TAction>>& getEvents()
        {
            return events;
        }

        private:
            int delay;
            std::vector<EventContext<TAction>> events;
            int repeatInterval;
    };
}

#endif