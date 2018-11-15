#!/bin/bash

# build test
sh ./Scripts/build.sh -std=c++11

# unit test
mkdir build
cd build
cmake ../Test/
make
./LifeGameTest