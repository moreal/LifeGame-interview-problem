#!/bin/bash

g++ -std=c++11 -I ./Header `find ./Source/*.cc` -o run $@