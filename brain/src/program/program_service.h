#ifndef BPB_BRAIN_PROGRAM_PROGRAM_SERVICE_H
#define BPB_BRAIN_PROGRAM_PROGRAM_SERVICE_H

#include <chrono>
#include <functional>
#include <istream>
#include <memory>
#include <map>
#include <string>
#include <vector>

#include "action_runner.h"
#include "clock_state.h"
#include "destination.h"
#include "layer_state_list.h"
#include "layer_state_node.h"
#include "../core/pedal_source_state.h"
#include "../core/pedal_target_state.h"
#include "phrase_context.h"
#include "phrase_state.h"
#include "program_context.h"
#include "program_state.h"
#include "target_program_state.h"
#include "tempo_program_state.h"
#include "trigger_context.h"
#include "tempo_program_state.h"
#include "tempo_state.h"

using namespace BPB::Brain::Core;

namespace BPB::Brain::Program
{
    template <class TAction, class TState>
    class ProgramService
    {
        private:
            ActionRunner<TAction, TState>& actionRunner;
            ClockState& clock;
            ProgramContext<TAction>& context;
            PedalSourceState sources[];
            ProgramState<TState>& state;

            PhraseState repeatPhrase(PhraseContext<TAction> phrase, PhraseState phraseState);
            PhraseState startPhrase(PhraseContext<TAction> phrase);
            StateChange<TState> runScheduledEvents(PhraseContext<TAction> phrase, int sourceState, PhraseState& phraseState);
            
        public:
            ProgramService(
                ProgramContext<TAction>& context,
                ClockState& clock,
                PedalSourceState sources[],
                ActionRunner<TAction, TState>& actionRunner,
                ProgramState<TState>& state
            ) : 
                context(context),
                clock(clock),
                sources(sources),
                actionRunner(actionRunner),
                state(state)
            { }

            TState runScheduledEvents(LayerStateList<TState>& destination);
            LayerStateList<TState> runTrigger(const TriggerContext<TAction>& trigger, const LayerStateList<TState>& layers, const LayerStateList<TState>& destination);
    };
}

#endif