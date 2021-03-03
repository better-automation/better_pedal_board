#include "../source_device_factory.h"
#include "latching_footswitch.h"
#include "nonlatching_footswitch.h"

using namespace BPB::Pedal::Device;
using namespace BPB::Pedal::Device::SourceDevices;

std::shared_ptr<SourceDevice> SourceDeviceFactory::create(std::string& type, std::map<std::string, std::string>& config)
{
    if (type == "Latching Footswitch")
    {
        return std::make_shared<LatchingFootswitch>(stoi(config["sourcePin"]));
    }

    if (type == "Nonlatching Footswitch")
    {
        return std::make_shared<NonlatchingFootswitch>(stoi(config["sourcePin"]));
    }

    return NULL;
}