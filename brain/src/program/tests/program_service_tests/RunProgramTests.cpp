#include "../../program_service.h"

#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../action_runner.h"
#include "../../destination.h"
#include "../../device.h"
#include "../../../core/pedal_context.h"
#include "../../../core/pedal_source_state.h"
#include "../../../core/pedal_target_state.h"
#include "../../program_context.h"
#include "../../program.h"
#include "../../state_change.h"
#include "../../target_actions/set_state_action.h"
#include "../../trigger_context.h"
#include "../../target_program_runner.h"
#include "../../target_program_state.h"
#include "../../target_program_context.h"

#include "mock_action.h"

using namespace BPB::Brain::Core;
using namespace BPB::Brain::Program;
using namespace BPB::Brain::Program::TargetActions;
using ::testing::ReturnRef;
using ::testing::Return;
using ::testing::_;

namespace BPB::Brain::Program::Tests::ProgramServiceTests
{
    // struct TargetProgramState : public ProgramState<int>
    // {
    //     std::vector<std::vector<LayerState<int>*>> targetLayers;
    
    //     TargetProgramState(
    //         std::vector<std::vector<LayerState<int>*>> targetLayers,
    //         std::vector<LayerState<int>> triggerLayers,
    //         std::vector<std::vector<PhraseState>> triggerPhrases
    //     ) :
    //         ProgramState(triggerLayers, triggerPhrases),
    //         targetLayers(targetLayers)
    //     { }
    // };

    // struct TargetTriggerContext : public TriggerContext<TargetAction>
    // {
    //     Device target;

    //     TargetTriggerContext(
    //         Device source,
    //         bool isUnconditional,
    //         int deviceSourceStateCondition,
    //         std::vector<PhraseContext<TargetAction>> phrases,
    //         Device target
    //     ) :
    //         TriggerContext(source, isUnconditional, deviceSourceStateCondition, phrases),
    //         target(target)
    //     { }
    // };

    // struct TargetProgramContext : public ProgramContext<TargetAction>
    // {   
    //     private:
    //         static std::vector<TriggerContext<TargetAction>> createTriggers(std::vector<TargetTriggerContext>& mockTriggers)
    //         {
    //             std::vector<TriggerContext<TargetAction>> triggers;

    //             for (TargetTriggerContext& trigger : mockTriggers)
    //                 triggers.push_back(trigger);

    //             return triggers;
    //         }

    //     public:
    //         std::vector<TargetTriggerContext> mockTriggers;

    //         TargetProgramContext(
    //             std::vector<PedalContext>& pedals,
    //             std::vector<TargetTriggerContext> triggers
    //         ) :
    //             ProgramContext(pedals, createTriggers(triggers)),
    //             mockTriggers(triggers)
    //         { }
    // };

    // class TargetActionRunner : public ActionRunner<TargetAction, int>
    // {
    //     private:
    //         TargetProgramContext& context;
    //         TargetProgramState& state;

    //     public:
    //         TargetActionRunner(
    //             TargetProgramContext& context,
    //             TargetProgramState& state
    //         ) : 
    //             context(context),
    //             state(state)
    //         { }

    //         MOCK_METHOD(LayerState<int>*&, getLayerState, (int), (override));
    //         MOCK_METHOD(StateChange<int>, getStateChange, (TargetAction&, int), (override));

    //         int getDefaultState() override
    //         {
    //             return 0;
    //         }
    // };

    // class TargetProgram : public Program
    // {
    //     private:
    //         ClockState& clock;
    //         TargetProgramContext& context;
    //         TargetProgramState& state;
        
    //     public:
    //         TargetProgram(
    //             ClockState& clock,
    //             TargetProgramContext& context,
    //             TargetProgramState& state
    //         ) :
    //             clock(clock),
    //             context(context),
    //             state(state)
    //         { }

    //         void runProgram(PedalSourceState sources[], PedalTargetState targets[]) override
    //         {
    //             ProgramService<TargetAction, int> programService(context);

    //             for (int triggerIndex = 0; triggerIndex < context.triggers.size(); triggerIndex++)
    //             {
    //                 Device& target = context.targetTriggers[triggerIndex].target;
    //                 LayerState<TState>*& destinationLayer = state.targetLayers[target.pedalIndex][target.deviceIndex];

    //                 programService.runTrigger(clock, triggerIndex, sources, state, destinationLayer);
    //             }
                
    //             TargetActionRunner actionRunner(context, state);

    //             for (int targetPedalIndex = 0; targetPedalIndex < context.pedals.size(); targetPedalIndex++)
    //             for (int targetDeviceIndex = 0; targetDeviceIndex < context.pedals[targetPedalIndex].targetDeviceCount; targetDeviceIndex++)
    //             {
    //                 Destination<int> destination(&state.targetLayers[targetPedalIndex][targetDeviceIndex], &targets[targetPedalIndex].next[targetDeviceIndex]);

    //                 programService.updateDestination(actionRunner, clock, sources, state, destination);
    //             }
    //         }
    // };


    struct RunProgramTests : testing::Test
    {
        PedalSourceState sources[MAX_SOURCE_PEDAL_COUNT];
        PedalTargetState targets[MAX_TARGET_PEDAL_COUNT];

