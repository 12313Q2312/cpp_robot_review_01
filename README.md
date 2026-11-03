# C++ Robot Review 01

一个由 Robot、Battery 和左右 Motor 组合而成的离散运动模拟项目。记录位置、方向和运动轨迹，作为后续机器人软件的工程基础。

当前运动是在函数调用时直接更新坐标；没有真实电机通信、传感器、碰撞检测或 ROS2 集成。

## 工程入口

| 文件 | 用途 |
|---|---|
| [src/main.cpp](src/main.cpp) | 创建机器人，设置速度并执行示例运动 |
| [src/Robot.cpp](src/Robot.cpp) | 位置、朝向、电量消耗和轨迹记录 |
| [src/Battery.cpp](src/Battery.cpp) | 电量范围维护 |
| [src/Motor.cpp](src/Motor.cpp) | 转速状态 |
| [include/](include/) | 组件接口 |
| [CMakeLists.txt](CMakeLists.txt) | C++17 构建配置，目标名为 robot_run |
| [整理与验证记录](docs/hygiene-20261103.md) | 清理范围、实际验证及回滚说明 |

## 构建与运行

需要 CMake 3.16+ 以及支持 C++17 的编译器。

Linux / 单配置生成器：

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/robot_run
```

Windows / Visual Studio 多配置生成器：

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\robot_run.exe
```

MinGW 等单配置生成器的 Windows 输出通常为 build/robot_run.exe。程序末尾读取输入，交互运行时按回车结束。

原有 run.bat 仍保留；它会删除旧 build 并固定使用 MinGW。本次没有运行或修改该脚本，推荐使用上面的显式构建命令。

## 验证与边界

本轮实际验证见整理记录。仓库没有自动化测试套件，示例运行不能代替边界、控制稳定性或硬件验证。源码保留原始编码，没有批量转码。

后续方向包括传感器接口、障碍检测、控制器和 ROS2；这些仍是规划。任何架构或真实硬件接入应先定义接口和验收标准。
