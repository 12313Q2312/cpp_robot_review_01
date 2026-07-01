cmake_minimum_required(VERSION 3.16)
project(cpp_robot_review_01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 全部源文件必须全部写上
set(SRC_FILES
    src/main.cpp
    src/Battery.cpp
    src/Motor.cpp
    src/Robot.cpp
)

add_executable(robot_run ${SRC_FILES})
