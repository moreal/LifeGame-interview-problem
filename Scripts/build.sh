#!/bin/bash

g++ -I ./Header $(find ./Source/*.cc) -o run -std=c++11 $@