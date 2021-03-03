#ifndef BPB_BRAIN_PROGRAM_TESTS_PROGRAM_SERVICE_TESTS_MOCK_ACTION_H
#define BPB_BRAIN_PROGRAM_TESTS_PROGRAM_SERVICE_TESTS_MOCK_ACTION_H

#include "../../state_change.h"

using namespace BPB::Brain::Program;

namespace BPB::Brain::Program::Tests::ProgramServiceTests
{
    class MockAction
    { 
        public:
            int id;

            MockAction(int id) : id(id) { }

            friend bool operator== (const MockAction &a, const MockAction &b)
            {
                return (a.id == b.id);
            }
    };
}

#endif