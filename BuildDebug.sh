#!/bin/bash

mkdir -p Builds
cd Builds
cmake ..
cmake --build . --config Debug
cd ..