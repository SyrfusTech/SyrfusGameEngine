@ECHO OFF

rmdir /s Builds
if not exist "Builds" mkdir Builds
cd Builds
cmake ..
cd ..