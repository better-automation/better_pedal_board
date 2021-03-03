#ifndef BPB_PEDAL_DEVICE_DEVICE_REPOSITORY_H
#define BPB_PEDAL_DEVICE_DEVICE_REPOSITORY_H

#include "../../../../shared/include/data/data_store.h"
#include "../devices.h"
#include "../source_device_factory.h"
#include "../target_device_factory.h"

using namespace BPB::Pedal::Device;
using namespace BPB::Shared::Data;

namespace BPB::Pedal::Device::Data
{
    class DeviceRepository
    {
        private:
            DataStore& dataStore;
            SourceDeviceFactory sourceDeviceFactory;
            TargetDeviceFactory targetDeviceFactory;

        public:
            DeviceRepository(
                DataStore& dataStore,
                SourceDeviceFactory sourceDeviceFactory, 
                TargetDeviceFactory targetDeviceFactory
            ) : 
                dataStore(dataStore),
                sourceDeviceFactory(sourceDeviceFactory), 
                targetDeviceFactory(targetDeviceFactory)
            { }
                          
            Devices getDevices();
            void savePedalJson(std::string& devicesJson);
    };
}

#endif