#!/bin/bash

if [ -f "$PWD/bin/linux/budget_tracker" ];
then 
    cd "$PWD/bin/linux/"
    "./budget_tracker"
else
    echo "executable file doesn't exist"
fi