# 32bit
export GOARCH=386
export CGO_ENABLED=1
go build -buildmode=c-shared -o convertPinyin.so convertPinyin.go
gcc -m32 -o ry ry.c convertPinyin.so
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./ry hello.ry
rm -f ry
rm -f convertPinyin.h
rm -f convertPinyin.so
export GOARCH=amd64


# # 64bit
# go build -buildmode=c-shared -o convertPinyin.so convertPinyin.go
# gcc -o ry ry.c convertPinyin.so
# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
# ./ry hello.ry
# rm -f ry
# rm -f convertPinyin.h
# rm -f convertPinyin.so