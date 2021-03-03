#ifndef BPB_SHARED_DATA_DATA_STORE_H
#define BPB_SHARED_DATA_DATA_STORE_H

#include <istream>
#include <memory>
#include <string>

namespace BPB::Shared::Data
{
    class DataStore
    {
        private:
            std::string fileLocation;

        public:
            DataStore(std::string fileLocation) : fileLocation(fileLocation) { }

            std::shared_ptr<std::istream> read(std::string filename);
            void write(std::string filename, std::string& data);
    };
}

#endif