#include "Battery.h"

Battery::Battery() : Batterypower(100)
{
}

void Battery::charge(int val)
{
    this->Batterypower += val;
    if(this->Batterypower > 100)
        this->Batterypower = 100;
}

void Battery::discharge(int val)
{
    this->Batterypower -= val;
    if(this->Batterypower < 0)
        this->Batterypower = 0;
}

int Battery::getPower() const
{
    return this->Batterypower;
}
