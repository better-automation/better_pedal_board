#include "../../include/platform/command_bus.h"

using namespace BPB::Shared::Platform;

void CommandBus::clearCommand()
{
    queue.clear();
}

std::string& CommandBus::getCommand()
{
    return queue;
}

void CommandBus::setCommand(std::string command)
{
    queue = command;
}