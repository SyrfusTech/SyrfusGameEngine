@ECHO OFF

rmdir /s build
if not exist "build" mkdir build
cd build
cmake ..
cd ..