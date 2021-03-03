#ifndef BPB_BRAIN_PROGRAM_DATA_PROGRAM_REPOSITORY_H
#define BPB_BRAIN_PROGRAM_DATA_PROGRAM_REPOSITORY_H

#include <istream>
#include <string>
#include <vector>

#include "../action_factory.h"
#include "../event_context.h"
#include "models/event_data.h"
#include "../pedal_context.h"
#include "models/pedal_data.h"
#include "../phrase_context.h"
#include "models/phrase_data.h"
#include "../program_context.h"
#include "models/trigger_data.h"
#include "../trigger_context.h"

using namespace BPB::Brain::Program;
using namespace BPB::Brain::Program::Data::Models;

namespace BPB::Brain::Program::Data
{
    class ProgramRepository
    {
        private:
            TargetActionFactory actionFactory;

            std::vector<EventContext> convertEvents(std::deque<EventData>& data);
            std::vector<PedalContext> convertPedals(std::deque<PedalData>& data);
            std::vector<PhraseContext> convertPhrases(std::deque<PhraseData>& data);
            std::vector<TriggerContext> convertTriggers(std::deque<TriggerData>& data);

        public:
            ProgramRepository(
                TargetActionFactory actionFactory
            ) : 
                actionFactory(actionFactory) 
            { }

            ProgramContext getProgram(std::istream& programData);
    };
}

#endif