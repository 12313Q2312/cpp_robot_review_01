#include "Robot.h"
#include <iostream>

Robot::Robot(std::string robotName)
    : name(robotName),
      x(0),
      y(0),
      dir(North),
      speed(0),
      leftMotor("左电机"),
      rightMotor("右电机")
{
    // 初始坐标加入轨迹
    track.push_back({x, y});
}

void Robot::setSpeed(double sp)
{
    speed = sp;
    leftMotor.setRPM(static_cast<int>(speed * 10));
    rightMotor.setRPM(static_cast<int>(speed * 10));
}

void Robot::moveForward()
{
    if (battery.getPower() <= 0)
    {
        std::cout << "电量不足，无法前进\n";
        return;
    }
    battery.discharge(1);
    switch (dir)
    {
    case North: y += speed; break;
    case South: y -= speed; break;
    case East:  x += speed; break;
    case West:  x -= speed; break;
    }
    track.push_back({x, y});
}

void Robot::moveBackward()
{
    if (battery.getPower() <= 0)
    {
        std::cout << "电量不足，无法后退\n";
        return;
    }
    battery.discharge(1);
    switch (dir)
    {
    case North: y -= speed; break;
    case South: y += speed; break;
    case East:  x -= speed; break;
    case West:  x += speed; break;
    }
    track.push_back({x, y});
}

void Robot::turnLeft()
{
    battery.discharge(1);
    switch (dir)
    {
    case North: dir = West; break;
    case West:  dir = South; break;
    case South: dir = East; break;
    case East:  dir = North; break;
    }
}

void Robot::turnRight()
{
    battery.discharge(1);
    switch (dir)
    {
    case North: dir = East; break;
    case East:  dir = South; break;
    case South: dir = West; break;
    case West:  dir = North; break;
    }
}

void Robot::printRobotStatus() const
{
    std::string dirStr[] = {"北", "南", "东", "西"};
    std::cout << "========机器人状态========" << std::endl;
    std::cout << "名称：" << name << std::endl;
    std::cout << "坐标：X=" << x << " Y=" << y << std::endl;
    std::cout << "朝向：" << dirStr[dir] << std::endl;
    std::cout << "当前速度：" << speed << std::endl;
    std::cout << "剩余电量：" << battery.getPower() << "%" << std::endl;
    leftMotor.printStatus();
    rightMotor.printStatus();
    std::cout << "=========================" << std::endl;
}

void Robot::printTrack() const
{
    std::cout << "\n机器人运动轨迹：" << std::endl;
    for (size_t i = 0; i < track.size(); ++i)
    {
        std::cout << "点位" << i << ": X=" << track[i].x << ", Y=" << track[i].y << std::endl;
    }
}
