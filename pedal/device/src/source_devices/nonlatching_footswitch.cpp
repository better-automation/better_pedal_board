#include "nonlatching_footswitch.h"

using namespace BPB::Pedal::Device::SourceDevices;

int NonlatchingFootswitch::getState(std::vector<int>& pins)
{
    return pins[sourcePin];
}