#ifndef BPB_BRAIN_PROGRAM_TARGET_PROGRAM_H
#define BPB_BRAIN_PROGRAM_TARGET_PROGRAM_H

#include "clock_state.h"
#include "../core/pedal_source_state.h"
#include "../core/pedal_target_state.h"
#include "program.h"
#include "program_service.h"
#include "target_action.h"
#include "target_program_context.h"
#include "target_program_state.h"

using namespace BPB::Brain::Core;

namespace BPB::Brain::Program
{
    class TargetProgram : public Program
    {
        private:
            TargetProgramContext& context;
            ProgramService<TargetAction, int>& programService;
            PedalTargetState targets[];
        
        public:
            TargetProgram(
                TargetProgramContext& context,
                ProgramService<TargetAction, int>& programService,
                PedalTargetState targets[]
            ) :
                context(context),
                programService(programService),
                targets(targets)
            { }

            void run();
    };
}

#endif