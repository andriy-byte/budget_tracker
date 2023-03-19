#!/bin/bash

if [ -f "$PWD/bin/linux/budget_tracker" ];
then 
    "$PWD/bin/linux/budget_tracker"
else
    echo "executable file doesn't exist"
fi