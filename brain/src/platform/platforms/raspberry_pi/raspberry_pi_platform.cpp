#include "raspberry_pi_platform.h"

#include <wiringPi.h>

#include "../../../include/command.h"

using namespace BPB::Brain::Platform;
using namespace BPB::Brain::Platform::Platforms::RaspberryPi;

std::chrono::milliseconds RaspberryPiPlatform::getNow()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
}

int RaspberryPiPlatform::getSourcePinCount()
{
    return sourcePinCount;
}

int RaspberryPiPlatform::getTargetPinCount()
{
    return targetPinCount;
}

void RaspberryPiPlatform::initialize(std::vector<int>& pedalSourceStates)
{
    wiringPiSetup();

    for (int i = 4; i < 8; i++)
    {
        pinMode(i, INPUT);
    }

    for (int i = 0; i < 4; i++)
    {
        pinMode(i, OUTPUT);
    }

    for (int i = 0; i < 4; i++)
    {
        digitalWrite(i, pedalSourceStates[i]);
    }
}

void RaspberryPiPlatform::read(std::vector<int>& result, CommandBus& commandBus)
{
    if (result.empty())
    {
        commandBus.setCommand(Command::INITIALIZE_PLATFORM);
        
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        result[i] = digitalRead(i + 4);
    }
}

std::string RaspberryPiPlatform::readInstructions()
{
    /* TODO */

    return "";
}

void RaspberryPiPlatform::write(std::vector<int>& previousState, std::vector<int>& state)
{
    bool hasPinSizeChanged = previousState.size() != state.size();

    for (int i = 0; i < 4; i++)
    {
        if (!hasPinSizeChanged && state[i] == previousState[i])
        {
            continue;
        }

        digitalWrite(i, state[i]);
    }
}