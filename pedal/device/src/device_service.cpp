#include "../include/device_service.h"

#include "data/device_repository.h"
#include "source_device_factory.h"
#include "target_device_factory.h"

using namespace BPB::Pedal::Device;
using namespace BPB::Pedal::Device::Data;

void DeviceService::loadDevices()
{
    DeviceRepository repository(dataStore, SourceDeviceFactory(), TargetDeviceFactory());

    devices = repository.getDevices();
}

void DeviceService::updateSourceDeviceState(std::vector<int> sourcePlatformState, std::vector<int> result)
{
    if (sourcePlatformState.empty() || result.empty())
    {
        return;
    }

    for (int i = 0; i < sourceDevices.size(); i++)
    {
        result[i] = sourceDevices[i]->getState(sourcePlatformState);
    }
}

void DeviceService::updatePlatformTargetState(std::vector<int>& previousTargetDeviceState, std::vector<int>& targetDeviceState, std::vector<int>& result)
{
    if (targetDeviceState.empty() || result.empty())
    {
        return;
    }

    bool hasPedalSizeChanged = previousTargetDeviceState.size() != targetDeviceState.size();

    for (int i = 0; i < targetDevices.size(); i++)
    {
        if (!hasPedalSizeChanged && previousTargetDeviceState[i] == targetDeviceState[i])
        {
            continue;
        }

        targetDevices[i]->setPins(targetDeviceState[i], result);
    }
}