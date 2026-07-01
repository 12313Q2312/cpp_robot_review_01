# C++ Robot Review 01

A simple C++ project for reviewing object-oriented programming and basic software engineering concepts.

## Project Description

This project simulates a simple robot with the following components:

- Robot
- Battery
- Left Motor
- Right Motor

The robot can move, turn, change speed, record its movement path, and display its current status.

This project is intended as a C++ review before learning more advanced robotics development with ROS2.

---

## Features

- Robot class
- Battery class
- Motor class
- Object composition
- Position tracking
- Path history using `std::vector`
- Status display
- Modular project structure
- CMake build system

---

## Project Structure

```
cpp_robot_review_01/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── Robot.h
│   ├── Motor.h
│   └── Battery.h
└── src/
    ├── main.cpp
    ├── Robot.cpp
    ├── Battery.cpp
    └── Motor.cpp
```

---

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run:

```bash
./cpp_robot_review_01
```

(On Windows, run the generated executable.)

---

## Concepts Practiced

- C++ Classes
- Constructors
- Encapsulation
- Composition
- Header / Source file separation
- std::vector
- References
- const
- Basic CMake

---

## Future Improvements

- Add sensors
- Add obstacle detection
- Add robot controller
- Support multiple robots
- Integrate with ROS2

## Learning Purpose

This project is the first practice project in my robotics learning journey.

The goal is not only to review C++, but also to build the habit of designing software for real robotic systems.

Future projects will gradually integrate:

- ROS2
- Linux
- STM32
- Sensors
- Motors
- Control Algorithms