        ClockState clock = ClockState(std::chrono::milliseconds(0));
        int deviceCountPerPedal = 4;
        int pedalCount = 2;

        std::vector<PedalContext> pedals;
        std::vector<TargetTriggerContext> triggers;
        std::vector<std::vector<LayerState<int>*>> targetLayers;
        std::vector<LayerState<int>> triggerLayers;
        std::vector<std::vector<PhraseState>> triggerPhrases;

        RunProgramTests()
        {
            for (int i = 0; i < pedalCount; i++)
            {
                pedals.push_back(PedalContext(deviceCountPerPedal, deviceCountPerPedal));

                triggers.push_back(TargetTriggerContext(Device(i, 0), false, 1, std::vector<PhraseContext<TargetAction>>(1, PhraseContext<TargetAction>(0, 0, { EventContext(std::make_shared<SetStateAction>(1), 0) })), Device(i, 0))); // switch on
                triggers.push_back(TargetTriggerContext(Device(i, 0), false, 0, std::vector<PhraseContext<TargetAction>>(1, PhraseContext<TargetAction>(0, 0, { EventContext(std::make_shared<SetStateAction>(1), 0) })), Device(i, 0))); // switch off
                triggers.push_back(TargetTriggerContext(Device(i, 1), true, 0, std::vector<PhraseContext<TargetAction>>(1, PhraseContext<TargetAction>(0, 0, { EventContext(std::make_shared<SetStateAction>(1), 0) })), Device(i, 1))); // volume
                triggers.push_back(TargetTriggerContext(Device(i, 2), true, 0, std::vector<PhraseContext<TargetAction>>(1, PhraseContext<TargetAction>(0, 0, { EventContext(std::make_shared<SetStateAction>(1), 0) })), Device(i, 2))); // drive
                triggers.push_back(TargetTriggerContext(Device(i, 3), true, 0, std::vector<PhraseContext<TargetAction>>(1, PhraseContext<TargetAction>(0, 0, { EventContext(std::make_shared<SetStateAction>(1), 0) })), Device(i, 3))); // tone

                triggerLayers.push_back(LayerState<int>(triggerLayers.size()));
                triggerLayers.push_back(LayerState<int>(triggerLayers.size()));
                triggerLayers.push_back(LayerState<int>(triggerLayers.size()));
                triggerLayers.push_back(LayerState<int>(triggerLayers.size()));
                triggerLayers.push_back(LayerState<int>(triggerLayers.size()));

                triggerPhrases.push_back(std::vector<PhraseState>(1));
                triggerPhrases.push_back(std::vector<PhraseState>(1));
                triggerPhrases.push_back(std::vector<PhraseState>(1));
                triggerPhrases.push_back(std::vector<PhraseState>(1));
                triggerPhrases.push_back(std::vector<PhraseState>(1));

                targetLayers.push_back(std::vector<LayerState<int>*>(deviceCountPerPedal));

                for (int ii = 0; ii < deviceCountPerPedal; ii++)
                {
                    sources[i].previous[ii] = 0;
                    sources[i].current[ii] = 0;

                    targets[i].current[ii] = 0;
                    targets[i].next[ii] = 0;
                }
            }
        }

        virtual ~RunProgramTests()
        {

        }
    };

    // TEST_F(RunProgramTests, SetsAllTargetStatesWhenNoPreviousSourceState) 
    // {
    //     TargetProgramContext context(pedals, triggers);
    //     TargetProgramState state = TargetProgramState(targetLayers, triggerLayers, triggerPhrases);

    //     TargetActionRunner actionRunner(context, state, targets);
        
    //     for (int i = 0; i < context.triggers.size(); i++)
    //     {
    //         Device& target = context.triggers[i].target;

    //         if (i % 5 == 0)
    //         {
    //             EXPECT_CALL(actionRunner, getLayerState(i))
    //                 .Times(0);

    //             EXPECT_CALL(actionRunner, getStateChange(*context.triggers[i].phrases[0].events[0].action, _))
    //                 .Times(0);

    //             continue;
    //         }
                
    //         EXPECT_CALL(actionRunner, getLayerState(i))
    //             .Times(1)
    //             .WillOnce(ReturnRef(state.targetLayers[target.pedalIndex][target.deviceIndex]));

    //         EXPECT_CALL(actionRunner, getStateChange(*context.triggers[i].phrases[0].events[0].action, 0))
    //             .Times(1)
    //             .WillOnce(Return(StateChange(1)));   
    //     }

    //     std::vector<Destination<int>> destinations = actionRunner.createDestinations();

    //     ProgramService<TargetAction, int>(context).runProgram(actionRunner, clock, sources, destinations, state);

    //     for (int i = 0; i < context.triggers.size(); i++)
    //     {
    //         if (i % 5 == 0)
    //         {
    //             EXPECT_EQ(0, state.triggerPhrases[i][0].nextEventIndex);
    //             EXPECT_EQ(0, state.triggerPhrases[i][0].nextEventScheduledTime);
    //             EXPECT_EQ(0, state.triggerPhrases[i][0].scheduledStartTime);

