#include "digital_switch.h"

using namespace BPB::Pedal::Device::TargetDevices;

void DigitalSwitch::setPins(int state, std::vector<int>& targetPins)
{
    targetPins[targetPin] = state;
}