#ifndef BPB_SHARED_PLATFORM_SIMULATOR_SIMULATOR_SERIAL_READER_H
#define BPB_SHARED_PLATFORM_SIMULATOR_SIMULATOR_SERIAL_READER_H

#include <deque>
#include <future>
#include <string>
#include <vector>

namespace BPB::Shared::Platform::Simulator
{
    class SimulatorSerialReader
    {
        private:
            static void listenForInput();

            inline static std::deque<std::string> inputBuffer;
            inline static std::mutex inputBufferMutex;
            inline static std::future<void> listenForInputFuture;
            inline static bool pause;
            
        public:
            bool isCommand(std::string& input);
            void read(std::deque<std::string>& inputQueue);
    };
}

#endif