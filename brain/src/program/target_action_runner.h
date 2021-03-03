#ifndef BPB_BRAIN_PROGRAM_TARGET_ACTION_RUNNER_H
#define BPB_BRAIN_PROGRAM_TARGET_ACTION_RUNNER_H

#include "action_runner.h"

#include <functional>
#include <vector>

#include "layer_state.h"
#include "../core/pedal_target_state.h"
#include "program_context.h"
#include "state_change.h"
#include "target_action.h"
#include "target_program_context.h"
#include "target_program_state.h"
#include "trigger_context.h"

namespace BPB::Brain::Program
{
    class TargetActionRunner : public ActionRunner<TargetAction, int>
    {
        private:
            TargetProgramContext& context;

        public:
            TargetActionRunner(
                TargetProgramContext& context
            ) :
                context(context)
            { }

            int getDefaultState();
            StateChange<int> getStateChange(TargetAction& action, int sourceState);
    };
}

#endif