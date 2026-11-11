#include "Motor.h"
#include <iostream>

Motor::Motor(std::string name) : motorName(name), rpm(0)
{
}

void Motor::setRPM(int r)
{
    rpm = r;
}

int Motor::getRPM() const
{
    return rpm;
}

void Motor::stop()
{
    rpm = 0;
}

void Motor::printStatus() const
{
    std::cout << motorName << " 当前转速：" << rpm << " RPM" << std::endl;
}
