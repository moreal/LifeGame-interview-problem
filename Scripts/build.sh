#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd "$DIR"

g++ -std=c++17 -I ./Header `find ./Source/*.cc` -o run $@ >/dev/null