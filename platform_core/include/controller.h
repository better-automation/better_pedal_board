#ifndef BPB_PLATFORM_CORE_CONTROLLER_H
#define BPB_PLATFORM_CORE_CONTROLLER_H

namespace BPB::PlatformCore
{
    class Controller
    {
        public:
            virtual void updateProgram() = 0;
    };
}

#endif