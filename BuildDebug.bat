@ECHO OFF

if not exist "Builds" mkdir Builds
cd Builds
cmake ..
cmake --build . --config Debug
cd ..