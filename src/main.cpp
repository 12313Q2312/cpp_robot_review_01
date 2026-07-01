#include "Robot.h"
#include <iostream>

int main()
{
    Robot robot("一号侦察机器人");

    robot.setSpeed(5);
    robot.printRobotStatus();

    robot.moveForward();
    robot.turnRight();
    robot.moveForward();
    robot.moveBackward();
    robot.turnLeft();

    robot.printRobotStatus();
    robot.printTrack();

	std::cout << "\n按下回车键退出程序..." << std::endl;
	std::cin.ignore();  // 忽略缓冲区残留换行
	std::cin.get();
    return 0;
}
