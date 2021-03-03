#ifndef BPB_BRAIN_PROGRAM_ACTION_FACTORY_H
#define BPB_BRAIN_PROGRAM_ACTION_FACTORY_H

#include <map>
#include <memory>
#include <string>

#include "target_action.h"

namespace BPB::Brain::Program
{
    class TargetActionFactory
    {
        public:
            std::shared_ptr<TargetAction> create(std::string type, std::map<std::string, std::string> config);
    };
}

#endif