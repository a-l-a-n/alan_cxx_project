#!/bin/bash

cd $(dirname "$0")"/.."

if [ ! -d "build" ]; then
    mkdir build
else
    rm -rf build/*
fi

cd build
cmake ..
make
