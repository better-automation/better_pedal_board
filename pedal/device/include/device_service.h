#ifndef BPB_PEDAL_DEVICE_DEVICE_SERVICE_H
#define BPB_PEDAL_DEVICE_DEVICE_SERVICE_H

#include <memory>
#include <vector>

#include "../../../shared/include/data/data_store.h"
#include "../src/devices.h"
#include "../src/source_device.h"
#include "../src/target_device.h"

using namespace BPB::Shared::Data;

namespace BPB::Pedal::Device
{
    class DeviceService
    {
        private:
            DataStore& dataStore;
            Devices devices;
            std::vector<std::shared_ptr<SourceDevice>> sourceDevices;
            std::vector<std::shared_ptr<TargetDevice>> targetDevices;

        public:
            DeviceService(DataStore& dataStore) : dataStore(dataStore) { }

            void loadDevices();
            void updatePlatformTargetState(std::vector<int>& previousTargetDeviceState, std::vector<int>& targetDeviceState, std::vector<int>& result);
            void updateSourceDeviceState(std::vector<int> sourcePlatformState, std::vector<int> result);            
    };
}

#endif