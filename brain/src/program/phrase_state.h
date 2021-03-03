#ifndef BPB_BRAIN_PROGRAM_PHRASE_STATE_H
#define BPB_BRAIN_PROGRAM_PHRASE_STATE_H

namespace BPB::Brain::Program
{
    struct PhraseState
    {
        PhraseState() :
            nextEventIndex(0),
            nextEventScheduledTime(0),
            scheduledStartTime(0)
        { }

        PhraseState(
            int nextEventIndex,
            unsigned long nextEventScheduledTime,
            unsigned long scheduledStartTime
        ) :
            nextEventIndex(nextEventIndex),
            nextEventScheduledTime(nextEventScheduledTime),
            scheduledStartTime(scheduledStartTime)
        { }

        int getNextEventIndex()
        {
            return nextEventIndex;
        }

        unsigned long getNextEventScheduledTime()
        {
            return nextEventScheduledTime;
        }

        unsigned long getScheduledStartTime()
        {
            return scheduledStartTime;
        }

        private:
            int nextEventIndex;
            unsigned long nextEventScheduledTime;
            unsigned long scheduledStartTime;
    };
}

#endif