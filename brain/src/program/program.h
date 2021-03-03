#ifndef BPB_BRAIN_PROGRAM_PROGRAM_H
#define BPB_BRAIN_PROGRAM_PROGRAM_H

#include "../core/pedal_source_state.h"
#include "../core/pedal_target_state.h"

using namespace BPB::Brain::Core;

namespace BPB::Brain::Program
{
    class Program
    {
        public:
            virtual void runProgram(PedalSourceState sources[], PedalTargetState targets[]) = 0;
    };
}

#endif