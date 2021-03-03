#ifndef BPB_BRAIN_PLATFORM_PLATFORMS_SIMULATOR_SIMULATOR_PLATFORM_H
#define BPB_BRAIN_PLATFORM_PLATFORMS_SIMULATOR_SIMULATOR_PLATFORM_H

#include <chrono>
#include <deque>
#include <future>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

#include "../../../../../platform_core/include/platform.h"

using namespace BPB::Brain::Platform;
using namespace BPB::PlatformCore;

namespace BPB::Brain::Platform::Platforms::Simulator
{
    class SimulatorPlatform : public Platform
    {
        private:
            inline static std::string PROGRAM_DATA_FILE_LOCATION = "../../dev-data/bpb-program.json";

            inline static std::deque<std::string> inputBuffer;
            inline static std::mutex inputBufferMutex;
            inline static bool isRunningUpdateProgramCommand = false;

            static void listenForInput();
            inline static std::future<void> listenForInputFuture = std::async(std::launch::async, listenForInput);

            std::chrono::milliseconds readTimeLimit;

            void updateResult(std::string& input, std::vector<std::vector<int>>& result);

        public:
            SimulatorPlatform(std::chrono::milliseconds readTimeLimit) : readTimeLimit(readTimeLimit) { }

            std::chrono::milliseconds getNow();
            std::shared_ptr<std::istream> getProgramData();
            void read(Controller& controller, std::vector<std::vector<int>>& result);
            void write(std::vector<std::vector<int>>& previousStates, std::vector<std::vector<int>>& states);
    };
}

#endif