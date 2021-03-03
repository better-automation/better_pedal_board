#include "latching_footswitch.h"

using namespace BPB::Pedal::Device::SourceDevices;

int LatchingFootswitch::getState(std::vector<int>& pins)
{
    return pins[sourcePin];
}