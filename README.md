# C++ Robot State Simulator

**用组合式 C++ 组件描述机器人，并用一段可复现动作序列观察状态变化。**

项目将 `Robot`、`Battery` 和左右 `Motor` 组合成一个机器人对象，记录二维位置、朝向、电量与运动轨迹。它提供一个小而清晰的状态模型，用于检查组件接口、动作顺序和状态更新之间的关系。

**C++17 · CMake**。运行示例后可核对 **最终位置 `(0, 5)`、朝北、电量 95%**，并在终端看到四个记录点。

[构建与运行](#构建与运行) · [动作与预期结果](#五步示例) · [类接口](#代码导航)

## 当前能力

| 组件 | 现有职责 |
|---|---|
| `Robot` | 前进、后退、四方向转向、状态输出与轨迹记录 |
| `Battery` | 充放电及剩余电量状态 |
| `Motor` | 转速状态、停止与状态输出 |
| `main.cpp` | 创建机器人并执行一段固定动作序列 |

当前 `speed` 直接决定一次移动调用的位移步长，没有时间步长或物理单位；电机 RPM 是状态变量，不参与差速运动学计算。该模型适用于离散状态实验，尚未包含传感器、碰撞检测、闭环控制或真实电机通信。

## 五步示例

示例以 `(0, 0)`、朝北开始，设置步长为 `5`：

| 动作 | 位置 | 朝向 |
|---|---|---|
| 前进 | `(0, 5)` | 北 |
| 右转 | `(0, 5)` | 东 |
| 前进 | `(5, 5)` | 东 |
| 后退 | `(0, 5)` | 东 |
| 左转 | `(0, 5)` | 北 |

最终应输出 **X=0、Y=5、朝北**。位置轨迹记录初始点及三次平移动作，转向动作更新朝向而不新增位置点。对应代码见 [src/main.cpp](src/main.cpp) 和 [src/Robot.cpp](src/Robot.cpp)。

## 构建与运行

需要 **CMake 3.16+** 和支持 **C++17** 的编译器；在仓库根目录运行。

### Linux / 单配置生成器

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/robot_run
```

### Windows / Visual Studio 生成器

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\robot_run.exe
```

使用 MSVC 时，先在 Visual Studio Developer PowerShell 中确认编译器可用。MinGW 的可执行文件通常为 `build/robot_run.exe`。程序末尾等待输入，必要时再按一次回车退出。

原有 [run.bat](run.bat) 固定使用 MinGW 并删除旧 build 目录；它是原环境的快捷脚本。首次运行建议使用上面的显式命令，便于观察每一步结果。

## 代码导航

| 入口 | 用途 |
|---|---|
| [include/Robot.h](include/Robot.h) | 机器人动作与状态接口 |
| [include/Battery.h](include/Battery.h) | 电量接口 |
| [include/Motor.h](include/Motor.h) | 电机状态接口 |
| [src/](src/) | 组件实现与运行示例 |
| [CMakeLists.txt](CMakeLists.txt) | 构建目标 `robot_run` |
| [验证记录](docs/hygiene-20261103.md) | 干净构建、示例输出、资产清理与恢复 |

## 验证与后续工作

Linux GCC 和 Windows MinGW 均已从源码完成构建，并运行五步示例核对最终坐标。当前验证以可运行示例为主。

下一步适合先为转向、位移、电量耗尽和输入边界建立断言测试；若要引入时间步长、控制器或硬件接口，应先确定模型契约和验收标准。
