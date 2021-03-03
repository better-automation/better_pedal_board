#include "../../include/data/data_store.h"

#include <fstream>

using namespace BPB::Shared::Data;

std::shared_ptr<std::istream> DataStore::read(std::string filename)
{
    return std::make_shared<std::ifstream>(fileLocation + filename);
}

void DataStore::write(std::string filename, std::string& data)
{
    std::ofstream fileStream(fileLocation + filename, std::fstream::out);

    fileStream << data;
}