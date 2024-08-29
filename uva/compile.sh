#!/bin/bash


if (g++ 408.cpp); then
    echo "compilou"
    if !(time ./a.out < in > out) then
        echo "AHAHA"
    fi
fi