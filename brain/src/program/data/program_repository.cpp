#include "program_repository.h"

#include <nlohmann/json.hpp>

#include <memory>
#include <istream>
#include <vector>

#include "../action.h"
#include "models/program_data.h"

using namespace BPB::Brain::Program;
using namespace BPB::Brain::Program::Data;
using namespace BPB::Brain::Program::Data::Models;
using namespace nlohmann;

std::vector<PedalContext> ProgramRepository::convertPedals(std::deque<PedalData>& data)
{
    std::vector<PedalContext> pedals;

    while (!data.empty())
    {
        PedalData& pedalData = data.front();

        pedals.push_back(PedalContext(pedalData.id, pedalData.sourceDeviceCount, pedalData.targetDeviceCount));

        data.pop_front();
    }

    return pedals;
}

std::vector<EventContext> ProgramRepository::convertEvents(std::deque<EventData>& data)
{
    std::vector<EventContext> events;

    while (!data.empty())
    {
        EventData& eventData = data.front();
    
        std::shared_ptr<TargetAction> action = actionFactory.create(eventData.actionType, eventData.config);

        events.push_back(EventContext(action, eventData.delay));

        data.pop_front();
    }

    return events;
}

std::vector<PhraseContext> ProgramRepository::convertPhrases(std::deque<PhraseData>& data)
{
    std::vector<PhraseContext> phrases;

    while (!data.empty())
    {
        PhraseData& phraseData = data.front();

        phrases.push_back(PhraseContext(phraseData.delay, phraseData.repeatInterval, convertEvents(phraseData.eventQueue)));

        data.pop_front();
    }

    return phrases;
}

std::vector<TriggerContext> ProgramRepository::convertTriggers(std::deque<TriggerData>& data)
{
    std::vector<TriggerContext> triggers;

    while (!data.empty())
    {
        TriggerData& triggerData = data.front();

        triggers.push_back(TriggerContext(triggerData.deviceSourceStateCondition, triggerData.isUnconditional, triggerData.sourcePedalIndex, triggerData.sourceDeviceIndex, triggerData.targetPedalIndex, triggerData.targetDeviceIndex, convertPhrases(triggerData.phrases)));
    
        data.pop_front();
    }

    return triggers;
}

ProgramContext ProgramRepository::getProgram(std::istream& programData)
{
    ProgramData data = json::parse(programData);

    return ProgramContext(
        convertPedals(data.pedals),
        convertTriggers(data.triggers)
    );
}