    //             continue;
    //         }

    //         EXPECT_EQ(1, state.triggerPhrases[i][0].nextEventIndex);
    //         EXPECT_EQ(0, state.triggerPhrases[i][0].nextEventScheduledTime);
    //         EXPECT_EQ(0, state.triggerPhrases[i][0].scheduledStartTime);
    //     }

    //     for (int i = 0; i < pedalCount; i++)
    //     {
    //         for (int ii = 0; ii < deviceCountPerPedal; ii++)
    //         {
    //             EXPECT_EQ(0, targets[i].current[ii]);
    //             EXPECT_EQ(1, targets[i].next[ii]);
    //         }
    //     }
    // }

    TEST_F(RunProgramTests, DoesNothingWhenSourceStateDoesNotChangeAndThereAreNoPhrasesToRun) {
        for (int i = 0; i < pedalCount; i++)
        {
            sources[i].arePreviousStatesAvailable = true;
        }

        for (int i = 0; i < triggers.size(); i++)
        {
            triggerPhrases[i][0].nextEventIndex = 1;
        }

        TargetProgramContext context(pedals, triggers);
        TargetProgramState state(targetLayers, triggerLayers, triggerPhrases);

        TargetProgram program(clock, context, state);

        program.runProgram(sources, targets);

        // for (int i = 0; i < context.triggers.size(); i++)
        // {
        //     EXPECT_CALL(actionRunner, getLayerState(i))
        //         .Times(0);

        //     EXPECT_CALL(actionRunner, getStateChange(*context.triggers[i].phrases[0].events[0].action, _))
        //         .Times(0);
        // }


        for (int i = 0; i < context.triggers.size(); i++)
        {
            EXPECT_EQ(1, state.triggerPhrases[i][0].nextEventIndex);
            EXPECT_EQ(0, state.triggerPhrases[i][0].nextEventScheduledTime);
            EXPECT_EQ(0, state.triggerPhrases[i][0].scheduledStartTime);
        }

        for (int i = 0; i < pedalCount; i++)
        {   
            for (int ii = 0; ii < deviceCountPerPedal; ii++)
            {
                EXPECT_EQ(0, targets[i].next[ii]);
            }
        }
    }

    // TEST_F(RunProgramTests, RunsOnlyScheduledEventsWhenSourceStateDoesNotChange) {
    //     for (int i = 0; i < pedalCount; i++)
    //     {
    //         sources[i].arePreviousStatesAvailable = true;
    //     }

    //     for (int i = 0; i < triggers.size(); i++)
    //     {
    //         triggerPhrases[i][0].nextEventScheduledTime = i % 10;
    //         triggerPhrases[i][0].scheduledStartTime = i % 10;
    //     }

    //     clock.totalTicksElapsedCount = 3;

    //     TargetProgramContext context(pedals, triggers);
    //     TargetProgramState state = TargetProgramState(targetLayers, triggerLayers, triggerPhrases);

    //     TargetActionRunner actionRunner(context, state, targets);
        
    //     for (int i = 0; i < context.triggers.size(); i++)
    //     {
    //         EXPECT_CALL(actionRunner, getLayerState(i))
    //             .Times(0);

    //         if (i == 0 || i % 10 > 3)
    //         {
    //             EXPECT_CALL(actionRunner, getStateChange(*context.triggers[i].phrases[0].events[0].action, _))
    //                 .Times(0);

    //             continue;
    //         }

    //         EXPECT_CALL(actionRunner, getStateChange(*context.triggers[i].phrases[0].events[0].action, 0))
    //             .Times(1)
    //             .WillOnce(Return(StateChange(1)));   
    //     }

    //     std::vector<Destination<int>> destinations = actionRunner.createDestinations();

    //     for (int i = 0; i < destinations.size(); i++)
    //     {
    //         destination.layer.
    //     }

    //     ProgramService<TargetAction, int>(context).runProgram(actionRunner, clock, sources, destinations, state);

    //     for (Destination<int>& destination : destinations)
    //         std::cout << "destination state: " << *destination.state << std::endl;

    //     for (int i = 0; i < context.triggers.size(); i++)
    //     {
    //         Device& target = context.triggers[i].target;

    //         if (i % 10 > 3)
    //         {
    //             EXPECT_EQ(0, state.triggerPhrases[i][0].nextEventIndex);
    //             EXPECT_EQ(0, state.triggerPhrases[i][0].nextEventScheduledTime);
    //             EXPECT_EQ(0, state.triggerPhrases[i][0].scheduledStartTime);

    //             EXPECT_EQ(0, targets[target.pedalIndex].next[target.deviceIndex]);

    //             continue;
    //         }

    //         EXPECT_EQ(0, state.triggerPhrases[i][0].nextEventIndex);
    //         EXPECT_EQ(i % 10, state.triggerPhrases[i][0].nextEventScheduledTime);
    //         EXPECT_EQ(i % 10, state.triggerPhrases[i][0].scheduledStartTime);

    //         EXPECT_EQ(1, targets[target.pedalIndex].next[target.deviceIndex]);
    //     }
    // }
}