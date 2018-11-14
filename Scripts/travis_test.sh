#!/bin/bash

# build test
sh ./Scripts/build.sh

# unit test
mkdir build
cd build
cmake ../../Test/
makes