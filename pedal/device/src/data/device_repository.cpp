#include "device_repository.h"

#include <nlohmann/json.hpp>

#include <memory>
#include <istream>
#include <vector>

#include "models/devices_data.h"
#include "models/device_data.h"
#include "../source_device.h"
#include "../target_device.h"

using namespace BPB::Pedal::Device;
using namespace BPB::Pedal::Device::Data;
using namespace BPB::Pedal::Device::Data::Models;
using namespace nlohmann;

Devices DeviceRepository::getDevices()
{
    std::shared_ptr<std::istream> dataStream = dataStore.read("bpb-devices.json");

    DevicesData data = json::parse(*dataStream);

    std::vector<std::shared_ptr<SourceDevice>> sourceDevices;
    std::vector<std::shared_ptr<TargetDevice>> targetDevices;

    while (!data.sourceDevices.empty())
    {
        DeviceData& device = data.sourceDevices.front();

        sourceDevices.push_back(sourceDeviceFactory.create(device.type, device.config));

        data.sourceDevices.pop_front();
    }

    while (!data.targetDevices.empty())
    {
        DeviceData& device = data.targetDevices.front();

        targetDevices.push_back(targetDeviceFactory.create(device.type, device.config));

        data.targetDevices.pop_front();
    }

    return Devices(sourceDevices, targetDevices);
}

void DeviceRepository::savePedalJson(std::string& devicesJson)
{
    dataStore.write("bpb-pedal.json", devicesJson);
}