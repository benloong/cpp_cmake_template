#!/bin/bash
if test -d ./build
then
    echo 'build folder exists'
else 
    mkdir build
fi

cd build 
cmake -G Xcode ..
cmake --build . --config Debug
cd bin/Debug
./Test

cd ../../
cmake --build . --config Release
cd bin/Release
./Test

cd ../../../