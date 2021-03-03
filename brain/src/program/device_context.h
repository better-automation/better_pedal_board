#ifndef BPB_BRAIN_PROGRAM_DEVICE_CONTEXT_H
#define BPB_BRAIN_PROGRAM_DEVICE_CONTEXT_H

namespace BPB::Brain::Program
{
    struct DeviceContext
    {
        DeviceContext(
            int pedalIndex,
            int deviceIndex
        ):
            pedalIndex(pedalIndex),
            deviceIndex(deviceIndex)
        { }

        int getDeviceIndex()
        {
            return deviceIndex;
        }

        int getPedalIndex()
        {
            return pedalIndex;
        }

        private:
            int deviceIndex;
            int pedalIndex;
    };
}

#endif