#ifndef BPB_BRAIN_BRAIN_CONTROLLER_H
#define BPB_BRAIN_BRAIN_CONTROLLER_H

#include <vector>

#include "../../platform_core/include/controller.h"
#include "platform/platform_service.h"
#include "program/program_service.h"
#include "program/program_state.h"

using namespace BPB::PlatformCore;
using namespace BPB::Brain::Platform;
using namespace BPB::Brain::Program;

namespace BPB::Brain
{
    class BrainController : public Controller
    {
        private:
            PlatformService& platformService;
            ProgramService& programService;
            ProgramState& programState;
            std::vector<std::vector<int>>& sourceStates;
            std::vector<std::vector<int>>& targetStates;

        public:
            BrainController(
                PlatformService& platformService,
                ProgramService& programService,
                ProgramState& programState,
                std::vector<std::vector<int>>& sourceStates,
                std::vector<std::vector<int>>& targetStates
            ) :
                platformService(platformService),
                programService(programService),
                programState(programState),
                sourceStates(sourceStates),
                targetStates(targetStates)
            { }

            void updateProgram();
    };
}

#endif