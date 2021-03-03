#include "../target_state_action_factory.h"

#include "mimic_action.h"
#include "set_state_action.h"

using namespace BPB::Brain::Program::Actions;
using namespace BPB::Brain::Program;

std::shared_ptr<TargetAction> TargetActionFactory::create(std::string type, std::map<std::string, std::string> config)
{
    if (type == "Mimic")
    {
        return std::make_shared<MimicAction>();
    }

    if (type == "Set State")
    {
        return std::make_shared<SetStateAction>(std::stoi(config["targetState"]));
    }

    return NULL;
}