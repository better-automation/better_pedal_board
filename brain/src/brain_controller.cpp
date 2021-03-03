#include "brain_controller.h"

#include "program/data/program_repository.h"

using namespace BPB::Brain;
using namespace BPB::Brain::Program;
using namespace BPB::Brain::Program::Data;

void BrainController::updateProgram()
{
    std::shared_ptr<std::istream> programData = platformService.getProgramData();

    ProgramRepository repository = ProgramRepository(TargetActionFactory());

    programService = repository.getProgram(*programData);

    programState = programService.createProgramState();

    sourceStates = std::vector<std::vector<int>>();
    targetStates = std::vector<std::vector<int>>();
}