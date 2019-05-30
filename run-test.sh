#!/bin/bash
if test -d ./build
then
    echo 'build folder exists'
else 
    mkdir build
fi

cd build 
cmake -G Xcode ..
cmake --build .
cd build/Debug
./Test

cd ../../../