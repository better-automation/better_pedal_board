#include "../target_device_factory.h"
#include "digital_switch.h"

using namespace BPB::Pedal::Device;
using namespace BPB::Pedal::Device::TargetDevices;

std::shared_ptr<TargetDevice> TargetDeviceFactory::create(std::string& type, std::map<std::string, std::string>& config)
{
    if (type == "Digital Switch")
    {
        return std::make_shared<DigitalSwitch>(stoi(config["targetPin"]));
    }

    return NULL;
}