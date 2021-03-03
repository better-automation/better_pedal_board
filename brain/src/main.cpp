#include <map>
#include <string>
#include <vector>

#include "brain_controller.h"
#include "program/clock_service.h"
#include "core/pedal_source_state.h"
#include "core/pedal_target_state.h"
#include "platform/platform_factory.h"
#include "platform/platform_service.h"
#include "program/program_context.h"
#include "program/program_state.h"
#include "program/program_service.h"
#include "program/tempo_program_state.h"

#include "mem_limits.h"

using namespace BPB::Brain;
using namespace BPB::Brain::Core;
using namespace BPB::Brain::Platform;
using namespace BPB::Brain::Program;
using namespace BPB::PlatformCore;

int main()
{
    PedalSourceState sourceStates[MAX_SOURCE_PEDAL_COUNT];
    PedalTargetState targetStates[MAX_TARGET_PEDAL_COUNT];

    PlatformService platformService = PlatformService(PlatformFactory::create);

    TargetProgramState targetProgramState;
    TempoProgramState tempoProgramState;

    BrainController controller(platformService, programService, programState, sourceStates, targetStates);

    controller.updateProgram();

    ClockService clockService;
    ClockState clockState(platformService.getNow(), 1000000);

    TempoState tempoState(clockState.lastTickTime, std::chrono::milliseconds(10));

    while (true)
    {
        std::vector<std::vector<int>> previousSourceStates = sourceStates;

        if (sourceStates.empty())
        {
            sourceStates = programService.createPedalSourceStates();
        }

        platformService.read(controller, sourceStates);

        std::vector<std::vector<int>> previousTargetStates = targetStates;

        if (targetStates.empty())
        {
            targetStates = programService.createPedalTargetStates();
        }

        clockService.updateClockState(clockState, platformService.getNow());


        programService.runProgram(clockState, tempoState, programState, previousSourceStates, sourceStates, targetStates, []() =>
        {

        });


        programService.updateProgramState(clockState, previousSourceStates, sourceStates, programState);

        programService.updatePedalTargetStates(clockState, programState, sourceStates, targetStates);

        platformService.writePedalTargetStates(previousTargetStates, targetStates);
    }
}