#include "simulator_platform.h"

#include <deque>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace BPB::Brain::Platform;
using namespace BPB::Brain::Platform::Platforms::Simulator;

void SimulatorPlatform::listenForInput()
{
    std::string input;

    while (std::getline(std::cin, input))
    {
        std::lock_guard<std::mutex> lock(inputBufferMutex);

        inputBuffer.push_back(input);
    }
}

void SimulatorPlatform::updateResult(std::string& input, std::vector<std::vector<int>>& result)
{   
    std::istringstream stream(input);
    std::string field;
    
    std::getline(stream, field, ' ');
    int pedalIndex = stoi(field);

    std::getline(stream, field, ' ');
    int deviceIndex = stoi(field);

    std::getline(stream, field);
    int state = stoi(field);

    result[pedalIndex][deviceIndex] = state;
}

std::chrono::milliseconds SimulatorPlatform::getNow()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
}

std::shared_ptr<std::istream> SimulatorPlatform::getProgramData()
{
    return std::make_shared<std::ifstream>(std::ifstream(PROGRAM_DATA_FILE_LOCATION));
}

void SimulatorPlatform::read(Controller& controller, std::vector<std::vector<int>>& result)
{
    std::chrono::steady_clock::time_point readEndTime = std::chrono::steady_clock::now() + readTimeLimit;

    while (std::chrono::steady_clock::now() < readEndTime)
    { 
        if (inputBuffer.empty())
        {
            continue;
        }

        if (isRunningUpdateProgramCommand)
        {
            std::ofstream fileStream(PROGRAM_DATA_FILE_LOCATION, std::ofstream::app);

            while (std::chrono::steady_clock::now() < readEndTime)
            {
                if (inputBuffer.empty())
                {
                    continue;
                }

                std::string input = inputBuffer.front();

                if (input == "#END")
                {
                    isRunningUpdateProgramCommand = false;

                    fileStream.close();

                    controller.updateProgram();
            
                    std::lock_guard<std::mutex> lock(inputBufferMutex);

                    inputBuffer.pop_front();

                    break;
                }

                fileStream << input;
            
                std::lock_guard<std::mutex> lock(inputBufferMutex);

                inputBuffer.pop_front();
            }

            continue;
        }

        std::string input = inputBuffer.front();

        if (input == "#UPDATE_PROGRAM")
        {
            isRunningUpdateProgramCommand = true;

            std::ofstream fileStream(PROGRAM_DATA_FILE_LOCATION);

            std::lock_guard<std::mutex> lock(inputBufferMutex);

            inputBuffer.pop_front();

            continue;
        }

        if (!result.empty())
        {
            updateResult(input, result);
        }
    
        std::lock_guard<std::mutex> lock(inputBufferMutex);

        inputBuffer.pop_front();
    }
}

void SimulatorPlatform::write(std::vector<std::vector<int>>& previousStates, std::vector<std::vector<int>>& states)
{
    for (int pedalIndex = 0; pedalIndex < states.size(); pedalIndex++)
    {
        for (int deviceIndex = 0; deviceIndex < states[pedalIndex].size(); deviceIndex++)
        {
            int state = states[pedalIndex][deviceIndex];

            if (!previousStates.empty() && state == previousStates[pedalIndex][deviceIndex])
            {
                continue;
            }
        }
    }
}