#ifndef BPB_PLATFORM_CORE_DATA_STORE_H
#define BPB_PLATFORM_CORE_DATA_STORE_H

#include <istream>
#include <string>

namespace BPB::PlatformCore
{
    class DataStore
    {
        public:
            virtual std::istream getProgramData();
    };
}

#endif