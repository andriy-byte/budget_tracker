#!/bin/bash

if [ -f "$PWD/build/linux/x64" ];
then
    cmake --build "$PWD/build/linux/x64"
else
    cmake -B "$PWD/build/linux/x64" -S "$PWD"

    cmake --build "$PWD/build/linux/x64"

fi