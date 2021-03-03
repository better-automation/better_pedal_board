#include "../../../include/platform/simulator/simulator_serial_reader.h"

#include <iostream>
#include <sstream>

using namespace BPB::Shared::Platform::Simulator;

bool SimulatorSerialReader::isCommand(std::string& data)
{
    return !data.empty() && data[0] == '#';
}

void SimulatorSerialReader::listenForInput()
{
    std::string input;

    while (pause = false)
    {
        std::getline(std::cin, input);

        std::lock_guard<std::mutex> lock(inputBufferMutex);

        inputBuffer.push_back(input);
    }
}

void SimulatorSerialReader::read(std::deque<std::string>& inputQueue)
{
    pause = false;

    std::async(std::launch::async, listenForInput);

    std::this_thread::sleep_for(std::chrono::milliseconds(5));

    pause = true;

    std::lock_guard<std::mutex> lock(inputBufferMutex);

    std::string input;

    while (!inputBuffer.empty())
    {
        input = inputBuffer.front();

        inputQueue.push_back(input);
        
        inputBuffer.pop_front();
    }
}