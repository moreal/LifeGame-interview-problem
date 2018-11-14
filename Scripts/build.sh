#!/bin/bash

g++ -std=c++17 -I ./Header `find ./Source/*.cc` -o run $@ >/dev/null