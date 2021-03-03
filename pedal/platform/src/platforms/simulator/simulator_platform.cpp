#include "simulator_platform.h"

#include <deque>
#include <iostream>
#include <sstream>

#include "../../../include/command.h"

using namespace BPB::Pedal::Platform::Platforms::Simulator;
using namespace BPB::Shared::Platform;

void SimulatorPlatform::updateResult(std::string& input, std::vector<int>& result)
{
    if (result.empty())
    {
        return;
    }
    
    std::istringstream stream(input);
    std::string field;

    std::getline(stream, field, ' ');
    int index = stoi(field);

    std::getline(stream, field);
    int state = stoi(field);

    result[index] = state;
}

int SimulatorPlatform::getSourcePinCount()
{
    return sourcePinCount;
}

int SimulatorPlatform::getTargetPinCount()
{
    return targetPinCount;
}

void SimulatorPlatform::initialize(std::vector<int>& sourceState)
{
    std::deque<std::string> inputQueue;

    while (true)
    {
        while (inputQueue.empty())
        {
            reader.read(inputQueue);
        }

        std::string& input = inputQueue.front();

        if (input == Command::END)
        {
            return;
        }

        updateResult(input, sourceState);

        inputQueue.pop_front();
    }
}

void SimulatorPlatform::readPins(std::vector<int>& result, CommandBus& commandBus)
{
    std::deque<std::string> inputQueue;

    reader.read(inputQueue);

    while (!inputQueue.empty())
    {
        std::string& input = inputQueue.front();

        if (reader.isCommand(input))
        {
            if (input != Command::END)
            {
                commandBus.setCommand(input);
            }

            break;
        }

        if (!result.empty())
        {
            updateResult(input, result);
        }

        inputQueue.pop_front();
    }
}

void SimulatorPlatform::writePins(std::vector<int>& previousState, std::vector<int>& state)
{
    bool hasStateSizeChanged = previousState.size() != state.size();

    for (int i = 0; i < state.size(); i++)
    {
        if (!hasStateSizeChanged && state[i] == previousState[i])
        {
            continue;
        }

        std::cout << i << ' ' << state[i] << std::endl;
    }
}