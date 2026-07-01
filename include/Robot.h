#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include <vector>
#include "Battery.h"
#include "Motor.h"

// 机器人朝向枚举
enum Direction
{
    North,
    South,
    East,
    West
};

// 坐标点位结构体
struct Point
{
    double x;
    double y;
};

class Robot
{
private:
    std::string name;
    double x;
    double y;
    Direction dir;
    double speed;
    Battery battery;
    Motor leftMotor;
    Motor rightMotor;
    std::vector<Point> track; // 运动轨迹
public:
    explicit Robot(std::string robotName);
    //设置速度
    void setSpeed(double sp);
	//前进
    void moveForward();
	//后退
    void moveBackward();
    //左转
    void turnLeft();
    //右转
    void turnRight();
    //打印机器人状态
    void printRobotStatus() const;
    //打印运动轨迹
    void printTrack() const;
};

#endif
