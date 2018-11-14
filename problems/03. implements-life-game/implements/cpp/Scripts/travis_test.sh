#!/bin/bash

# build test
sh Scripts/build

# unit test
mkdir build
cd build
cmake ../Test/
make