@echo off
:: 删除旧构建文件夹
if exist build rd /s /q build
:: 新建编译目录
mkdir build
cd build
:: cmake构建
cmake -G "MinGW Makefiles" ..
:: 编译
mingw32-make
:: 运行程序
robot_run.exe
:: 运行完暂停
pause
