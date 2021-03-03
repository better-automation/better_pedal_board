#ifndef BPB_PLATFORM_CORE_PLATFORM_H
#define BPB_PLATFORM_CORE_PLATFORM_H

#include <chrono>
#include <istream>
#include <memory>
#include <string>
#include <vector>

#include "controller.h"

namespace BPB::PlatformCore
{
    class Platform
    {
        public:
            virtual ~Platform() { }

            virtual std::chrono::milliseconds getNow() = 0;
            virtual std::shared_ptr<std::istream> getProgramData() = 0;
            virtual void read(Controller& controller, std::vector<std::vector<int>>& result) = 0;
            virtual void write(std::vector<std::vector<int>>& previousStates, std::vector<std::vector<int>>& states) = 0;
    };
}

#endif