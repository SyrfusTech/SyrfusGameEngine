@ECHO OFF

if not exist "Builds" mkdir Builds
cd Builds
cmake ..
cd ..