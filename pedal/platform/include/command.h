#ifndef BPB_PEDAL_PLATFORM_COMMAND_H
#define BPB_PEDAL_PLATFORM_COMMAND_H

#include <string>

namespace BPB::Pedal::Platform
{
    struct Command
    {
        inline static std::string END = "#END";
        inline static std::string INITIALIZE_PLATFORM = "#INITIALIZE_PLATFORM";
        inline static std::string UPDATE_TARGET_STATE = "#UPDATE_TARGET_STATE";
    };
}

#endif