#!/bin/bash
if [ $1 == "32" ]
then
    # 32bit
    export GOARCH=386
    export CGO_ENABLED=1
    go build -buildmode=c-shared -o convertCode.so convertCode.go
    gcc -w -m32 -o ry ry.c convertCode.so
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
    ./ry hello.ry
    rm -f ry
    rm -f convertCode.h
    rm -f convertCode.so
    export GOARCH=amd64
elif [ $1 == "64" ]
then
    # 64bit
    go build -buildmode=c-shared -o convertCode.so convertCode.go
    gcc -w -o ry ry.c convertCode.so
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
    ./ry hello.ry
    rm -f ry
    rm -f convertCode.h
    rm -f convertCode.so
fi