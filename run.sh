go build -buildmode=c-shared -o convertPinyin.so convertPinyin.go
gcc -o ry ry.c convertPinyin.so
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./ry hello.ry
rm -f ry
rm -f convertPinyin.h
rm -f convertPinyin.so